#include "timeblock.h"

TimeBlock::TimeBlock()
{
}

TimeBlock::TimeBlock(int x1, int x2):
    x1{x1}, x2{x2}, length{x2-x1+1}
{
}

std::vector<TimeBlock> TimeBlock::find_available_blocks(std::vector<TimeBlock> timeblocks)
{
    std::vector bits;
    for (int i=0; i<=this->length; ++i){
        bits.push_back(1);
    }

    for(const &timeblock: timeblocks){
        for (int i=tyimeblock.x1; i<=timeblock.x2; ++i) {
            if (timebloc.x1==v.first)
        }
    }

}

