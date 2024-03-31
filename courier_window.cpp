    #include "courier_window.h"
#include "ui_courier_window.h"
#include <QString>
#include <string>
#include <QPushButton>


courier_window::courier_window(Session &_sess, const Courier _courier, QWidget *parent)
    :
    QWidget(parent),
    ui(new Ui::courier_window),
    sess{_sess},
    cur_courier{_courier}
{
    this->ui->setupUi(this);
    this->setWindowTitle(QString::fromStdString(cur_courier.get_name()));
    std::string zone_text = "Center: (" + std::to_string(cur_courier.get_zone().xc) + ", "
                            + std::to_string(cur_courier.get_zone().yc) + "), Radius: "
                            + std::to_string(cur_courier.get_zone().r);
    this->ui->zoneLineEdit->setText(QString::fromStdString(zone_text));
    this->populateComboBox();
    this->populatePackagesList();

    QObject::connect(this->ui->deliverPushButton, &QPushButton::clicked, this, [&]()
    {
        const auto selected_package = this->ui->packagesListWidget->selectedItems().at(0)->text().toStdString();
        auto pos1 = selected_package.find(':');
        pos1 += 2;
        std::string cur_street;
        for ( ; selected_package[pos1] != ','; ++pos1)
        {
            cur_street.push_back(selected_package[pos1]);
        }
        std::string cur_number;
        for (++pos1; selected_package[pos1] != ';'; ++pos1)
        {
            cur_number.push_back(selected_package[pos1]);
        }
        this->sess.deliver(std::stoi(cur_street), std::stoi(cur_number));
    });

    QObject::connect(this->ui->streetsComboBox, &QComboBox::textActivated, this, [&]()
    {
        this->populatePackagesList();
    });
}


int courier_window::get_sq_dist(int xa, int ya, int xb, int yb)
{
    return (xa - xb) * (xa - xb) + (ya - yb) * (ya - yb);
}


void courier_window::populatePackagesList()
{
    this->ui->packagesListWidget->clear();
    for (const auto &package : this->sess.get_packages())
    {
        if (!cur_courier.get_streets().count(package.get_address().street)
            && !(this->get_sq_dist(cur_courier.get_zone().xc, cur_courier.get_zone().yc,
            package.get_location().x, package.get_location().y) <= cur_courier.get_zone().r * cur_courier.get_zone().r))
        {
            continue;
        }
        if (package.get_deliv_status())
        {
            continue;
        }
        if (package.get_address().street != this->ui->streetsComboBox->currentText().toInt())
        {
            continue;
        }
        const std::string item_text = package.get_recipient() + "; address: " + std::to_string(package.get_address().street) + ", "
                                      + std::to_string(package.get_address().number) + "; location: (" + std::to_string(package.get_location().x) + ", "
                                      + std::to_string(package.get_location().y) + "); " + (package.get_deliv_status() ? "true" : "false");
        this->ui->packagesListWidget->addItem(QString::fromStdString(item_text));
    }
}


void courier_window::populateComboBox()
{
    this->ui->streetsComboBox->clear();
    std::vector<int> uniq_streets;
    for (const auto &package : this->sess.get_packages())
    {
        uniq_streets.emplace_back(package.get_address().street);
    }
    std::sort(begin(uniq_streets), end(uniq_streets));
    uniq_streets.erase(unique(begin(uniq_streets), end(uniq_streets)), end(uniq_streets));
    for (const int street : uniq_streets)
    {
        this->ui->streetsComboBox->addItem(QString::number(street));
    }
}


void courier_window::update()
{
    this->populatePackagesList();
    this->populateComboBox();
}


courier_window::~courier_window()
{
    delete ui;
}
