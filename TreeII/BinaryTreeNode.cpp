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

BinaryTreeNode::BinaryTreeNode(int data, BinaryTreeNode* parent) {
    this->parent = parent;
    this->data = data;
    this->left = 0;
    this->right = 0;
}

BinaryTreeNode::BinaryTreeNode(BinaryTreeNode& orig) {
    this->data = orig.data;
    this->left = orig.left;
    this->right = orig.right;
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

bool BinaryTreeNode::remove(int data)
{
    BinaryTreeNode* nodeToRemove = this->find(data);
    
    if(nodeToRemove != 0)//data is in tree
    {
        BinaryTreeNode* tempParent = (*nodeToRemove).getParent();  
        BinaryTreeNode* tempNode;
        
        if(nodeToRemove->left == 0 && nodeToRemove->right == 0)//delete leaf
        {

            if(data < tempParent->getData())
            {
                delete tempParent->left;
                tempParent->left = 0;
                return true;
            }
            else
            {
                delete tempParent->right;
                tempParent->right = 0;
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
            return true;
        }
        else//full node
        {
            nodeToRemove->setData(nodeToRemove->right->findMin());
            nodeToRemove->right->remove(nodeToRemove->getData());
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

