#ifndef MANAGER_H
#define MANAGER_H

#include "Room.h"
#include <vector>

namespace GameLife {
  class Manager {
  public:
    Manager(int row, int col);
    void moveIn();
    void visitNeighborLiveOrDie();
    void updateCurrentRoom();
    void printRoom();
    int getUp(int roomID);
    int getDown(int roomID);
    int getRight(int roomID);
    int getLeft(int roomID);
    int getUL(int roomID);
    int getUR(int roomID);
    int getDL(int roomID);
    int getDR(int roomID);
  private:
    int row, col;
    std::vector<Room> room;
  };
}

#endif
