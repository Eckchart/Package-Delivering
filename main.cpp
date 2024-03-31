#include "courier_window.h"
#include "repository.h"
#include "courier_company_window.h"
#include <QApplication>
#include <memory>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo(R"(C:\Users\Robert\Desktop\qt creaaaator\PRACTICE_OBSERVER_1\packages.txt)",
                    R"(C:\Users\Robert\Desktop\qt creaaaator\PRACTICE_OBSERVER_1\couriers.txt)");
    Session sess(repo);
    const auto couriers = repo.get_couriers();
    for (const auto &courier : couriers)
    {
        const auto cur_window = std::make_shared<courier_window>(sess, courier);
        sess.add_observer(cur_window);
        cur_window->show();
    }
    const auto company_window = std::make_shared<courier_company_window>(sess);
    sess.add_observer(company_window);
    company_window->show();
    return a.exec();
}
