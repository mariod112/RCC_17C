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
    this->currentCaptured = 0;
    this->currentFreed = 0;
}

TokenTree::TokenTree(TokenTree& orig) {
    this->root = orig.root;
    this->currentCaptured = orig.currentCaptured;
    this->currentFreed = orig.currentFreed;
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
        
        //reset iterator
        this->currentCaptured = 0;
        this->currentFreed = 0;
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
Token TokenTree::getNextCaptured()
{
    if(this->currentCaptured != 0)
    {
        this->currentCaptured = this->currentCaptured->getLeft();
    }
    else if(this->root != 0)
    {
        this->currentCaptured = this->root->getRight();
    }
    
    if(this->currentCaptured != 0)
        return this->currentCaptured->getToken();
    else
    {
        Token temp(-1,-1,"");
        return temp;
    }
}

Token TokenTree::getNextFreed()
{
    if(this->currentFreed != 0)
    {
        this->currentFreed = this->currentFreed->getLeft();
    }
    else if(this->root != 0)
    {
        this->currentFreed = this->root->getLeft();
    }
    
    if(this->currentFreed != 0)
        return this->currentFreed->getToken();
    else
    {
        Token temp(-1,-1,"");
        return temp;
    }
}

list<Token> TokenTree::toList()
{
    list<Token> tokenList;

    TokenTreeNode* temp = this->root;
    
    while(temp != 0)
    {
        tokenList.push_back(temp->getToken());
        
        temp = temp->getLeft();
    }
    
    temp = this->root->getRight();
    
    while(temp != 0)
    {
        tokenList.push_back(temp->getToken());
        
        temp = temp->getLeft();
    }
    
    return tokenList;
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

