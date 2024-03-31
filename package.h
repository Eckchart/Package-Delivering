#pragma once
#include <string>


struct Address
{
    int street, number;

    Address() {}
    Address(int _street, int _number) : street{_street}, number{_number} {}
};


struct Location
{
    int x, y;

    Location() {}
    Location(int _x, int _y) : x{_x}, y{_y} {}
};


class Package
{
private:
    std::string recipient;
    Address address;
    Location location;
    bool deliv_status;

public:
    Package(const std::string&, const Address&, const Location&, const bool);

    std::string get_recipient() const;

    Address get_address() const;

    Location get_location() const;

    bool get_deliv_status() const;

    void set_deliv_status();
};
