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
    BinaryTreeNode tree(10, 0);
    tree.insert(10);
    tree.insert(9);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    tree.insert(9);
    tree.insert(3);
    tree.insert(8);
    
    cout << tree.toStringInOrder() << endl;
    cout << tree.toStringPreOrder() << endl;
    cout << tree.toStringPostOrder() << endl;
    cout << "Min: " << tree.findMin() << endl;
    cout << tree.find(3)->getData() << endl;
    cout << tree.find(9)->getData() << endl;
    cout << tree.remove(9) << endl;
    cout << tree.remove(3) << endl;
    cout << tree.remove(8) << endl;
    cout << tree.remove(10) << endl;
    cout << tree.remove(10) << endl;
    cout << tree.remove(9) << endl;
    cout << tree.remove(9) << endl;
    cout << tree.remove(7) << endl;
    cout << tree.remove(8) << endl;
    cout << "Root: " << tree.getData() << endl;
    cout << tree.toStringInOrder() << endl;
    return 0;
}

