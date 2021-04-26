#include "player.hpp"

Player::Player(): score(0){
    srand(time(NULL));
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

bool Player::itsHeld(int pos){
    return dice[pos].first.isHeld();
}

int Player::getScore(){
    return score;
}

void Player::setScore(){
    score += calcScore();
}

void Player::printAll(){
    for(int i = 0; i<6; i++){
        std::cout<<dice[i].first;
    }
    std::cout<<std::endl;
}

void Player::resetDice(){
    for(int i = 0; i<6; i++)
        dice[i].second = 0;
}

int Player::calcScore(){
    int s = 0;
    std::vector<int> nums;
    for(int i = 1; i<=3; i++){
        nums.clear();
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
    if(v.size()<6){
        return 0;
    }
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
    if(v.size()<6){
        return 0;
    }
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
    if(v.size()<6){
        return 0;
    }
    if(v.at(0) == v.at(1) && v.at(2)==v.at(3)&&v.at(4)==v.at(5)){
        while(v.size()>0)
            v.pop_back();
        return 1000;
    }
    else return 0;
}
int Player::fiveEq(std::vector<int> &v){
    if(v.size()<5){
        return 0;
    }
    for(int i = 0; i<v.size()-4; i++){
        if(v.at(i)==v.at(i+4)){
            int t = v.at(1);
            if(v.at(0)==v.at(4)){
                for(int j = 0; j<5; j++){
                    rm(0, v);
                }
            }
            else{
                for(int j = 0; j<5; j++)
                    v.pop_back();
            }
            if(t == 1){
                return 1000*4;
            }
            else return t*100*4;
        }
    }
    return 0;
}
int Player::fiveStraight(std::vector<int> &v){
    if(v.size()<5){
        return 0;
    }
    int dupe = rmDupe(v);
    if(v.size()==5){
        if(v.at(0)== v.at(1)-1&&v.at(2)==v.at(3)-1&&v.at(4)-1==v.at(3)){
            v.clear();
            if(dupe != -1){
                v.push_back(dupe);
            }
            return 500;
        }
    }
    if(dupe != -1){
        v.push_back(dupe);
        sort(v);
    }
    return 0;

}
int Player::fourEq(std::vector<int> &v){
    if(v.size()<4){
        return 0;
    }
    for(int i = 0; i<v.size()-3; i++){
        if(v.at(i)== v.at(i+3)){
            int t = v.at(i);
            for(int j = 0; j<4; j++)
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
    if(v.size()<3){
        return 0;
    }
    for(int i = 0; i<v.size()-2; i++){
        if(v.at(i)== v.at(i+2)){
            int t = v.at(i);
            for(int j = 0; j<3; j++)
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
    // while(v.size()>0){
        if(v.at(0)==1){
            rm(0, v);
            return 100;
        }
        else if(v.at(0)==5){
            rm(0, v);
            return 50;
        }
        else rm(0, v);
    // }
    return 0;
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

void Player::rm(int index, std::vector<int> &v){
    if(v.size() == 0)
        return;
    if(v.size() == 1)
        v.pop_back();
    else{
        int temp = v.at(v.size()-1);
        v.at(v.size()-1) = v.at(index);
        v.at(index) = temp;
        v.pop_back();
    }
}
int Player::rmDupe(std::vector<int> &v){
    for(int i = 0; i<v.size()-2; i++){
        if(v.at(i)==v.at(i+1)){
            int o = v.at(i);
            rm(i, v);
            sort(v);
            return o;
        }
    }
    return -1;
}