#ifndef UTILS_H
#define UTILS_H

#include <QDebug>
#include <iostream>

std::ostream& operator<<(std::ostream& os, Team const& team)
{
    os << team.id << team.name;
    return os;
}

template <typename T>
void print_container(T const& container)
{
    for (auto elem : container) {
        std::cout << elem << std::endl;
    }
}

#endif // UTILS_H
