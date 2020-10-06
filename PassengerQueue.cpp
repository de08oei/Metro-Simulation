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
*    Purpose: initialize a PassengerQueue
* Parameters: None 
*    Returns: None 
*/
PassengerQueue::PassengerQueue()
{
    first = 0;
    last = 0;
}

/* Destructor 
*    Purpose: recycle memory associated with the PassengerQueue class
* Parameters: None 
*    Returns: None 
*/
PassengerQueue::~PassengerQueue()
{
    
}

/* size 
*    Purpose: return current size of vector
* Parameters: None 
*    Returns: int - size of vector
*/
int PassengerQueue::size()
{
    return inLine.size();
}

/* first
*    Purpose: returns Passenger at front of the queue 
* Parameters: None 
*    Returns: Passenger - Passenger at front of queue  
*/
Passenger PassengerQueue::front()
{
    return inLine.front();
}

/* enqueue 
*    Purpose: push given passenger into queue 
* Parameters: const Passenger &passenger - constant reference to a passenger  
*    Returns: None 
*/
void PassengerQueue::enqueue(const Passenger &passenger) 
{
    inLine.push_back(passenger);
    last = inLine.size() - 1;
}

/* dequeue 
*    Purpose: remove first passenger from the front of the queue 
* Parameters: None 
*    Returns: None 
*/
void PassengerQueue::dequeue()
{
    inLine.erase(inLine.begin());
    last = inLine.size() - 1;
}

/* print 
*    Purpose: print out passenger queue 
* Parameters: ostream &output - reference to ostream object  
*    Returns: None 
*/
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
