/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.cpp
 * Author: mario
 * 
 * Created on May 28, 2016, 2:33 PM
 */

#include "BinaryTree.h"
#include "BinaryTreeNode.h"

BinaryTree::BinaryTree(int data) {
    this->root = new BinaryTreeNode(data);
}

BinaryTree::BinaryTree(const BinaryTree& orig) {
}

void BinaryTree::insert(int data)
{
    this->root->insert(data);
}

BinaryTree::~BinaryTree() {
    this->root->~BinaryTreeNode();
    delete this->root;
    this->root = 0;
}

