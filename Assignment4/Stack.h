/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: mario
 *
 * Created on March 28, 2016, 7:41 PM
 */
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <string.h>

#include "LinkedListElement.h"

template <class T>
class Stack
{
private:
   ListElement<T> *head;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
public:
   // Default constructor
   Stack()
   {
       head = new ListElement<T>;
       head->pointer = 0;
       head->data = 0;
   }
      
   // Constructor declaration
   Stack(T);
   
   // Copy constructor declaration
   Stack(const Stack<T> &);
   
   // Destructor declaration
   ~Stack();
   T peek();
   // Overloaded [] operator declaration
   T &operator[](const int &);
   void Purge();
   void push(T);
   T pop();
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
Stack<T>::Stack(T data)
{
       head = new ListElement<T>;
       head->pointer = 0;
       head->data = data;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
Stack<T>::Stack(const Stack<T> &obj)
{
    this->head = obj->head;
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
Stack<T>::~Stack()
{
    Purge();
    delete head;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void Stack<T>::memError()
{
   //cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void Stack<T>::subError()
{
   //cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void Stack<T>::Purge()
{
    while(head->pointer != 0)
    {
        ListElement<T>* temp = head;
        head = head->pointer;
        delete temp;
    }
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************
template <class T>
T Stack<T>::peek()
{
    return head->data;
}

template <class T>
void Stack<T>::push(T value)
{
    ListElement<T>* temp = new ListElement<T>;

    temp->pointer = head;
    temp->data = value;
    head = temp;
}

template <class T>
T Stack<T>::pop()
{
    T tempValue;
    
    if(head->pointer != 0)
    {
        tempValue = head->data;
        ListElement<T>* temp = head;
        head = temp->pointer;
        
        delete temp;
    }
    
    return tempValue;
}

#endif /* STACK_H */

