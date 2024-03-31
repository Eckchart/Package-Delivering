#include "courier_company_window.h"
#include "ui_courier_company_window.h"


courier_company_window::courier_company_window(Session &_sess, QWidget *parent)
    :
    QWidget(parent),
    ui(new Ui::courier_company_window),
    sess{_sess}
{
    this->ui->setupUi(this);
    this->populatePackagesList();

    QObject::connect(this->ui->addPushButton, &QPushButton::clicked, this, [&]()
    {
        auto recipient = this->ui->recipientLineEdit->text().toStdString();
        auto street = this->ui->streetLineEdit->text().toInt();
        auto street_nr = this->ui->streetNrLineEdit->text().toInt();
        auto xLoc = this->ui->xLocLineEdit->text().toInt();
        auto yLoc = this->ui->yLocLineEdit->text().toInt();
        this->sess.add_package(recipient, street, street_nr, xLoc, yLoc);
    });
}


void courier_company_window::populatePackagesList()
{
    this->ui->packagesListWidget->clear();
    for (const auto &package : this->sess.get_packages())
    {
        const std::string item_text = package.get_recipient() + "; address: " + std::to_string(package.get_address().street) + ", "
                                      + std::to_string(package.get_address().number) + "; location: (" + std::to_string(package.get_location().x) + ", "
                                      + std::to_string(package.get_location().y) + "); " + (package.get_deliv_status() ? "true" : "false");
        auto cur_item = new QListWidgetItem(QString::fromStdString(item_text));
        if (package.get_deliv_status())
        {
            cur_item->setBackground(Qt::green);
        }
        this->ui->packagesListWidget->addItem(cur_item);
    }
}


void courier_company_window::update()
{
    this->populatePackagesList();
}


courier_company_window::~courier_company_window()
{
    delete ui;
}
