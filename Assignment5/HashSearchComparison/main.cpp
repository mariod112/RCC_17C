/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mario
 *
 * Created on May 12, 2016, 5:20 PM
 */

#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> fillArray(int);
vector<list<string>> fillHashedArray(vector<string>*);

int binarySearch(vector<string>*  array, int length, string value);
int linearSearch(vector<string>*  array, int length, string value);
int findHashIndex(vector<list<string>>* hashedArray, string value);

int hashFunction(string input);

int main(int argc, char** argv) {
    //srand(static_cast<unsigned int>(time(0)));
    cout << "N,Linear,Binary,Hash" << endl;
    for(int x = 1; x < 50; x++)
    {
        int arraySize = 10000 * x;
        vector<string> stringArray = fillArray(arraySize);
        vector<list<string>> hashStringArray = fillHashedArray(&stringArray);//copy array using hash 
        
        high_resolution_clock::time_point startChrono;//timing variables
        high_resolution_clock::time_point endChrono;
        duration<double> time_span;
        
        cout << arraySize << ", ";
        int foundAtIndex;
        
        string stringToFind = stringArray[arraySize - 1];//"VVKESCXDSSDHCGMRQPUU";
        
        
        startChrono = high_resolution_clock::now();
        foundAtIndex = linearSearch(&stringArray, arraySize, stringToFind);
        endChrono = high_resolution_clock::now();
        time_span = duration_cast<duration<double>>(endChrono - startChrono);

        cout << time_span.count() << ", " << endl;
        
        sort(stringArray.begin(), stringArray.end());//sort array for binary search
        
        startChrono = high_resolution_clock::now();
        foundAtIndex = binarySearch(&stringArray, arraySize, stringToFind);
        endChrono = high_resolution_clock::now();
        time_span = duration_cast<duration<double>>(endChrono - startChrono);

        cout << time_span.count() << ", " << endl;


        startChrono = high_resolution_clock::now();
        foundAtIndex = findHashIndex(&hashStringArray, stringToFind);
        endChrono = high_resolution_clock::now();
        time_span = duration_cast<duration<double>>(endChrono - startChrono);
        
        cout << time_span.count() << endl;
    }
    
    return 0;
}

int hashFunction(string input)
{
    int index = 0;
    
    for(int i = 0; i < input.size() / 5; i++)//use first fifth of string to calculate hash
    {
        index += (int)input[i] * pow(26,i);
    }
    
    return index;
}

vector<list<string>> fillHashedArray(vector<string>* stringArray)
{
    vector<list<string>> hashedArray(stringArray->size());
    
    for(int i = 0; i < stringArray->size(); i++)
    {
        string tempString = (*stringArray)[i];
        
        int index = hashFunction(tempString) % stringArray->size();
        hashedArray[index].push_back(tempString);
    }
    
    return hashedArray;
}

vector<string> fillArray(int arraySize)
{
    int stringSize = 20;
    vector<string> stringArray;
    
    for(int i = 0; i < arraySize; i++)
    {
        string tempString;
        
        for(int j = 0; j < stringSize; j++)
        {  
            char temp = (char)(rand() % (90 - 66 + 1) + 66);//generate random ascii capital letters
            tempString.push_back(temp);
        }
        
        stringArray.push_back(tempString);
    }
    
    return stringArray;
}

int findHashIndex(vector<list<string>>* hashedArray, string value)
{     
    int indexOf = hashFunction(value) % hashedArray->size();
    list<string>::iterator iteratorHash;

    iteratorHash = (*hashedArray)[indexOf].begin();

    for(int y = 0; y < (*hashedArray)[indexOf].size(); y++)//iterate through list in hashed vector
    {
        string inList = *iteratorHash;
        
        if(inList.compare(value) == 0)//value found return index
        {
            return indexOf;
        }

        iteratorHash++;
    }
    
    return -1;
}

int binarySearch(vector<string>* array, int length, string value)
{
    int index = length / 2;
    int min = 0;
    int max = length;
    int indexLast = index;
    
    while((*array)[index].compare(value) != 0)
    {
        if((*array)[index] > value)
        {
            max = index;
        }
        else
        {
            min = index;
        }
        
        indexLast = index;
        index = (max + min) / 2;
        
        if(indexLast == index)
        {
            index = -1;
            break;
        }
    }
    
    return index;
}

int linearSearch(vector<string>* array, int length, string value)
{
    int index = 0;
    
    while((*array)[index].compare(value) != 0)
    {
        index++;
        
        if(index >= length)
        {
            return -1;
        }
    }
    
    return index;
}