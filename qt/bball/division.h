#ifndef DIVISION_H
#define DIVISION_H

#include <vector>
#include "round.h"
#include "team.h"

class Division
{
public:
    Division();
    Division(std::vector<Team> division_teams)
    {
        for (auto team: division_teams) {
            teams.push_back(team);
        }
    }

    std::vector<Round> generate_rounds();
    std::vector<Team> teams;
};

#endif // DIVISION_H
