#include "dice.hpp"

Dice::Dice() :held(0) { roll();}

void Dice::roll(){
    srand(time(0));
    val = rand()%6 +1;
}

int Dice::getVal(){
    return val;
}

void Dice::hold(){
    held = !held;
}