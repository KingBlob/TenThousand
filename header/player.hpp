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
        bool itsHeld(int pos);
        bool allHeld();
        int getScore();
        void setScore(int);
        void printAll();
        int calcRollScore(int turn);
        void resetDice();
        int calcScore();
    private:
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
        void sort(std::pair<Dice, int>*);
        void rm(int, std::vector<int> &);
        int rmDupe(std::vector<int> &);
};
#endif