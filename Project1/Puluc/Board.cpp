/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Board.cpp
 * Author: mario
 * 
 * Created on May 4, 2016, 5:09 PM
 */

#include "Board.h"
#include "Token.h"

#include <map>
#include <string>

using namespace std;

Board::Board() {
    Token player1_1(1,1,"M1");
    player1Home.push(player1_1);
}

Board::Board(const Board& orig) {
}

void Board::addColumn(string name, BoardColumn* column)
{
    board[name] = column;
}

string Board::toString()
{
    string boardString;
    
    map<string,BoardColumn*>::iterator mapIterator = board.begin();
    
    boardString += "Player 1 Pieces at base: " + to_string(player1Home.size()) + "\n";
    boardString += "Player 1 Pieces dead: " + to_string(player1DeadTokens.size()) + "\n";
    boardString += "=========================================\n";

    while(mapIterator != board.end())
    {
        boardString += "-----------------------------------------\n";
        boardString += mapIterator->first + ":" + mapIterator->second->toString() + "\n";
 
        mapIterator++;
    }
    
    boardString += "-----------------------------------------\n";
    boardString += "=========================================\n";
    boardString += "Player 2 Pieces at base: " + to_string(player2Home.size()) + "\n";
    boardString += "Player 2 Pieces dead: " + to_string(player2DeadTokens.size()) + "\n";
    return boardString; 
}

Board::~Board() {
}

