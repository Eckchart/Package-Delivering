#include "package.h"


Package::Package(const std::string &_recipient, const Address &_address, const Location &_location, const bool _deliv_status)
    : recipient{_recipient}, address{_address}, location{_location}, deliv_status{_deliv_status} {}


std::string Package::get_recipient() const
{
    return this->recipient;
}


Address Package::get_address() const
{
    return this->address;
}


Location Package::get_location() const
{
    return this->location;
}


bool Package::get_deliv_status() const
{
    return this->deliv_status;
}


void Package::set_deliv_status()
{
    this->deliv_status = true;
}
