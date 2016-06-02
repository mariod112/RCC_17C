/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeBoardColumn.h
 * Author: mdiaz
 *
 * Created on June 2, 2016, 6:19 PM
 */

#include <list>
#include <string>
#include "Token.h"
#include "TokenTree.h"

#ifndef TREEBOARDCOLUMN_H
#define TREEBOARDCOLUMN_H

class TreeBoardColumn {
private:
    TokenTree column;
public:
    TreeBoardColumn();
    TreeBoardColumn(const TreeBoardColumn& orig);
    int getTopPlayer();
    Token getTopToken();
    list<Token> getColumnTokens();
    void addToken(Token token);
    void moveOnTopColumn(TreeBoardColumn boardColumn);
    Token getNextFreed();
    Token getNextCaptured();
    string toString();
    virtual ~TreeBoardColumn();
private:

};

#endif /* TREEBOARDCOLUMN_H */

