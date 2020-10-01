//STUFF

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
    cerr << "first: " << first << endl;
    cerr << "last: " << last << endl;
    
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
    cerr << "starting with size " << inLine.size() << endl;
    return inLine.size();
}

/*


void dequeue();
void enqueue();
void print();
*/

/* first
*    Purpose: returns element at front of the queue 
* Parameters: None 
*    Returns: Passenger - element at front of queue  
*/
Passenger PassengerQueue::front()
{
    return *inLine.front();
}

Passenger *PassengerQueue::createPassenger(int id, int from, int to)
{
    Passenger *newPassenger = new Passenger;
    newPassenger->id = id;
    newPassenger->from = from;
    newPassenger->to = to;
    return newPassenger;
}

void PassengerQueue::enqueue(const Passenger& passenger)
{
    cerr << "capacity = " << inLine.capacity() << endl;
    //inLine.push_back(passenger);
    cerr << "new capacity = " << inLine.capacity() << endl;
}