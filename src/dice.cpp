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

void Dice::setVal(int v){
    val = v;
}

void Dice::hold(){
    held = !held;
}

bool Dice::isHeld(){
    return held;
}

std::ostream & operator<<(std::ostream & out, const Dice & d){
    if(d.held)
        out << "|- "<<d.val<<" -|";
    else
        out << "| "<<d.val<<" |";
    return out;
}