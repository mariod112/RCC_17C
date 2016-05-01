// SortedLinkedList class template
#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <string.h>

#include "LinkedListElement.h"

using namespace std;

template <class T>
class SortedLinkedList
{
private:
   ListElement<T> *head;
   ListElement<T> *next;
   void memError();  // Handles memory allocation errors
   void subError();  // Handles subscripts out of range
   
public:
   // Default constructor
   SortedLinkedList()
   {
       head = new ListElement<T>;
       head->pointer = 0;
       head->data = 0;
       next = head;
   }
      
   // Constructor declaration
   SortedLinkedList(T);
   
   // Copy constructor declaration
   SortedLinkedList(const SortedLinkedList &);
   
   // Destructor declaration
   ~SortedLinkedList();
   ListElement<T>* GetNext();
   // Overloaded [] operator declaration
   T &operator[](const int &);
   void Purge();
   void push_back(T);
   T  pop_off();
};

//***********************************************************
// Constructor for SortedLinkedList class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SortedLinkedList<T>::SortedLinkedList(T data)
{
       head = new ListElement<T>;
       head->pointer = NULL;
       head->data = data;
       next = head;
}

//*******************************************
// Copy Constructor for SortedLinkedList class. *
//*******************************************

template <class T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList &obj)
{
    this->head = obj->head;
    this->next = obj->next;
}

//**************************************
// Destructor for SortedLinkedList class.  *
//**************************************

template <class T>
SortedLinkedList<T>::~SortedLinkedList()
{
    Purge();
    delete head;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SortedLinkedList<T>::memError()
{
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SortedLinkedList<T>::subError()
{
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void SortedLinkedList<T>::Purge()
{
    while(head != NULL)
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
T &SortedLinkedList<T>::operator[](const int &sub)
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
ListElement<T>* SortedLinkedList<T>::GetNext()
{
    ListElement<T>* temp = next;
    
    next = next->pointer;
    
    return temp;
}

template <class T>
void SortedLinkedList<T>::push_back(T value)
{
    ListElement<T>* temp = head;
    ListElement<T>* tempLast = NULL;
        
    while(temp->data < value)
    {
        tempLast = temp;
        temp = temp->pointer;
        
        if(temp == NULL)
            break;
    }
    
    
    if(tempLast != NULL)
    {
        ListElement<T>* newElement = new ListElement<T>;
        tempLast->pointer = newElement;
        newElement->data = value;
        newElement->pointer = temp;
    }
    else
    {
        ListElement<T>* newElement = new ListElement<T>;
        newElement->pointer = head;
        newElement->data = value;
        head = newElement;
    }
}

template <class T>
T SortedLinkedList<T>::pop_off()
{
    T value = 0;
    
    if(head != NULL)
    {
        value = head->data;
        
        ListElement<T>* temp = head;
        head = head->pointer;
        delete temp;
    }
    
    return value;
    
}
#endif