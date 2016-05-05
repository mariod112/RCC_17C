/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BoardColumn.h
 * Author: mario
 *
 * Created on May 2, 2016, 5:07 PM
 */
#include <list>
#include <string>
#include "Token.h"

using namespace std;

#ifndef BOARDCOLUMN_H
#define BOARDCOLUMN_H

class BoardColumn {
private:
    list<Token> column;
public:
    BoardColumn();
    BoardColumn(const BoardColumn& orig);
    Token peekTop();
    list<Token>* getColumnTokens();
    list<Token> removeColumnTokens();
    void addTokenListOnTop(list<Token>* tokenList);
    void addToken(Token token);
    void clearColumn();
    void moveColumn(BoardColumn* boardColumn);
    Token pullTopToken();
    bool operator==(const Token& other);
//    bool operator!=(const Token& other);
    string toString();
    virtual ~BoardColumn();

};

#endif /* BOARDCOLUMN_H */

