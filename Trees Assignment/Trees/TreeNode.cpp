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


TreeNode::TreeNode(int data) {
    this->data = data;
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

void TreeNode::addChild(int data)
{
    TreeNode* newNode = new TreeNode(data);
    this->children.push_back(newNode);
}

list<TreeNode*>* TreeNode::getChildren()
{
    return &children;
}

int TreeNode::getData()
{
    return this->data;
}

bool TreeNode::isLeaf()
{
    return this->children.empty();
}

void TreeNode::printChildren()
{
    list<TreeNode*>::iterator childIterator = this->children.begin();
    
    while(childIterator != this->children.end())
    {
        cout << "node data: " << (*childIterator)->getData() << endl;
        childIterator++;
    }
}

TreeNode::~TreeNode() {
    list<TreeNode*>::iterator childIterator = this->children.begin();
    
    while(childIterator != this->children.end())
    {
        delete (*childIterator);
        childIterator++;
    }
    
    this->children.clear();
}

