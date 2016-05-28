/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTreeNode.cpp
 * Author: mario
 * 
 * Created on May 28, 2016, 2:01 PM
 */

#include "BinaryTreeNode.h"
#include <string>


using namespace std;

BinaryTreeNode::BinaryTreeNode(int data) {
    this->data = data;
    this->left = 0;
    this->right = 0;
}

BinaryTreeNode::BinaryTreeNode(BinaryTreeNode& orig) {
    this->data = orig.data;
    this->left = orig.left;
    this->right = orig.right;
}

void BinaryTreeNode::insert(int data)
{
    if(data <= this->data)
    {
        if(this->left == 0)
        {
            this->left = new BinaryTreeNode(data);
        }
        else
        {
            this->left->insert(data);
        }
    }
    else
    {
        if(this->right == 0)
        {
            this->right = new BinaryTreeNode(data);
        }
        else
        {
            this->right->insert(data);
        }
    }
}

string BinaryTreeNode::toStringInOrder()
{
    string nodeString;
    
    if(this->left != 0)
        nodeString += this->left->toStringInOrder();
    
    nodeString += to_string(this->data) + " ";
    
    if(this->right != 0)
        nodeString += this->right->toStringInOrder();
    
    return nodeString;
}

string BinaryTreeNode::toStringPreOrder()
{
    string nodeString;
    
    nodeString += to_string(this->data) + " ";
    
    if(this->left != 0)
        nodeString += this->left->toStringPreOrder();
    
    if(this->right != 0)
        nodeString += this->right->toStringPreOrder();
    
    
    return nodeString;
}

string BinaryTreeNode::toStringPostOrder()
{
    string nodeString;
    
    if(this->left != 0)
        nodeString += this->left->toStringPostOrder();
    
    if(this->right != 0)
        nodeString += this->right->toStringPostOrder();
    
    nodeString += to_string(this->data) + " ";
    
    return nodeString;
}

BinaryTreeNode::~BinaryTreeNode() {
    if(this->left != 0)
    {
        this->left->~BinaryTreeNode();
        delete this->left;
        this->left = 0;
    }
    if(this->right != 0)
    {
        this->right->~BinaryTreeNode();
        delete this->right;
        this->right = 0;
    }
}

