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
        void enqueue(const Passenger& passenger);
        int size();
        void print();
        
        //void addPassenger(Passenger *toAdd);
        Passenger *createPassenger(int id, int from, int to);
        
    private:
        vector<Passenger *> inLine;
        int first;
        int last;
};

#endif
