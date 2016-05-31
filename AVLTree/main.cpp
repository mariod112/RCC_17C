/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on May 30, 2016, 2:21 PM
 */

#include <cstdlib>
#include <iostream>
#include "AVLTree.h"

using namespace std;

int main(int argc, char** argv) {
    AVLTree tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.remove(3);
    tree.remove(5);
    cout << tree.toStringInOrder() << endl;
    cout << tree.toStringPostOrder() << endl;
    cout << tree.toStringPreOrder() << endl;
    
    return 0;
}

