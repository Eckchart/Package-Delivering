#pragma once
#include <string>
#include <vector>
#include <unordered_set>


struct Zone
{
    int xc, yc, r;
};


class Courier
{
private:
    std::string name;
    std::unordered_set<int> streets;
    Zone zone;

public:
    Courier(const std::string&, const std::vector<int>&, const Zone&);

    std::string get_name() const;

    std::unordered_set<int>& get_streets();

    Zone get_zone() const;
};
