/* 
 * File:   Player.cpp
 * Author: mario
 * 
 * Created on May 1, 2016, 4:57 PM
 */

#include "Player.h"
#include<string>

using namespace std;

Player::Player(string name, int number) {
    this->name = name;
    this->playerNumber = number;
}

Player::Player(const Player& orig) {
    this->name = orig.name;
    this->playerNumber = orig.playerNumber;
}

string Player::toString()
{
    //string playerString = "Player " + to_string(this->playerNumber) + ": " + this->name;
    string playerString = "Player " + to_string(this->playerNumber) + ": " + this->name;
    return playerString;
}

Player::~Player() {
}

