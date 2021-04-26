#ifndef DICE_HPP
#define DICE_HPP

#include <stdlib.h>
#include <time.h>
class Dice{
    private:
        int val;
    public:
        Dice();
        void roll();
        int getVal();
};
#endif /* DICE_HPP */