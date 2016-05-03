/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.h
 * Author: mario
 *
 * Created on May 1, 2016, 6:33 PM
 */

#include <string>

using namespace std;

#ifndef TOKEN_H
#define TOKEN_H

class Token {
private:
    int playerNumber;
    int tokenNumber;
    string name;
public:
    Token(int playerNumber, int tokenNumber, string name);
    Token(const Token& orig);
    void setPlayer(int number){this->playerNumber = number;}
    int getPlayer(){return this->playerNumber;}
    void setTokenNumber(int number){this->tokenNumber = number;}
    int getTokenNumber(){return this->tokenNumber;}
    string getName(){return this->name;}
    void setName(string name){this->name = name;}
    virtual ~Token();
};

#endif /* TOKEN_H */

