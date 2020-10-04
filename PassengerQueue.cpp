/*
*  COMP 15 HW 3 Metro Simulator
*
*  PassengerQueue.cpp
*
*  PURPOSE
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
    return ptrInLine.size();
}


/* first
*    Purpose: returns element at front of the queue 
* Parameters: None 
*    Returns: Passenger - element at front of queue  
*/
Passenger PassengerQueue::front()
{
    //return inLine.front();
    return *ptrInLine.front();
}

Passenger PassengerQueue::back()
{
    return *ptrInLine.back();
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
    // inLine.push_back(passenger);
    // last = inLine.size() - 1;
    
    //below 
    //const Passenger *newPassPtr = &passenger;
    //newPassPtr = passenger;
    ptrInLine.push_back(&passenger);
//    cerr << "NO";
    last = ptrInLine.size() + 1;
}

void PassengerQueue::dequeue()
{
    // inLine.pop_back();
    // last = inLine.size() - 1;
    ptrInLine.pop_back();
    last = ptrInLine.size() - 1;
}

void PassengerQueue::print(ostream &output)
{
    int queueSize = ptrInLine.size();
    for (int i = 0; i < queueSize; i++) {
        Passenger currPass = *ptrInLine.at(i);
        output << "[" 
             << currPass.id 
             << ", " 
             << currPass.from 
             << "->" 
             << currPass.to 
             << "]";
    }


}

void PassengerQueue::orderPassengers()
{
    cerr << "ORdering" << endl;
    int inLineSize = ptrInLine.size(); //get size for iteration
    cerr << "Size: " << inLineSize << endl;
    for (int i = 0; i < inLineSize - 1; i++) {
        const Passenger *passOne = ptrInLine.at(i); //get the first passenger 
        cerr << "Pass one: " << passOne->id << endl;
    
        const Passenger *passTwo = ptrInLine.at(i + 1); //get the second passenger
        cerr << "Pass two: " << passTwo->id << endl;
        if (passOne->to > passTwo->to) { //compare their to's 
            cerr << "Greateer" << endl;
            const Passenger *temp = passOne;
            cerr << "Temp" << temp->id << endl;
            passOne = passTwo;
            cerr << "New pass one " << passOne->id << endl;
            passTwo = temp;
            cerr << "New pass two " << passTwo->id << endl;
            // swap(passOne, passTwo);
        }
    }
}