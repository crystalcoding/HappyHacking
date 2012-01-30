#include <iostream>
#include "Manager.h"
#include "Room.h"
using namespace std;
using namespace GameLife;
int main()
{
  Manager manager(9,9);
  manager.moveIn();
  manager.printRoom();
  while (true){
    manager.visitNeighborLiveOrDie();
    manager.updateCurrentRoom();
    cout << "==========" << endl;
    manager.printRoom();
  }
}
