/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: mdiaz
 * 
 * Created on May 20, 2016, 9:30 AM
 */

#include "Tree.h"
#include "TreeNode.h"
#include <iostream>

Tree::Tree(int m) {
    this->m = m;
    this->currentFullLevel = 0;
    this->root = new TreeNode(m);
}

bool Tree::insertData(int data)
{
    if(this->root->insertData(data, this->currentFullLevel))
    {
        return true;
    }
    else
    {
        this->currentFullLevel++;
        return this->root->insertData(data,this->currentFullLevel);
    }
}

void Tree::print()
{
    this->root->printChildren();
}

Tree::Tree(const Tree& orig) {
}

Tree::~Tree() {
    delete this->root;
}

