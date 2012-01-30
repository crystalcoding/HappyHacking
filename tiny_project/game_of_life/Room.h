#ifndef ROOM_H
#define ROOM_H
namespace GameLife {
  class Room {
  public:
    Room();
    enum populate { EMPTY, FULL };

    void setRoomID(int id);
    void setNeighbor(int up, int down, int right, int left,
              int upleft, int upright, int downleft, int downright);
    void setCurrent(populate p);
    void setFuture(populate f);
    populate getCurrent();//implt(learning)
    populate getFuture() {return future;}
    int getUp() {return up;}
    int getDown() {return down;}
    int getRight() {return right;}
    int getLeft() {return left;}
    int getUpLeft() {return upLeft;}
    int getUpRight(){return upRight;}
    int getDownLeft(){return downLeft;}
    int getDownRight(){return downRight;}
  private:
    int roomID;
    int up, down, right, left;
    int upLeft, upRight, downLeft, downRight;
    populate current, future; //currently, future, EMPYT, or FULL
  };
}


#endif
