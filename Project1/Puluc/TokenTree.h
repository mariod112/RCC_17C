/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTree.h
 * Author: mdiaz
 *
 * Created on May 31, 2016, 5:57 PM
 */
#include "Token.h"
#include "TokenTreeNode.h"
#include <string>

using namespace std;

#ifndef TOKENTREE_H
#define TOKENTREE_H

class TokenTree {
private:
    TokenTreeNode* root;
public:
    TokenTree();
    TokenTree(const TokenTree& orig);
    void insert(Token token);
    string toString();
    virtual ~TokenTree();

};

#endif /* TOKENTREE_H */

