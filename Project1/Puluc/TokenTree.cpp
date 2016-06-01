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
    this->root = 0;
}

TokenTree::TokenTree(const TokenTree& orig) {
}

void TokenTree::insert(Token token)
{
    if(root != 0)
    {
        TokenTreeNode* temp = new TokenTreeNode();
        temp->insertToken(token);
        
        if(this->root->getToken().getPlayer() == token.getPlayer())
        {
            temp->setLeft(root);
            temp->setRight(root->getRight());
            root->setRight(0);
            root = temp;
        }
        else
        {
            temp->setRight(root);
            temp->setLeft(root->getRight());
            root->setRight(0);
            root = temp;
        }
    }
    else
    {
        this->root = new TokenTreeNode();
        this->root->insertToken(token);
    }
}

Token TokenTree::getTopToken()
{
    if(this->root != 0)
        return this->root->getToken();
    else
    {
        Token temp(-1,-1,"");
        return temp;
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

