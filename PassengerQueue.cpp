/*
*  COMP 15 HW 3 Metro Simulator
*
*  PassengerQueue.cpp
*
*  Implementation of the PassengerQueue class. Contains definitions of key
*  functions that allow the user to create, add to, remove from, print, and 
*  modify passenger queues.
*
*  Deanna Oei 
*  October 6, 2020 
*/  

#include <iostream>
#include <stdexcept>

#include <vector>
#include <string>
#include "PassengerQueue.h"

using namespace std;

/* Default Constructor
*    Purpose: test
* Parameters: None 
*    Returns: None 
*/
PassengerQueue::PassengerQueue()
{
    //vector<Passenger> inLine; //is this needed? it's already made 
    first = 0;
    last = 0;
}

/* Destructor 
*    Purpose: test
* Parameters: None 
*    Returns: None 
*/
PassengerQueue::~PassengerQueue()
{
    
}

/* size 
*    Purpose: return current size of vector inLine 
* Parameters: None 
*    Returns: int - size of vector inLine  
*/
int PassengerQueue::size()
{
    //return ptrInLine.size();
    return inLine.size();
}


/* first
*    Purpose: returns element at front of the queue 
* Parameters: None 
*    Returns: Passenger - element at front of queue  
*/
Passenger PassengerQueue::front()
{
    return inLine.front();
    //return *ptrInLine.front();
}

Passenger PassengerQueue::back()
{
    //return *ptrInLine.back();
    return inLine.back();
}

Passenger PassengerQueue::createPassenger(int id, int from, int to)
{
    Passenger newPassenger;
    newPassenger.id = id;
    newPassenger.from = from;
    newPassenger.to = to;
    return newPassenger; 
}

void PassengerQueue::enqueue(const Passenger &passenger) //object passed by reference
{
    inLine.push_back(passenger);
    last = inLine.size() - 1;

}

void PassengerQueue::dequeue()
{
    inLine.pop_back();
    last = inLine.size() - 1;
    // ptrInLine.pop_back();
    // last = ptrInLine.size() - 1;
}

void PassengerQueue::print(ostream &output)
{

    
    int queueSize = inLine.size();
    for (int i = 0; i < queueSize; i++) {
        Passenger currPass = inLine.at(i);
        output << "[" 
             << currPass.id 
             << ", " 
             << currPass.from 
             << "->" 
             << currPass.to 
             << "]";
    }


}
