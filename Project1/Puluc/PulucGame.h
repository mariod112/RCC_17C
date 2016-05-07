/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PulucGame.h
 * Author: mario
 *
 * Created on May 5, 2016, 5:18 PM
 */
#include <string>
#include "Player.h"
#include "Board.h"
#include "Dice.h"


#ifndef PULUCGAME_H
#define PULUCGAME_H

class PulucGame {
private:
    Player player1;
    Player player2;
    Dice dice;
    Board board;
    int currentPlayer;
    int lastDiceRoll;
public:
    PulucGame();
    void setPlayer1Name(string name);
    void setPlayer2Name(string name);
    void setUpBoard();
    void moveToBase(int from);
    bool moveFromBase(int to);
    bool moveFromColumn(int from, int to);
    Player getCurrentPlayer();
    string nextTurn();
    bool nextMove(int from, bool direction);
    bool getGameEnded();
    string playerNextTurnString();
    string winnerString();
    string boardString();
    virtual ~PulucGame();
};

#endif /* PULUCGAME_H */

