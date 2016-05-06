/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.h
 * Author: mario
 *
 * Created on May 4, 2016, 5:09 PM
 */

#include "BoardColumn.h"
#include <map>
#include <queue>
#include <set>
#include <string>


using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    map<int,BoardColumn*> board;
    queue<Token> player1Home;
    queue<Token> player2Home;
    set<Token> player1DeadTokens;
    set<Token> player2DeadTokens;
public:
    Board();
    Board(const Board& orig);
    void addColumn(int number, BoardColumn* column);
    void moveTokensInColumn(int from, int to);
    void moveTokenFromHome(int to, int playerNumber);
    void moveTokenIntoHome(Token token);
    void killToken(Token token);
    string toString();
    virtual ~Board();

};

#endif /* BOARD_H */

