#include "Manager.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace GameLife {
  Manager::Manager(int r, int c) 
  {
    row = r; col = c;
    room = std::vector<Room>(row*col);
  }
  void Manager::moveIn()
  {
    std::srand(time(NULL));
    for (int i=0; i<row*col; ++i){
      if (std::rand() % 2) room[i].setCurrent(Room::FULL);
      else room[i].setCurrent(Room::EMPTY);
     
      room[i].setNeighbor(getUp(i),getDown(i),getRight(i),getLeft(i),getUL(i),getUR(i),getDL(i),getDR(i));
    }
  }
  void Manager::visitNeighborLiveOrDie()
  {
    for (int i=0; i<row*col; ++i){
      int mfriend = 0;
      if (room[i].getUp() != -1 && room[room[i].getUp()].getCurrent() == Room::FULL) ++mfriend;
      if (room[i].getDown() != -1 && room[room[i].getDown()].getCurrent() == Room::FULL) ++mfriend;
      if (room[i].getLeft() != -1 && room[room[i].getLeft()].getCurrent() == Room::FULL) ++mfriend;
      if (room[i].getRight() != -1 && room[room[i].getRight()].getCurrent() == Room::FULL) ++mfriend;
      if (room[i].getUpLeft() != -1 && room[room[i].getUpLeft()].getCurrent() == Room::FULL) ++mfriend;
      if (room[i].getUpRight() != -1 && room[room[i].getUpRight()].getCurrent() == Room::FULL) ++mfriend;
      if (room[i].getDownLeft() != -1 && room[room[i].getDownLeft()].getCurrent() == Room::FULL) ++mfriend;
      if (room[i].getDownRight() != -1 && room[room[i].getDownRight()].getCurrent() == Room::FULL) ++mfriend;
      
      if (room[i].getCurrent() == Room::FULL){
	if (mfriend < 2) room[i].setFuture(Room::EMPTY); //lonely
	else if ( mfriend > 3) room[i].setFuture(Room::EMPTY); //over population
	else room[i].setFuture(Room::FULL);
      }
      else if (room[i].getCurrent() == Room::EMPTY) {
	if (mfriend == 3) room[i].setFuture(Room::FULL); //spawn
	else room[i].setFuture(Room::EMPTY); // nothing happen
      }
    }
  }
  void Manager::updateCurrentRoom()
  {
    for (int i=0; i<row*col; ++i){
      room[i].setCurrent(room[i].getFuture());
    }
  }
  void Manager::printRoom()
  {
    for (int i=0; i<row*col; ++i){
      if (i%col == 0) std::cout << std::endl;
      if (room[i].getCurrent() == Room::FULL) std::cout << "*";
      else std::cout << "-";
    }
    std::cout << std::endl;
  }
  int Manager::getUp(int roomID)
  {
    return ((roomID-col) >=0)? roomID-col: -1;
  }
  int Manager::getDown(int roomID)
  {
    return ((roomID+col)< (row*col)) ? roomID+col: -1;
  }
  int Manager::getRight(int roomID)
  {
    return ((roomID%col) != (col-1)) ? roomID+1: -1;
  }
  int Manager::getLeft(int roomID)
  {
    return ((roomID%col) != 0) ? roomID-1: -1;
  }
  int Manager::getUL(int roomID)
  {
    return getUp(roomID)>0? getLeft(getUp(roomID)): -1;
  }
  int Manager::getUR(int roomID)
  {
    return getUp(roomID)>0? getRight(getUp(roomID)): -1;
  }
  int Manager::getDL(int roomID)
  {
    return getDown(roomID)>0? getLeft(getDown(roomID)): -1;
  }
  int Manager::getDR(int roomID)
  {
    return getDown(roomID)>0? getRight(getDown(roomID)): -1;
  }
}

