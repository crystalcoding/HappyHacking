#include "bball.h"
#include <QApplication>
#include <vector>
#include "division.h"
#include "team.h"
#include "utils.h"

int main(int argc, char *argv[])
{
    std::vector<Team> teams;
    teams.push_back(Team(1, "Apple"));
    teams.push_back(Team(2, "Berry"));
    teams.push_back(Team(3, "Clementine"));
    teams.push_back(Team(4, "Dandelion"));
    teams.push_back(Team(5, "Egg"));
    teams.push_back(Team(6, "Fish"));
    teams.push_back(Team(7, "Grape"));
    teams.push_back(Team(8, "Habonero"));
    teams.push_back(Team(9, "Ice cream"));
    teams.push_back(Team(10, "Juice"));
    print_container(teams);
    Division d(teams);

    QApplication a(argc, argv);
    bball w;
    w.show();

    return a.exec();
}
