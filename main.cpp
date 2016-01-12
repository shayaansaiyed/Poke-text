//
//  main.cpp
//  pokemon-battle
//
//  Created by Shayaan Saiyed on 10/23/15.
//  Copyright (c) 2015 Shayaan Saiyed. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BattleMove{
public:
    BattleMove (const string& aName, int aPower) : name(aName), power(aPower) {};
    BattleMove () {};
    void displayMove(){
        cout << name << " (Power: " << power << ")\n";
    }
    string name;
    int power;
};

class Pokemon{
public:
    Pokemon (const string& aName, int aLevel, int aHealth)
    : name(aName), level(aLevel), health(aHealth) {};
    void battle (Pokemon& opponent){
        cout << "Choose a move:\n" << endl;
        for (BattleMove& move: moves){
            move.displayMove();
        }
        string moveName;
        cin >> moveName;
        BattleMove move;
        for (BattleMove& bmove: moves){
            if (bmove.name == moveName){
                move = bmove;
            }
        }
        Pokemon* oppPtr = &opponent;
        oppPtr->health *= ((this->level/oppPtr->level)*move.power);
    }
    void display(){
        cout << name << endl;
        cout << "Health: " << health;
        cout << " Level: " << level << endl;
    }
    void addMove(BattleMove& battle){
        moves.push_back(battle);
    }
    bool isDead () {return((health < 0)||(health == 0)); }
    
private:
    string name;
    vector<BattleMove> moves;
    int health;
    int level;
};

class Trainer{
public:
private:
    string name;
    vector<Pokemon*> pokemon;
};

int main(int argc, const char * argv[]) {
    Pokemon bulba ("bulbasaur", 3, 14);
    Pokemon charm ("charmander", 4, 7);
    BattleMove Tackle("Tackle", 3);
    BattleMove Ember("Ember", 4);
    bulba.addMove(Tackle);
    bulba.addMove(Ember);
    charm.addMove(Tackle);
    while (!bulba.isDead() || !charm.isDead()){
        bulba.display();
        charm.display();
        cout << endl;
        cout << "Bulbasaur's Turn:\n";
        bulba.battle(charm);
        bulba.display();
        charm.display();
        cout << endl;
        cout << "Charmander's Turn:\n";
        charm.battle(bulba);
    }
    bulba.display();
    charm.display();
    return 0;
}
