/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DoublyLinkedList.h
 * Author: mario
 *
 * Created on April 2, 2016, 12:55 PM
 */

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <string.h>

#include "DoublyLinkedListElement.h"

using namespace std;

template <class T>
class DoublyLinkedList
{
private:
   DoublyLinkedListElement<T> *head;
   DoublyLinkedListElement<T> *current;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
public:
   // Default constructor
   DoublyLinkedList()
   {
       head = new DoublyLinkedListElement<T>;
       head->next = 0;
       head->previous = 0;
       head->data = 0;
       current = head;
   }
      
   // Constructor declaration
   DoublyLinkedList(T);
   
   // Copy constructor declaration
   DoublyLinkedList(const DoublyLinkedList &);
   
   // Destructor declaration
   ~DoublyLinkedList();
   DoublyLinkedListElement<T>* MoveToNext();
   DoublyLinkedListElement<T>* MoveToLast();
   DoublyLinkedListElement<T>* GetCurrent();
   // Overloaded [] operator declaration
   T &operator[](const int &);
   void Purge();
   void push_back(T);
   void pop_off();
};

//***********************************************************
// Constructor for DoublyLinkedList class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T data)
{
       head = new DoublyLinkedListElement<T>;
       head->next = 0;
       head->previous = 0;
       head->data = data;
       current = head;
}

//*******************************************
// Copy Constructor for DoublyLinkedList class. *
//*******************************************

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList &obj)
{
    this->head = obj->head;
    this->current = obj->current;
}

//**************************************
// Destructor for DoublyLinkedList class.  *
//**************************************

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Purge();
    delete head;
    delete current;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void DoublyLinkedList<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void DoublyLinkedList<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// purge function                                           *
//clear list of all elements                                *
//***********************************************************
template <class T>
void DoublyLinkedList<T>::Purge()
{
    while(head->next != 0)
    {
        DoublyLinkedListElement<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &DoublyLinkedList<T>::operator[](const int &sub)
{
    DoublyLinkedListElement<T>* temp = head;
    int count = sub;
    
    while(temp->next != 0)
    {
        if(count == 0)
            break;
        
        temp = temp->next;
        count--;
    }
    
    return temp->data;
}

//*******************************************************
//GetNext                                               *
//Returns the next element in the list                  *
//*******************************************************
template <class T>
DoublyLinkedListElement<T>* DoublyLinkedList<T>::MoveToNext()
{
    if(current->next != 0)
        current = current->next;
    return current;
}

//*******************************************************
//GetLast                                               *
//Returns the last element in the list                  *
//*******************************************************
template <class T>
DoublyLinkedListElement<T>* DoublyLinkedList<T>::MoveToLast()
{
    if(current->previous != 0)
        current = current->previous;
    return current;
}

//*******************************************************
//GetCurrent                                            *
//Returns the current element in the list               *
//*******************************************************
template <class T>
DoublyLinkedListElement<T>* DoublyLinkedList<T>::GetCurrent()
{
    return current;
}

//*******************************************************
//push_back                                             *
//add element to end of list                            *
//*******************************************************
template <class T>
void DoublyLinkedList<T>::push_back(T value)
{
    DoublyLinkedListElement<T>* temp = current;
    
    while(temp->next != 0)
    {
        temp = temp->next;
    }
    
    temp->next = new DoublyLinkedListElement<T>;
    temp->next->data = value;
    temp->next->next = 0;
    temp->next->previous = temp;
}

//*******************************************************
//pop_off                                               *
//return element at the head then delete head and move  *
//pointer to next element                               *
//*******************************************************
template <class T>
void DoublyLinkedList<T>::pop_off()
{
    if(head->next != 0)
    {
        DoublyLinkedListElement<T>* temp = head;
        head = head->next;
        delete temp;
    }
    
}


#endif /* DOUBLYLINKEDLIST_H */

