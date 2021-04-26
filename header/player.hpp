#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "dice.hpp"
#include <utility>
#include <vector>
class Player{
    private:
        std::pair<Dice, int>* dice;
        int score;
    public:
        Player();
        void roll(int turn);
        void hold(int pos);
        int getScore();
        void setScore();
    private:
        void resetDice();
        int calcScore();
        /* SCORING CONDITIONS */
        int allEq(std::vector<int> &);
        int straight(std::vector<int> &);
        int threePairs(std::vector<int> &);
        int fiveEq(std::vector<int> &);
        int fiveStraight(std::vector<int> &);
        int fourEq(std::vector<int> &);
        int threeEq(std::vector<int> &);
        int oneOrFive(std::vector<int> &);
        /* Sorting Algorithm */
        void sort(std::vector<int> &);
        void rm(int, std::vector<int> &);
};
#endif