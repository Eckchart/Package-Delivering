#pragma once
#include "subject.h"
#include "repository.h"


class Session : public Subject
{
private:
    Repository &repo;

public:
    Session(Repository&);

    std::vector<Package>& get_packages();

    void deliver(const int street, const int number);

    void add_package(const std::string&, int, int, int, int);
};
