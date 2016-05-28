/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTreeNode.h
 * Author: mario
 *
 * Created on May 28, 2016, 2:01 PM
 */

#include <string>

using namespace std;

#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

class BinaryTreeNode {
private:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
public:
    BinaryTreeNode(int data);
    BinaryTreeNode(BinaryTreeNode& orig);
    void insert(int data);
    string toStringInOrder();
    string toStringPreOrder();
    string toStringPostOrder();
    virtual ~BinaryTreeNode();
};

#endif /* BINARYTREENODE_H */

