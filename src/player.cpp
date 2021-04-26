#include "player.hpp"

Player::Player(): score(0){
    dice = new std::pair<Dice, int>[6];
    for(int i = 0; i<6; i++){
        dice[i].second = 0;
    }
}

void Player::roll(int turn){
    for(int i = 0; i<6; i++){
        if(!dice[i].first.isHeld()){
            dice[i].first.roll();
            dice[i].second = turn;
        }
    }
}

void Player::hold(int pos){
    dice[pos].first.hold();
}

int Player::getScore(){
    return score;
}

void Player::setScore(){
    score += calcScore();
}

void Player::resetDice(){
    for(int i = 0; i<6; i++)
        dice[i].second = 0;
}

int Player::calcScore(){
    int s = 0;
    for(int i = 1; i<=3; i++){
        std::vector<int> nums;
        for(int j = 0; j<6; j++){
            if(dice[j].second == i)
                nums.push_back(dice[j].first.getVal());
        }
        sort(nums);
        /*
            6 dice conditions
            all =
            1 2 3 4 5 6
            2 = x3

            5 dice conditions
            5/6 =
            1 2 3 4 5 || 2 3 4 5 6

            4 dice conditions
            4/6 =

            3 dice conditions
            3/6 =

            2 dice conditions
            1 || 5 x2

            1 die conditions
            1 || 5

            */
        if(nums.size() > 2){
            s += allEq(nums);
            s += straight(nums);
            s += threePairs(nums);

            s += fiveEq(nums);
            s += fiveStraight(nums);

            s += fourEq(nums);

            s += threeEq(nums);
        }
        while(nums.size() > 0){
            s+= threeEq(nums);
            s+=oneOrFive(nums);
        }
    }
    return s;
}

int Player::allEq(std::vector<int> &v){
    if(v.at(0) == v.at(5)){
        int t = v.at(0);
        while(v.size()>0)
            v.pop_back();
        if(t == 1){
            return 8000;
        }
        else return t*100*8;
    }
    else return 0;
}
int Player::straight(std::vector<int> &v){
    if(v.at(0)==1&&
    v.at(1)==2&&
    v.at(2)==3&&
    v.at(3)==4&&
    v.at(4)==5&&
    v.at(5)==6){
        while(v.size()>0)
            v.pop_back();
        return 1000;
    }
    else return 0;
}
int Player::threePairs(std::vector<int> &v){
    if(v.at(0) == v.at(1) && v.at(2)==v.at(3)&&v.at(4)==v.at(5)){
        while(v.size()>0)
            v.pop_back();
        return 1000;
    }
    else return 0;
}
int Player::fiveEq(std::vector<int> &v){
    if((v.at(0)==v.at(4))||(v.at(1)==v.at(5))){
        int t = v.at(1);
        if(v.at(0)==v.at(4)){
            while(v.size() > 1){
                rm(0, v);
            }
        }
        else{
            while(v.size()>1)
                v.pop_back();
        }
        if(t == 1){
            return 1000*4;
        }
        else return t*100*4;
    }
    else return 0;
}
int Player::fiveStraight(std::vector<int> &v){
    if(v.at(1)==2&&
    v.at(2)==3&&
    v.at(3)==4&&
    v.at(4)==5&&
    (v.at(0)==1 ||v.at(5)==6)){
        if(v.at(5)==6){
            while(v.size()>1)
                v.pop_back();
        }
        else{
            while(v.size()>1)
                rm(0,v);
        }
        return 500;
    }
    else return 0;
}
int Player::fourEq(std::vector<int> &v){
    for(int i = 0; i<3; i++){
        if(v.at(i)== v.at(i+3)){
            int t = v.at(i);
            while(v.size()>2)
                rm(i,v);
            sort(v);
            if(t == 1){
                return 1000*2;
            }
            else return t*100*2;
        }
    }
    return 0;
}
int Player::threeEq(std::vector<int> &v){
    for(int i = 0; i<4; i++){
        if(v.at(i)== v.at(i+2)){
            int t = v.at(i);
            while(v.size()>3)
                rm(i,v);
            sort(v);
            if(t == 1){
                return 1000;
            }
            else return t*100;
        }
    }
    return 0;
}
int Player::oneOrFive(std::vector<int> &v){
    int i = 0;
    while(v.size()>0){
        if(v.at(i)==1){
            rm(i, v);
            return 100;
        }
        else if(v.at(i)==5){
            rm(i, v);
            return 50;
        }
        else i++;
    }
}

void Player::sort(std::vector<int> &v){
    if(v.size() <= 1)
        return;
    for(int i = 0; i<v.size()-1; i++){
        for(int j = i+1; j<v.size(); j++){
            if(v.at(i) > v.at(j)){
                int temp = v.at(j);
                v.at(j) = v.at(i);
                v.at(i) = temp;
            }
        }
    }
}