/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeBoardColumn.cpp
 * Author: mdiaz
 * 
 * Created on June 2, 2016, 6:19 PM
 */

#include "TreeBoardColumn.h"

TreeBoardColumn::TreeBoardColumn() {
}

TreeBoardColumn::TreeBoardColumn(const TreeBoardColumn& orig) {
    this->column = orig.column;
}

int TreeBoardColumn::getTopPlayer()
{
    return this->column.getTopToken().getPlayer();
}

Token TreeBoardColumn::getTopToken()
{
    return this->column.getTopToken();
}

list<Token> TreeBoardColumn::getColumnTokens()
{
    return this->column.toList();
}

void TreeBoardColumn::addToken(Token token)
{
    this->column.insert(token);
}

void TreeBoardColumn::moveOnTopColumn(TreeBoardColumn boardColumn)
{
    Token nextToken = boardColumn.getNextCaptured();
            
    while(nextToken.getPlayer() != -1)
    {
        this->column.insert(nextToken);
        nextToken = boardColumn.getNextCaptured();
    }
    
    nextToken = boardColumn.getNextFreed();
    
    while(nextToken.getPlayer() != -1)
    {
        this->column.insert(nextToken);
        nextToken = boardColumn.getNextFreed();
    }
    
    nextToken = boardColumn.getTopToken();
    
    if(nextToken.getPlayer() != -1)
        this->column.insert(nextToken);
}
    
Token TreeBoardColumn::getNextFreed()
{
    return this->column.getNextFreed();
}

Token TreeBoardColumn::getNextCaptured()
{
    return this->column.getNextCaptured();
}
    
string TreeBoardColumn::toString()
{
    return this->column.toString();
}

TreeBoardColumn::~TreeBoardColumn() {
}

