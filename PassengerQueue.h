/*
*  COMP 15 HW 3 Metro Simulator
*
*  PassengerQueue.h
*
*  Interface of PassengerQueue class. Declares public and private functions 
*  and member variables of the PassengerQueue class.
*
*  Deanna Oei 
*  October 6, 2020 
*/  

#ifndef _PASSENGERQUEUE_H_
#define _PASSENGERQUEUE_H_

#include <vector>
#include "Passenger.h"

using namespace std;

class PassengerQueue
{
    public:
        PassengerQueue();
        ~PassengerQueue();
        
        Passenger front();
        void dequeue();
        void enqueue(const Passenger& passenger); 
        int size();
        void print(ostream &output);
        
    private:
        vector<Passenger> inLine; 
        int first;
        int last;
};

#endif
