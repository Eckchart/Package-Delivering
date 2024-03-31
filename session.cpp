#include "session.h"


Session::Session(Repository &_repo) : repo{_repo} {}


void Session::deliver(const int street, const int number)
{
    for (auto &package : this->repo.get_packages())
    {
        if (package.get_address().street == street && package.get_address().number == number)
        {
            package.set_deliv_status();
            break;
        }
    }
    this->notify();
}


void Session::add_package(const std::string &recipient, int street, int street_nr, int x, int y)
{
    this->repo.add_package(recipient, Address(street, street_nr), Location(x, y), false);
    this->notify();
}


std::vector<Package>& Session::get_packages()
{
    return this->repo.get_packages();
}
