#include "subject.h"
#include <iostream>


void Subject::add_observer(const std::shared_ptr<Observer> &obs)
{
    this->observers.emplace_back(obs);
}


void Subject::notify()
{
    for (const auto &obs : this->observers)
    {
        obs->update();
    }
}
