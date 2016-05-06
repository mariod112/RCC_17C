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
    bool gameEnded;
    int currentTurn;
public:
    PulucGame();
    void setPlayer1Name(string name);
    void setPlayer2Name(string name);
    void setUpBoard();
    string boardString();
    int rollDice();
    virtual ~PulucGame();

private:
    int rollDice();
};

#endif /* PULUCGAME_H */

