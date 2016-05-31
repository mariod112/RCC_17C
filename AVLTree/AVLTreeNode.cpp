/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AVLTreeNode.cpp
 * Author: mario
 * 
 * Created on May 30, 2016, 2:22 PM
 */
#include "AVLTreeNode.h"
#include <string>

using namespace std;

AVLTreeNode::AVLTreeNode(int data, AVLTreeNode* parent) {
    this->parent = parent;
    this->data = data;
    this->balance = -1;
}

AVLTreeNode::AVLTreeNode(AVLTreeNode& orig) {
    this->parent = orig.parent;
    this->data = orig.data;
    this->balance = orig.balance;
}

int AVLTreeNode::getData()
{
    return data;
}

int AVLTreeNode::getBalance()
{
    return balance;
}
AVLTreeNode* AVLTreeNode::getLeft()
{
    return this->left;
}
AVLTreeNode* AVLTreeNode::getRight()
{
    return this->right;
}
AVLTreeNode* AVLTreeNode::getParent()
{
    return parent;
}
void AVLTreeNode::setData(int data)
{
    this->data = data;
}
void AVLTreeNode::setBalance(int balance)
{
    this->balance = balance;
}
void AVLTreeNode::setLeft(AVLTreeNode* left)
{
    this->left = left;
}
void AVLTreeNode::setRight(AVLTreeNode* right)
{
    this->right = right;
}
void AVLTreeNode::setParent(AVLTreeNode* parent)
{
    this->parent = parent;
}

string AVLTreeNode::toStringInOrder()
{
    string nodeString;
    
    if(this->left != 0)
        nodeString += this->left->toStringInOrder();
    
    nodeString += to_string(this->data) + " ";
    
    if(this->right != 0)
        nodeString +=  this->right->toStringInOrder();
    
    return nodeString;
}

string AVLTreeNode::toStringPreOrder()
{
    string nodeString;
    
    nodeString += to_string(this->data) + " ";
    
    if(this->left != 0)
        nodeString += this->left->toStringPreOrder();
    
    if(this->right != 0)
        nodeString += this->right->toStringPreOrder();
    
    
    return nodeString;
}

string AVLTreeNode::toStringPostOrder()
{
    string nodeString;
    
    if(this->left != 0)
        nodeString += this->left->toStringPostOrder();
    
    if(this->right != 0)
        nodeString += this->right->toStringPostOrder();
    
    nodeString += to_string(this->data) + " ";
    
    return nodeString;
}

AVLTreeNode::~AVLTreeNode() {
    if(this->parent == 0)//delete all nodes if root
    {
        if(this->left != 0)
        {
            this->left->~AVLTreeNode();
            delete this->left;
            this->left = 0;
        }
        if(this->right != 0)
        {
            this->right->~AVLTreeNode();
            delete this->right;
            this->right = 0;
        }
    }
}

