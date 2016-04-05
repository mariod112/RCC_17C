/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TestClass.h
 * Author: mario
 *
 * Created on March 28, 2016, 7:25 PM
 */

#ifndef TESTCLASS_H
#define TESTCLASS_H

class TestClass {
public:
    TestClass(int value);
    TestClass(const TestClass& orig);
    virtual ~TestClass();
    int GetValue(){return value;}
    void SetValue(int value){this->value = value;}
private:
    int value;
};

#endif /* TESTCLASS_H */

