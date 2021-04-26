#include "dice.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;

int main(){
    Player one;
    cout<<"Ready to play? Commands are: r- roll dice, h- hold die, q- quit game."<<endl;
    string ans = "";
    int holds = -1;
    int turn = 1;
    while (ans != "q"){
        if(turn == 4){
            one.setScore();
            cout<<"Current score is "<<one.getScore()<<endl;
            for(int a = 0; a<6; a++){
                if(one.itsHeld(a)){
                    one.hold(a);
                }
            }
            turn =1;
        }
        cout<<"Enter command: ";
        cin>> ans;
        if(ans == "r"){
            cout<<"\nRolling!"<<endl;
            one.roll(turn);
            one.printAll();
            turn++;
        }
        else if(ans == "h"){
            while(1){
                cout<<"Enter dice numbers to hold (-1 to finish)"<<endl;
                cin >>holds;
                if(holds==-1)
                    break;
                one.hold(holds-1);
                cout<<"Die "<<holds<<" held toggled."<<endl;
            }
        }
    }
    return 0;
}