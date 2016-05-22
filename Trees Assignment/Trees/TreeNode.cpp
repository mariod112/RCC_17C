/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.cpp
 * Author: mdiaz
 * 
 * Created on May 20, 2016, 9:32 AM
 */

#include "TreeNode.h"
#include <list>
#include <iostream>

using namespace std;


TreeNode::TreeNode(int m) {
    this->m = m;
}

TreeNode::TreeNode(TreeNode& orig) {

    this->children.clear();
    list<TreeNode*>::iterator childrenIterator = orig.getChildren()->begin();
    
    while(childrenIterator != orig.children.end())
    {
        this->children.push_back(*childrenIterator);
        childrenIterator++;
    }
    
    
    this->children.assign(orig.children.begin(),orig.children.end());
}

bool TreeNode::addChild(int data)
{
    if(!isFull())
    {
        TreeNode* newNode = new TreeNode(this->m);
        newNode->setData(data);
        newNode->setLevel(this->level + 1);
        this->children.push_back(newNode);
        return true;
    }
    
    return false;
}

bool TreeNode::insertData(int data, int level)
{
    if(this->level == level)
    {
        return addChild(data);
    }
    else
    {
        list<TreeNode*>::iterator childIterator = this->children.begin();
    
        while(childIterator != this->children.end())
        {
            if((*childIterator)->insertData(data, level))
            {
                return true;
            }
            else
            {
                childIterator++;
            }
        }
    }
    
    return false;
}

list<TreeNode*>* TreeNode::getChildren()
{
    return &children;
}

int TreeNode::getData()
{
    return this->data;
}

void TreeNode::setData(int data)
{
    this->data = data;
}

int TreeNode::getLevel()
{
    return this->level;
}

void TreeNode::setLevel(int level)
{
    this->level = level;
}

TreeNode* TreeNode::getParent()
{
    return this->parent;
}

void TreeNode::setParent(TreeNode* parent)
{
    this->parent = parent;
}

bool TreeNode::isLeaf()
{
    return this->children.empty();
}

bool TreeNode::isFull()
{
    return this->children.size() >= m;
}

void TreeNode::printChildren()
{
    list<TreeNode*>::iterator childIterator = this->children.begin();
    
    if(!this->isLeaf())
        cout << "Level " << this->level << ": ";
    
    while(childIterator != this->children.end())
    {
        cout << (*childIterator)->getData() << ",";
        childIterator++;
    }
    
     if(!this->isLeaf())
        cout << endl;
    
    childIterator = this->children.begin();
    
    while(childIterator != this->children.end())
    {
        (*childIterator)->printChildren();
        childIterator++;
    }
}

TreeNode::~TreeNode() {
    list<TreeNode*>::iterator childIterator = this->children.begin();
    
    while(childIterator != this->children.end())
    {
        (*childIterator)->~TreeNode();//clear all branches
        delete (*childIterator);
        childIterator++;
    }
    
    this->children.clear();
}

