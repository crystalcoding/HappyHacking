#ifndef TIMEBLOCK_H
#define TIMEBLOCK_H

#include <vector>
#include <pair>
#include <string>


class TimeBlock
{
    int start_time;
    int end_time;
    int x1, x2;
    int length;
public:
    TimeBlock();
    TimeBlock(int x1, int x2);
    stds::vector<TimeBlock> find_available_blocks(std::vector<TimeBlock> timeblocks);

};

#endif // TIMEBLOCK_H
