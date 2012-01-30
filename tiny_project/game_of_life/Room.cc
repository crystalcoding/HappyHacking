#include "Room.h"
namespace GameLife {
  Room::Room() {roomID = up = down = right = left  = -1;}
  void Room::setRoomID(int id)
  {
    roomID = id;
  }
  void Room::setNeighbor(int u, int d, int r, int l
			 ,int ul, int ur, int dl, int dr)
  {
    up = u; down = d; right = r; left = l;
    upLeft = ul; upRight = ur;
    downLeft = dl; downRight = dr;
  }
  void Room::setCurrent(populate p)
  {
    current = p;
  }
  void Room::setFuture(populate f)
  {
    future = f;
  }
  Room::populate Room::getCurrent()
  {
    return current;
  }
}


