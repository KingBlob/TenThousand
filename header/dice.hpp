#ifndef DICE_HPP
#define DICE_HPP

#include <stdlib.h>
#include <time.h>
class Dice{
    private:
        int val;
        bool held;
    public:
        Dice();
        void roll();
        int getVal();
        void hold();
};
#endif /* DICE_HPP */