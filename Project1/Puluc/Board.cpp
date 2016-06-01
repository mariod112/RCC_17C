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

Board::Board() : board(10) {
    
}

Board::Board(const Board& orig) : board(10){
    this->board = orig.board;
    this->player1Home = orig.player1Home;
    this->player2Home= orig.player2Home;
    this->player1DeadTokens= orig.player1DeadTokens;
    this->player2DeadTokens= orig.player2DeadTokens;
}

void Board::addColumn(int number, BoardColumn column)
{
    board.insert(to_string(number), column);
//    board[number] = column;
}

void Board::moveTokensInColumn(int from, int to)
{
    board.getColumn(to_string(to)).moveOnTopColumn(board.getColumn(to_string(from)));
    board.getColumn(to_string(from)).clearColumn();
//    //if(board.count(from) != 0 && board.count(to) != 0)
//    {
//        board[to].moveOnTopColumn(board[from]);
//        board[from].clearColumn();
//    }
}

bool Board::moveTokenFromHome(int to, int playerNumber)
{
//   if(board.count(to) != 0)
   {
       if(playerNumber == 1)
       {
           if(!player1Home.empty())
           {
               BoardColumn temp = board.getColumn(to_string(to));
               temp.addToken(player1Home.front());
               board.insert(to_string(to), temp);
//               board[to].addToken(player1Home.front());
               player1Home.pop();
           }
           else
               return false;
       }
       else
       {
           if(!player2Home.empty())
           {
               BoardColumn temp = board.getColumn(to_string(to));
               temp.addToken(player2Home.front());
               board.insert(to_string(to), temp);
               //board[to].addToken(player2Home.front());
               player2Home.pop();
           }
           else
               return false;
       }
       
       return true;
   }
   
   return false;
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

list<Token> Board::getColumnTokens(int from)
{
    return board.getColumn(to_string(from)).getColumnTokens();
//    return board[from].getColumnTokens();
}

int Board::getColumnPlayer(int from)
{
    return board.getColumn(to_string(from)).getTopPlayer();
//    return board[from].getTopPlayer();
}

void Board::clearColumn(int column)
{
    board.getColumn(to_string(column)).clearColumn();
//    board[column].clearColumn();
}

void Board::killToken(Token token)//token needs to be removed from original location
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

int Board::getKillCount(int player)
{
    if(player == 1)
    {
        return player1DeadTokens.size();
    }
    else
    {
      return player2DeadTokens.size();   
    } 
}

int Board::getHomeCount(int player)
{
    if(player == 1)
    {
        return player1Home.size();
    }
    else
    {
      return player2Home.size();   
    } 
}

bool Board::checkPlayerFreeOnBoard(int player)
{
    vector<BoardColumn>::iterator mapIterator = board.getBegin();

    while(mapIterator != board.getEnd())
    {
        if(mapIterator->getTopPlayer() == player)//check if player controls column
            return true;
        
        mapIterator++;
    }
    
    return false;
}

string Board::toString()
{
    string boardString;
    
    vector<BoardColumn>::iterator mapIterator = board.getBegin();
    set<Token>::iterator deadIterator;
    
    boardString = "Player 1: \n";
    boardString += "  Pieces at base: " + to_string(player1Home.size()) + "\n";
    boardString += "  Pieces dead: ";
    
    if(!player1DeadTokens.empty())
    {
        for(deadIterator = player1DeadTokens.begin(); deadIterator != player1DeadTokens.end(); deadIterator++)
        {
            boardString += deadIterator->getName() + " ";
        }
    }
    
    boardString += "\n=========================================\n";

    for(int i = 1; i <=  board.getSize(); i++)
    {
        boardString += "-----------------------------------------\n";
        boardString += to_string(i) + ":" + mapIterator->toString() + "\n";
 
        mapIterator++;
    }
    
    
//    while(mapIterator != board.getEnd())
//    {
//        boardString += "-----------------------------------------\n";
//        boardString += to_string(mapIterator->first) + ":" + mapIterator->second.toString() + "\n";
// 
//        mapIterator++;
//    }
  
    boardString += "-----------------------------------------\n";
    boardString += "=========================================\n";
    boardString += "Player 2: \n";
    boardString += "  Pieces at base: " + to_string(player2Home.size()) + "\n";
    boardString += "  Pieces dead: ";
    
    if(!player2DeadTokens.empty())
    {
        for(deadIterator = player2DeadTokens.begin(); deadIterator != player2DeadTokens.end(); deadIterator++)
        {
            boardString += deadIterator->getName() + " ";
        }
    }
    
    boardString += "\n\n";
    
    return boardString; 
}

Board::~Board() {
}

