using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace game_of_life
{
    public class DormManager
    {
        private int total_row;
        private int total_col;
        bool[,] status;

        public DormManager(int r, int c)
        {
            total_row = r;
            total_col = c;
            status = new bool[r,c];
        }

        public void SetRoomStatus(bool newStatus, int row, int col)
        {
            status[row,col] = newStatus;
        }

        public bool checkFutureStatus(bool roomCurrentStatus,int row, int col)
        {
            int totalNeighbor = 0;
                //up
                if (row - 1 >= 0) if (status[row - 1, col]) ++totalNeighbor;
                //down
                if (row + 1 < total_row) if (status[row + 1, col]) ++totalNeighbor;
                //left
                if (col - 1 >= 0) if (status[row, col - 1]) ++totalNeighbor;
                //right
                if (col + 1 < total_col) if (status[row, col + 1]) ++totalNeighbor;
                //upper left
                if (row - 1 >=0 && col - 1 >= 0) if (status[row - 1, col - 1]) ++totalNeighbor;
                //upper right
                if (row - 1 >=0 && col + 1 < total_row) if (status[row - 1, col + 1]) ++totalNeighbor;
                //lower left
                if (row + 1 <total_row && col - 1 >= 0) if (status[row + 1, col - 1]) ++totalNeighbor;
                //lower right
                if (row + 1 <total_row && col + 1 < total_col) if (status[row + 1, col + 1]) ++totalNeighbor;
                if (roomCurrentStatus)
                {
                    switch (totalNeighbor)
                    {
                        case 0:
                        case 1:
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                        case 8:
                            return false;
                        case 2:
                        case 3:
                            return true;
                        default:
                            return false;
                    }
                }
                else
                {
                    //born if this empty cell has total neighbor of 3
                    if (totalNeighbor == 3) return true;
                    else return false;
                }
        }
    }
}
