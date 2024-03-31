#pragma once
#include "package.h"
#include "courier.h"
#include <vector>
#include <string>


class Repository
{
private:
    std::vector<Package> packages;
    std::vector<Courier> couriers;
    std::string packages_filename;
    std::string couriers_filename;

    void read_from_file();

    void save_to_file();

public:
    Repository(const std::string&, const std::string&);

    std::vector<Package>& get_packages();

    std::vector<Courier> get_couriers() const;

    void add_package(const std::string&, const Address&, const Location&, const bool);

    ~Repository();
};
