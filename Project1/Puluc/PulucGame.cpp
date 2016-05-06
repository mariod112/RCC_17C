/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PulucGame.cpp
 * Author: mario
 * 
 * Created on May 5, 2016, 5:18 PM
 */

#include "PulucGame.h"
#include "Token.h"
#include "BoardColumn.h"

PulucGame::PulucGame():player1("X",1),player2("O",2),dice(5,1,0)
{
}

void PulucGame::setPlayer1Name(string name)
{
    player1.setName(name);
}

void PulucGame::setPlayer2Name(string name)
{
    player2.setName(name);
}

void PulucGame::setUpBoard()
{
    string playerInitial = player1.getName().substr(0,1);
    string tokenName;
    
//    add tokens into home queue for player 1
    for(int i = 1; i < 6; i++)
    {
        tokenName = playerInitial + to_string(i);
        Token token(1,i,tokenName);
        board.moveTokenIntoHome(token);
    }
    
    //add tokens into home queue for player 1
    playerInitial = player2.getName().substr(0,1);
    
    for(int i = 1; i < 6; i++)
    {
        tokenName = playerInitial + to_string(i);
        Token token(2,i,tokenName);
        board.moveTokenIntoHome(token);
    }
    
    for(int i = 1; i < 11; i++)
    {
        BoardColumn column;
        board.addColumn(i, column);
    }
    
    board.moveTokenFromHome(5,1);
    board.moveTokenFromHome(5,2);
}

void PulucGame::moveToBase(int from)
{
    list<Token> tempList = board.getColumnTokens(from);
    list<Token>::iterator listIterator = tempList.begin();
    int playerBase = listIterator->getPlayer();
    
    while(listIterator != tempList.end())
    {
        if(listIterator->getPlayer() == playerBase)
        {
            board.moveTokenIntoHome(*listIterator);
        }
        else
        {
            board.killToken(*listIterator);
        }
               
        listIterator++;
    }
    
    board.clearColumn(from);
}

int PulucGame::rollDice()
{
    return dice.Roll();
}

string PulucGame::boardString()
{
    return board.toString();
}

PulucGame::~PulucGame() {
}

