#ifndef DICE_HPP
#define DICE_HPP

#include <stdlib.h>
#include <time.h>
#include <iostream>
class Dice{
    private:
        int val;
        bool held;
    public:
        Dice();
        void roll();
        int getVal();
        void hold();
        bool isHeld();
        friend std::ostream &operator<<(std::ostream &, const Dice &);

};
#endif /* DICE_HPP */