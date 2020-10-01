/*
 *
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
        void enqueue(const Passenger& passenger); //takes in an address to passenger
        int size();
        void print();
        
        //void addPassenger(Passenger *toAdd);
        Passenger createPassenger(int id, int from, int to);
        
    private:
        vector<Passenger> *vectorInLine;
        vector<Passenger> inLine; //vector of pointers to passengers
        int first;
        int last;
};

#endif
