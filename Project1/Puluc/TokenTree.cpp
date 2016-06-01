/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTree.cpp
 * Author: mdiaz
 * 
 * Created on May 31, 2016, 5:57 PM
 */

#include "TokenTree.h"

TokenTree::TokenTree() {
}

TokenTree::TokenTree(const TokenTree& orig) {
}

void TokenTree::insert(Token token)
{
    if(root != 0)
        this->root->insertToken(token);
    else
    {
        this->root = new TokenTreeNode();
        this->root->insertToken(token);
    }
}

string TokenTree::toString()
{
    if(this->root != 0)
        return this->root->toString();
    else
        return "";
}

TokenTree::~TokenTree() {
}

