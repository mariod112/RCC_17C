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
    BinaryTreeNode* parent;
    int height;
    int balanceFactor;
public:
    BinaryTreeNode(int data, BinaryTreeNode* parent);
    BinaryTreeNode(BinaryTreeNode& orig);
    int getData();
    void setData(int data);
    BinaryTreeNode* getParent();
    void setParent(BinaryTreeNode* parent);
    void updateHeight();
    int getHeight();
    int getBalanceFactor();
    void insert(int data);
    BinaryTreeNode* find(int data);
    int findMin();
    int findMax();
    bool remove(int data);
    void leftRotation();
    void rightRotation();
    void leftRightRotation();
    void rightLeftRotation();
    string toStringInOrder();
    string toStringPreOrder();
    string toStringPostOrder();
    virtual ~BinaryTreeNode();
};

#endif /* BINARYTREENODE_H */

