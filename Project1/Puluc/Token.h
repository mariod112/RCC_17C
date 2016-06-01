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
    int getTokenNumber() const {return this->tokenNumber;}
    string getName() const {return this->name;}
    void setName(string name){this->name = name;}
    bool operator==(const Token& other);
    bool operator!=(const Token& other);
    bool operator<(const Token& other)const;
    virtual ~Token();
};

#endif /* TOKEN_H */

