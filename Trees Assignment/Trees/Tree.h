/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: mdiaz
 *
 * Created on May 20, 2016, 9:30 AM
 */
#include "TreeNode.h"

#ifndef TREE_H
#define TREE_H

class Tree {
    private:
        TreeNode* root;
        int m;
        int currentFullLevel;
    public:
        Tree(int m);
        Tree(const Tree& orig);
        bool insertData(int data);
        void print();
        virtual ~Tree();
};

#endif /* TREE_H */

