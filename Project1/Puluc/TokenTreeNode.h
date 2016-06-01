/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTreeNode.h
 * Author: mdiaz
 *
 * Created on May 31, 2016, 5:58 PM
 */
#include "Token.h"
#include <string>

using namespace std;

#ifndef TOKENTREENODE_H
#define TOKENTREENODE_H

class TokenTreeNode {
private:
    Token token;
    TokenTreeNode* left;
    TokenTreeNode* right;
public:
    TokenTreeNode();
    TokenTreeNode(TokenTreeNode& orig);
    bool insertToken(Token token);
    Token getToken();
    TokenTreeNode* getLeft();
    TokenTreeNode* getRight();
    void setLeft(TokenTreeNode* left);
    void setRight(TokenTreeNode* right);
    string toString();
    virtual ~TokenTreeNode();
};

#endif /* TOKENTREENODE_H */

