#include "dice.hpp"

Dice::Dice() : held(0) {
    val = rand() %6 +1;
}

void Dice::roll(){
    val = rand()%6 +1;
}

int Dice::getVal(){
    return val;
}

void Dice::hold(){
    held = !held;
}

bool Dice::isHeld(){
    return held;
}

std::ostream & operator<<(std::ostream & out, const Dice & d){
    out << "| "<<d.val<<" |";
    return out;
}