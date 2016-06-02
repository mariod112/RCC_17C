/* 
 * File:   PulucGame.cpp
 * Author: mario
 * 
 * Created on May 5, 2016, 5:18 PM
 */

#include "PulucGame.h"
#include "Token.h"
#include "TreeBoardColumn.h"

PulucGame::PulucGame():player1("First",1),player2("Second",2),dice(4,1,0)
{
    this->currentPlayer = 0;//start with turn 1 -> player 1
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
    
    //add tokens into home queue for player 2
    playerInitial = player2.getName().substr(0,1);
    
    for(int i = 1; i < 6; i++)
    {
        tokenName = playerInitial + to_string(i);
        Token token(2,i,tokenName);
        board.moveTokenIntoHome(token);
    }
    
    for(int i = 1; i < 11; i++)
    {
        TreeBoardColumn column;
//        Token token(1,1,"M1");
//        column.addToken(token);
        board.addColumn(i, column);
    }
}

void PulucGame::moveToBase(int from)
{
    list<Token> tempList = board.getColumnTokens(from);
    list<Token>::iterator listIterator = tempList.begin();
    int playerBase = board.getColumnPlayer(from);
    
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

bool PulucGame::moveFromBase(int to)
{   
    
    if(currentPlayer != board.getColumnPlayer(to))
    {
        return board.moveTokenFromHome(to, currentPlayer);
    }
    
    return false;
}

bool PulucGame::moveFromColumn(int from, int to)
{
    int fromPlayer = board.getColumnPlayer(from);
    int toPlayer = board.getColumnPlayer(to);
    
    if(fromPlayer == toPlayer)//can't move on top of your own token
        return false;
    
    if(currentPlayer == fromPlayer)//only player controlling column can move
    {
        board.moveTokensInColumn(from,to);
        return true;
    }
    
    return false;
}

Player PulucGame::getCurrentPlayer()
{
    if(currentPlayer == 1)
        return player1;
    else
        return player2;
}

string PulucGame::nextTurn()
{
    if(currentPlayer == 1)//next players turn
        currentPlayer = 2;
    else
        currentPlayer = 1;
    
    string turnString = playerNextTurnString() + ":\n";
    
    lastDiceRoll = dice.Roll();
    
    turnString += "Dice Roll: " + dice.toString() + " = " + to_string(lastDiceRoll) + "\n";

    return turnString;
}

bool PulucGame::nextMove(int from, bool direction)
{
    int nextColumn;
    
    if(from == -1)//pass
        return true;
    
    if(from == 0)
    {
        int to = lastDiceRoll;
        
        if(currentPlayer == 2)//move player to up
            to = 11 - lastDiceRoll;
        
        return moveFromBase(to);
    }
    
    if(direction)//move up
    {
        nextColumn = from - lastDiceRoll;
        
        if(nextColumn < 1)
        {
            if(currentPlayer == 1 && board.getColumnPlayer(from) == currentPlayer)//move to player 1 base
            {
                moveToBase(from);
                return true;
            }
            else//wrap player 2 and move back down
               return moveFromColumn(from, (nextColumn * -1) + 2); 
        }
        else//move to next column
        {
            return moveFromColumn(from, nextColumn);
        }
    }
    else//move down
    {
        nextColumn = from + lastDiceRoll;
        
        if(nextColumn > 10)
        {
            if(currentPlayer == 2 && board.getColumnPlayer(from) == currentPlayer)//move to player 2 base
            {
                moveToBase(from);//
                return true;
            }
            else//wrap player 1 and move up
               return moveFromColumn(from, from -(nextColumn - 11)); 
        }
        else//move to next column
        {
            return moveFromColumn(from, nextColumn);
        }
    }
}

bool PulucGame::getGameEnded()
{   
    if(board.getKillCount(1) > 4 || board.getKillCount(2) > 4)//5 tokens killed by one player
    {
        return true;
    }
    
    if(board.getHomeCount(1) == 0 && !board.checkPlayerFreeOnBoard(1))//all player one tokens dead or captured
        return true;
    
    if(board.getHomeCount(2) == 0 && !board.checkPlayerFreeOnBoard(2))//all player two tokens dead or captured
        return true;
    
    return false;
    
}

string PulucGame::winnerString()
{
    return "-------------" + getCurrentPlayer().getName() + " Won!!!---------------";
}

string PulucGame::playerNextTurnString()
{
    string turnString =  getCurrentPlayer().getName() + "'s Turn";
    return turnString;
}

string PulucGame::boardString()
{
    return board.toString();
}

PulucGame::~PulucGame() {
}

