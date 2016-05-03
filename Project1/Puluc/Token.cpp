/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Token.cpp
 * Author: mario
 * 
 * Created on May 1, 2016, 6:33 PM
 */

#include "Token.h"

Token::Token(int playerNumber, int tokenNumber, string name) {
    this->playerNumber = playerNumber;
    this->tokenNumber = tokenNumber;
    this->name = name;
}

Token::Token(const Token& orig) {
    this->playerNumber = orig.playerNumber;
    this->tokenNumber = orig.tokenNumber;
    this->name = orig.name;
}

Token::~Token() {
}

