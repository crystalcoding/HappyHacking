#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <iostream>
#include <ostream>
class Team
{
public:
    Team();
    Team(int id, std::string name): id(id), name(name) {}
    int id;
    std::string name;
};

#endif // TEAM_H
