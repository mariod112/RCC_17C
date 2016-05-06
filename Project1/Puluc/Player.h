/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: mario
 *
 * Created on May 1, 2016, 4:57 PM
 */
#include<string>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    string name;
    int playerNumber;
public:
    Player();
    Player(string name, int number);
    Player(const Player& orig);
    string getName(){return this->name;}
    int getNumber(){return this->playerNumber;}
    void setName(string name){this->name = name;}
    void setNumber(int number){this->playerNumber = number;}
    string toString();
    virtual ~Player(); 
};

#endif /* PLAYER_H */

