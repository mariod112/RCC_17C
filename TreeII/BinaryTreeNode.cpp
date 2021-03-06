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
#include <iostream>

using namespace std;

BinaryTreeNode::BinaryTreeNode(int data, BinaryTreeNode* parent) {
    this->parent = parent;
    this->data = data;
    this->left = 0;
    this->right = 0;
    this->height = 0;
}

BinaryTreeNode::BinaryTreeNode(BinaryTreeNode& orig) {
    this->data = orig.data;
    this->left = orig.left;
    this->right = orig.right;
    this->height = orig.height;
}

int BinaryTreeNode::getData()
{
    return this->data;
}

void BinaryTreeNode::setData(int data)
{
    this->data = data;
}


BinaryTreeNode* BinaryTreeNode::getParent()
{
    return this->parent;
}

void BinaryTreeNode::setParent(BinaryTreeNode* parent)
{
    this->parent = parent;   
}

void BinaryTreeNode::updateHeight()
{
    int leftHeight = -1;
    int rightHeight = -1;
    
    if(this->left != 0 && this->right != 0)
    {
        leftHeight = this->left->getHeight();
        rightHeight = this->right->getHeight();
        
        if(leftHeight > rightHeight)
        {
            this->height = leftHeight + 1;
        }
        else
        {
            this->height = rightHeight + 1;
        }
    }
    else if(this->left != 0)
    {
        leftHeight = this->left->getHeight();
        this->height = leftHeight + 1;
    }
    else if(this->right != 0)
    {
        rightHeight = this->right->getHeight();
        this->height = rightHeight + 1;
    }
    else//leaf node
    {
        this->height = 0;
    }
    
    this->balanceFactor = leftHeight - rightHeight;
    cout << "Balance Factor: " << this->balanceFactor << endl;
    
    if(this->balanceFactor == -2)
    {
        if(this->right->getBalanceFactor() == -1)
            cout << "left Rotation" << endl;
        else
            cout << " right Left rotation" << endl;
    }
    else if(this->balanceFactor == 2)
    {
        if(this->left->getBalanceFactor() == 1)
            cout << "right Rotation" << endl;
        else
            cout << "left right rotation" << endl;
    }
    
    if(this->parent != 0)
        this->parent->updateHeight();
}

int BinaryTreeNode::getHeight()
{
    return this->height;
}

int BinaryTreeNode::getBalanceFactor()
{
    return this->balanceFactor;
}

void BinaryTreeNode::insert(int data)
{
    if(data >= this->data)
    {
        if(this->right == 0)
        {
            this->right = new BinaryTreeNode(data, this);
        }
        else
        {
            this->right->insert(data);
        }
    }
    else
    {
        if(this->left == 0)
        {
            this->left = new BinaryTreeNode(data, this); 
        }
        else
        {
            this->left->insert(data);
        }
    }
    
    this->updateHeight();
}

BinaryTreeNode* BinaryTreeNode::find(int data)
{
    if(this->data == data)
        return this;
    
    if(data >= this->data)
    {
        if(this->right == 0)
        {
            return 0;
        }
        else
        {
            return this->right->find(data);
        }
    }
    else
    {
        if(this->left == 0)
        {
            return 0;
        }
        else
        {
            return this->left->find(data);
        }
    }
}

int BinaryTreeNode::findMin()
{
    if(this->left == 0)
        return this->data;
    else
        return this->left->findMin();
}

int BinaryTreeNode::findMax()
{
    if(this->right == 0)
        return this->data;
    else
        return this->right->findMax();
}

bool BinaryTreeNode::remove(int data)
{
    BinaryTreeNode* nodeToRemove = this->find(data);
    
    if(nodeToRemove != 0)//data is in tree
    {
        BinaryTreeNode* tempParent = (*nodeToRemove).getParent();  
        BinaryTreeNode* tempNode;
        
        if(tempParent == 0)//root
        {
            //replace node with smallest value the delete smallest value
            if(nodeToRemove->right != 0)
            {
                nodeToRemove->setData(nodeToRemove->right->findMin());
                nodeToRemove->right->remove(nodeToRemove->getData());
            }
            else if(nodeToRemove->left != 0)
            {
                nodeToRemove->setData(nodeToRemove->left->findMax());
                nodeToRemove->left->remove(nodeToRemove->getData()); 
            }
            else
            {
                nodeToRemove->data = 0;
            }
            
            nodeToRemove->updateHeight();
            return true;
        }
        else if(nodeToRemove->left == 0 && nodeToRemove->right == 0)//delete leaf
        {

            if(data < tempParent->getData())
            {
                delete tempParent->left;
                tempParent->left = 0;
                tempParent->updateHeight();
                return true;
            }
            else
            {
                delete tempParent->right;
                tempParent->right = 0;
                tempParent->updateHeight();
                return true;
            }
        }
        else if(nodeToRemove->right == 0)//node on left
        {
            tempNode = nodeToRemove->left;
            tempNode->setParent(tempParent);
            
            if(tempParent->right == nodeToRemove)
            {
                delete tempParent->right;
                tempParent->right = tempNode;
            }
            else
            {
                delete tempParent->left;
                tempParent->left = tempNode;
            }
            
            tempParent->updateHeight();
            return true;
        }
        else if(nodeToRemove->left == 0)//node on right
        {
            tempNode = nodeToRemove->right;
            tempNode->setParent(tempParent);
            
            if(tempParent->right == nodeToRemove)
            {
                delete tempParent->right;
                tempParent->right = tempNode;
            }
            else
            {
                delete tempParent->left;
                tempParent->left = tempNode;
            }
            
            tempParent->updateHeight();
            return true;
        }
        else//full node
        {
            nodeToRemove->setData(nodeToRemove->right->findMin());
            nodeToRemove->right->remove(nodeToRemove->getData());
            tempParent->updateHeight();
            return true;
        }
    }
    else
        return false;
}

string BinaryTreeNode::toStringInOrder()
{
    string nodeString;
    
    if(this->left != 0)
        nodeString += this->left->toStringInOrder();
    
    nodeString += to_string(this->data) + "(" + to_string(this->getHeight()) + ")";
    
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
    if(this->parent == 0)//delete all nodes if root
    {
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
}

