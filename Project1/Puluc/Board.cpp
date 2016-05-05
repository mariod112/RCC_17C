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
    Token player1_1(1,3,"M3");
    Token player1_2(1,4,"M4");
    
    player1Home.push(player1_1);
    
    player1DeadTokens.insert(player1_2);
    player1DeadTokens.insert(player1_1);
    
}

Board::Board(const Board& orig) {
    this->board = orig.board;
    this->player1Home = orig.player1Home;
    this->player2Home= orig.player2Home;
    this->player1DeadTokens= orig.player1DeadTokens;
    this->player2DeadTokens= orig.player2DeadTokens;
}

void Board::addColumn(string name, BoardColumn* column)
{
    board[name] = column;
}

void Board::moveColumn(string from, string to)
{
    if(board.count(from) != 0 && board.count(to) != 0)
        board[to]->moveOnTopColumn(board[from]);
}

void Board::moveTokenFromHome(string to, int playerNumber)
{
   if(board.count(to) != 0)
   {
       if(playerNumber == 1)
       {
           board[to]->addToken(player1Home.front());
           player1Home.pop();
       }
       else
       {
           board[to]->addToken(player2Home.front());
           player2Home.pop();
       }
   }
}

void Board::moveTokenIntoHome(Token token)
{
    if(token.getPlayer() == 1)
    {
        player1Home.push(token);
    }
    else
    {
        player2Home.push(token);
    }
}

void Board::killToken(Token token)
{
    if(token.getPlayer() == 1)
    {
       player1DeadTokens.insert(token); 
    }
    else
    {
      player2DeadTokens.insert(token);   
    }
}

string Board::toString()
{
    string boardString;
    
    map<string,BoardColumn*>::iterator mapIterator = board.begin();
    set<Token>::iterator deadIterator;
    
    boardString += "Player 1: \n";
    boardString += "  Pieces at base: " + to_string(player1Home.size()) + "\n";
    boardString += "  Pieces dead: ";
    
    for(deadIterator = player1DeadTokens.begin(); deadIterator != player1DeadTokens.end(); deadIterator++)
    {
        boardString += deadIterator->getName() + " ";
    }
    
    boardString += "\n=========================================\n";

    while(mapIterator != board.end())
    {
        boardString += "-----------------------------------------\n";
        boardString += mapIterator->first + ":" + mapIterator->second->toString() + "\n";
 
        mapIterator++;
    }
    
    boardString += "-----------------------------------------\n";
    boardString += "=========================================\n";
    boardString += "Player 2: \n";
    boardString += "  Pieces at base: " + to_string(player2Home.size()) + "\n";
    boardString += "  Pieces dead: ";
    
    for(deadIterator = player2DeadTokens.begin(); deadIterator != player2DeadTokens.end(); deadIterator++)
    {
        boardString += deadIterator->getName() + " ";
    }
    
    return boardString; 
}

Board::~Board() {
}

