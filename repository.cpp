#include "repository.h"
#include <fstream>
#include <iostream>


Repository::Repository(const std::string &_packages_filename, const std::string &_couriers_filename)
                : packages_filename{_packages_filename}, couriers_filename{_couriers_filename}
{
    this->read_from_file();
}


void Repository::read_from_file()
{
    // read couriers
    std::ifstream fin(this->couriers_filename);
    int nr_couriers;
    fin >> nr_couriers;
    while (nr_couriers--)
    {
        std::string name;
        fin >> name;
        std::vector<int> assigned_streets;
        int nr_assigned_streets;
        fin >> nr_assigned_streets;
        while (nr_assigned_streets--)
        {
            int street;
            fin >> street;
            assigned_streets.emplace_back(street);
        }
        Zone zone;
        fin >> zone.xc >> zone.yc >> zone.r;
        this->couriers.emplace_back(name, assigned_streets, zone);
    }
    fin.close();

    // read packages
    fin.open(this->packages_filename);
    int nr_packages;
    fin >> nr_packages;
    while (nr_packages--)
    {
        std::string recipient;
        fin >> recipient;
        Address address;
        fin >> address.street >> address.number;
        Location loc;
        fin >> loc.x >> loc.y;
        std::string deliv_status;
        fin >> deliv_status;
        this->packages.emplace_back(recipient, address, loc, deliv_status == "true" ? true : false);
    }
}


void Repository::save_to_file()
{
    std::ofstream fout(this->packages_filename);
    fout << this->packages.size() << "\n";
    for (const auto &package : packages)
    {
        fout << "\n";
        fout << package.get_recipient() << "\n";
        fout << package.get_address().street << " " << package.get_address().number << "\n";
        fout << package.get_location().x << " " << package.get_location().y << "\n";
        fout << std::boolalpha << package.get_deliv_status() << "\n";
    }
}


std::vector<Package>& Repository::get_packages()
{
    return this->packages;
}


std::vector<Courier> Repository::get_couriers() const
{
    return this->couriers;
}


void Repository::add_package(const std::string &recipient, const Address &address, const Location &location, const bool deliv_status)
{
    Package package(recipient, address, location, deliv_status);
    this->packages.emplace_back(package);
}


Repository::~Repository()
{
    this->save_to_file();
}
