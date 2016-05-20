/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.h
 * Author: mdiaz
 *
 * Created on May 20, 2016, 9:32 AM
 */

#include <list>

using namespace std;

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
private:
    int data;
    list<TreeNode*> children;
public:
    TreeNode(int data);
    TreeNode(TreeNode& orig);
    void addChild(int data);
    int getData();
    list<TreeNode*>* getChildren();
    bool isLeaf();
    void printChildren();//md debug
    virtual ~TreeNode();
};

#endif /* TREENODE_H */

