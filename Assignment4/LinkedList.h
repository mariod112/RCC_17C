// LinkedList class template
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <string.h>

#include "LinkedListElement.h"

using namespace std;

template <class T>
class LinkedList
{
private:
   ListElement<T> *head;
   ListElement<T> *next;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
public:
   // Default constructor
   LinkedList()
   {
       head = new ListElement<T>;
       head->pointer = 0;
       head->data = 0;
       next = head;
   }
      
   // Constructor declaration
   LinkedList(T);
   
   // Copy constructor declaration
   LinkedList(const LinkedList &);
   
   // Destructor declaration
   ~LinkedList();
   ListElement<T>* GetNext();
   // Overloaded [] operator declaration
   T &operator[](const int &);
   void Purge();
   void push_back(T);
   void pop_off();
};

//***********************************************************
// Constructor for LinkedList class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
LinkedList<T>::LinkedList(T data)
{
       head = new ListElement<T>;
       head->pointer = 0;
       head->data = data;
       next = head;
}

//*******************************************
// Copy Constructor for LinkedList class. *
//*******************************************

template <class T>
LinkedList<T>::LinkedList(const LinkedList &obj)
{
    this->head = obj->head;
    this->next = obj->next;
}

//**************************************
// Destructor for LinkedList class.  *
//**************************************

template <class T>
LinkedList<T>::~LinkedList()
{
    Purge();
    delete head;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void LinkedList<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void LinkedList<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void LinkedList<T>::Purge()
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
T &LinkedList<T>::operator[](const int &sub)
{
    ListElement<T>* temp = head;
    int count = sub;
    
    while(temp->pointer != 0)
    {
        if(count == 0)
            break;
        
        temp = temp->pointer;
        count--;
    }
    
    return temp->data;
}

template <class T>
ListElement<T>* LinkedList<T>::GetNext()
{
    ListElement<T>* temp = next;
    
    next = next->pointer;
    
    return temp;
}

template <class T>
void LinkedList<T>::push_back(T value)
{
    ListElement<T>* temp = next;
    
    while(temp->pointer != 0)
    {
        temp = temp->pointer;
    }
    
    temp->pointer = new ListElement<T>;
    temp->pointer->data = value;
    temp->pointer->pointer = 0;
}

template <class T>
void LinkedList<T>::pop_off()
{
    if(head->pointer != 0)
    {
        ListElement<T>* temp = head;
        head = head->pointer;
        delete temp;
    }
    
}
#endif