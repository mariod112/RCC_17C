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

using namespace std;

BoardColumn::BoardColumn() {
}

BoardColumn::BoardColumn(const BoardColumn& orig) {
    this->column = orig.column;
}

Token BoardColumn::peekTop()
{
    return column.front();
}

void BoardColumn::addToken(Token token)
{
    column.push_back(token);
}

Token BoardColumn::pullTopToken()
{
    Token temp = column.front();
    column.pop_front();
    return temp;
}

string BoardColumn::toString()
{
    string columnString;
    list<Token>::const_iterator columnIterator;
    
    for(columnIterator = column.begin(); columnIterator != column.end(); ++columnIterator)
    {
        string temp = columnIterator->getName();
        columnString += temp + "\t";
    }
    
    return columnString;
}

BoardColumn::~BoardColumn() {
}