#include "dice.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

string menu();
void roll(int &, int &, Player &);
void hold(Player &);

int main(){
    string game = menu();
    if(game == "1"){
        Player one;
        int turn = 0;
        int tScore = 0;
        cout<<"Single player. Begin!"<<endl;
        while(one.getScore()<10000){
            if(one.allHeld()){
                tScore += one.calcScore();
                cout<<"All six dice used! Roll again!"<<endl;
                cout<<"Current turn's score: "<<tScore<<endl;
                turn = 0;
            }
            else{
                if(turn ==0)
                    roll(turn, tScore, one);
                else{
                    string answ = "";
                    cout<<"r - Roll\nh- Hold\ne - End turn"<<endl;
                    cin>>answ;
                    if(answ == "r"){
                        if(turn == 3){
                            cout<<"No rolls left, end turn."<<endl;
                        }
                        else
                            roll(turn, tScore, one);
                    }
                    else if(answ == "h"){
                        hold(one);
                    }
                    else{
                        tScore += one.calcScore();
                        one.setScore(tScore);
                        turn =0;
                        one.resetDice();
                        cout<<"Turn ended. Your score: "<<one.getScore()<<endl;
                    }
                }
                
            }

        }
    }


    // cout<<"Ready to play? Commands are: r- roll dice, h- hold die, q- quit game."<<endl;
    // string ans = "";
    // int holds = -1;
    // int turn = 1;
    // while (ans != "q"){
    //     if(turn == 4){
    //         one.setScore();
    //         cout<<"Current score is "<<one.getScore()<<endl;
    //         for(int a = 0; a<6; a++){
    //             if(one.itsHeld(a)){
    //                 one.hold(a);
    //             }
    //         }
    //         turn =1;
    //     }
    //     cout<<"Enter command: ";
    //     cin>> ans;
    //     if(ans == "r"){
    //         cout<<"\nRolling!"<<endl;
    //         one.roll(turn);
    //         one.printAll();
    //         turn++;
    //     }
    //     else if(ans == "h"){
    //         while(1){
    //             cout<<"Enter dice numbers to hold (-1 to finish)"<<endl;
    //             cin >>holds;
    //             if(holds==-1)
    //                 break;
    //             one.hold(holds-1);
    //             cout<<"Die "<<holds<<" held toggled."<<endl;
    //         }
    //     }
    // }
    return 0;
}

string menu(){
    string ans = "";
    cout<<"Main menu:\nsolo - new solo game\nversus - play against other players\ncomp - play against computer\nquit - exit game"<<endl;
    cin >>ans;
    if(ans == "solo"){
        return "1";
    }
    else if(ans == "versus"){
        //TODO
        return "q";
    }
    else if(ans == "comp"){
        //TODO
        return "q";
    }
    else return "q";
}
void roll(int &turn, int &tScore, Player &p){
    cout<<"Rolling..."<<endl;
    turn ++;
    p.roll(turn);
    p.printAll();
    if(p.calcRollScore(turn)==0){
        cout<<"Dead roll! Reset points."<<endl;
        turn = 0;
        tScore = 0;
        p.resetDice();
        return;
    }
    else{
        cout<<"Max roll score is "<<p.calcRollScore(turn)<<endl;
    }
}
void hold(Player &p){
    while(1){
        int holds = 0;
        p.printAll();
        cout<<"Enter dice numbers to hold (0 to finish)"<<endl;
        cin >>holds;
        if(holds==0)
            break;
        p.hold(holds-1);
        cout<<"Die "<<holds<<" held toggled."<<endl;
    }
}
