/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on May 28, 2016, 1:59 PM
 */

#include <cstdlib>
#include <iostream>
#include "BinaryTreeNode.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    BinaryTreeNode tree(5);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(6);
    tree.insert(3);
    
    cout << tree.toStringInOrder() << endl;
    cout << tree.toStringPreOrder() << endl;
    cout << tree.toStringPostOrder() << endl;
    return 0;
}

