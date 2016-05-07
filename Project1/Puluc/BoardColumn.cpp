/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BoardColumn.cpp
 * Author: mario
 * 
 * Created on May 2, 2016, 5:07 PM
 */

#include "BoardColumn.h"
#include <list>
#include <string>
#include "Token.h"

#include <cstdlib>
#include <iostream>

using namespace std;

BoardColumn::BoardColumn() {
}

BoardColumn::BoardColumn(const BoardColumn& orig) {
    this->column = orig.column;
}

//Look at top token
Token BoardColumn::peekTop()
{
    return column.front();
}

int BoardColumn::getTopPlayer()
{
    if(!column.empty())
        return column.front().getPlayer();
    else
        return -1;
}

//return list of tokens (column)
list<Token> BoardColumn::getColumnTokens()
{
    return column;
}

//Add a list of tokens to top of list
void BoardColumn::addTokenListOnTop(list<Token> tokenList)
{
    list<Token>::iterator tokenIterator = tokenList.end();
    
    while(tokenIterator != tokenList.begin())
    {
        tokenIterator--;
        column.push_front(*tokenIterator);   
    }
}

//Clear column of all tokens
void BoardColumn::clearColumn()
{
    column.clear();
}

//Move column from boardColumn to this column
void BoardColumn::moveOnTopColumn(BoardColumn boardColumn)
{
    addTokenListOnTop(boardColumn.getColumnTokens());
}

//Add a single token to top of list
void BoardColumn::addToken(Token token)
{
    column.push_front(token);
}

//Pull the top token in column
Token BoardColumn::pullTopToken()
{
    Token temp = column.front();
    column.pop_front();
    return temp;
}

//print list of tokens
string BoardColumn::toString()
{
    string columnString;
    list<Token>::iterator columnIterator;//get list iterator

    if(!column.empty())
    {
        for(columnIterator = column.begin(); columnIterator != column.end(); ++columnIterator)//iterate through list of tokens
        {
            string temp = columnIterator->getName();//get token name
            columnString += temp + "  ";//add token name to column string
        }
    }
    
    return columnString;
}

BoardColumn::~BoardColumn() {
}