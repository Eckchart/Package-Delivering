#include "courier.h"


Courier::Courier(const std::string &_name, const std::vector<int> &_streets, const Zone &_zone)
{
    this->name = _name;
    for (const auto street : _streets)
    {
        this->streets.emplace(street);
    }
    this->zone = _zone;
}


std::string Courier::get_name() const
{
    return this->name;
}


std::unordered_set<int>& Courier::get_streets()
{
    return this->streets;
}


Zone Courier::get_zone() const
{
    return this->zone;
}
