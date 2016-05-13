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
#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> fillArray(int);
vector<string> fillHashedArray(int);

int binarySearch(vector<string>  array, int length, string value);
int linearSearch(vector<string>  array, int length, string value);

int main(int argc, char** argv) {
    //srand(static_cast<unsigned int>(time(0)));
    for(int x = 1; x < 6; x++)
    {
        int arraySize = 10000 * x;
        vector<string> stringArray = fillArray(arraySize);
        vector<string> hashStringArray = fillHashedArray(arraySize);//incomplete
        high_resolution_clock::time_point startChrono;
        high_resolution_clock::time_point endChrono;
        duration<double> time_span;

//        for(int i = 0; i < 10; i++)
//        {
//            cout << stringArray[i] << endl;
//        }


        sort(stringArray.begin(), stringArray.end());

        int foundAtIndex;
        string stringToFind = "?:)(&3;>3?18+>)7'A45";

        startChrono = high_resolution_clock::now();
        foundAtIndex = binarySearch(stringArray, arraySize, stringToFind);
        endChrono = high_resolution_clock::now();
        time_span = duration_cast<duration<double>>(endChrono - startChrono);

        cout << "Binary Found in " << time_span.count()  << " sec" << endl;


        startChrono = high_resolution_clock::now();
        foundAtIndex = linearSearch(stringArray, arraySize, stringToFind);
        endChrono = high_resolution_clock::now();
        time_span = duration_cast<duration<double>>(endChrono - startChrono);

        cout << "Linear Found in " << time_span.count()  << " sec" << endl;
    }
    
    return 0;
}

vector<string> fillHashedArray(int arraySize)
{
    int stringSize = 20;
    vector<string> stringArray(arraySize);
    
    for(int i = 0; i < arraySize; i++)
    {
        string tempString;
        
        for(int j = 0; j < stringSize; j++)
        {  
            char temp = (char)(rand() % (65 - 33 + 1) + 33);//generate random ascii char
            tempString.push_back(temp);
        }
        
        stringArray[i] = tempString;
    }
    
    return stringArray;
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
            char temp = (char)(rand() % (65 - 33 + 1) + 33);//generate random ascii char
            tempString.push_back(temp);
        }
        
        stringArray.push_back(tempString);
    }
    
    return stringArray;
}

int binarySearch(vector<string> array, int length, string value)
{
    int index = length / 2;
    int min = 0;
    int max = length;
    int indexLast = index;
    
    while(array[index].compare(value) != 0)
    {
        if(array[index] > value)
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

int linearSearch(vector<string> array, int length, string value)
{
    int index = 0;
    
    while(array[index].compare(value) != 0)
    {
        index++;
        
        if(index >= length)
        {
            return -1;
        }
    }
    
    return index;
}