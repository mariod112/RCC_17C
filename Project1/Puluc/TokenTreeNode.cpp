/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TokenTreeNode.cpp
 * Author: mdiaz
 * 
 * Created on May 31, 2016, 5:58 PM
 */

#include "TokenTreeNode.h"
#include <string>

using namespace std;

TokenTreeNode::TokenTreeNode() : token(-1,-1,"") {
}

TokenTreeNode::TokenTreeNode(TokenTreeNode& orig): token(-1,-1,"") {
    this->token = orig.token;
    this->left = orig.left;
    this->right = orig.right;
    this->parent = orig.parent;
}

bool TokenTreeNode::insertToken(Token token)
{
    if(this->token.getPlayer() == -1)
    {
        this->token = token;
        return true;
    }
    else if(token.getPlayer() == this->token.getPlayer())//freed tokens on left
    {
        if(this->left == 0)
        {
            this->left = new TokenTreeNode();
            this->left->token = token;
            return true;
        }
        else
        {
            return this->left->insertToken(token);
        }
    }
    else//captured tokens on right
    {
        if(this->right == 0)
        {
            this->right = new TokenTreeNode();
            this->right->token = token;
            return true;
        }
        else
        {
            return this->right->insertToken(token);
        }
    }
}

string TokenTreeNode::toString()
{
    string tokenTreeString;
    
    tokenTreeString += this->token.getName() + "-";
    
    if(this->left != 0)
        tokenTreeString += this->left->toString();
    
    if(this->right != 0)
        tokenTreeString += this->right->toString();
    
    return tokenTreeString;
}
    
TokenTreeNode::~TokenTreeNode() {
}

