/* 
 * File:   Token.cpp
 * Author: mario
 * 
 * Created on May 1, 2016, 6:33 PM
 */

#include <vector>

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

bool Token::operator==(const Token& other)
{
    return this->playerNumber == other.playerNumber;
}

bool Token::operator!=(const Token& other)
{
    return this->playerNumber != other.playerNumber;
}
bool Token::operator<(const Token& other)const
{
    return (tokenNumber < other.getTokenNumber());
}

Token::~Token() {
}

