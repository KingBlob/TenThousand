#include "dice.hpp"

Dice::Dice() { roll();}

void Dice::roll(){
    srand(time(0));
    val = rand()%6 +1;
}

int Dice::getVal(){
    return val;
}