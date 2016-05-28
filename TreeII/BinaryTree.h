/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.h
 * Author: mario
 *
 * Created on May 28, 2016, 2:33 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "BinaryTreeNode.h"

class BinaryTree {
private:
    BinaryTreeNode* root;
public:
    BinaryTree(int data);
    BinaryTree(const BinaryTree& orig);
    void insert(int data);
    virtual ~BinaryTree();

};

#endif /* BINARYTREE_H */

