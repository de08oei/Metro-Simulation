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
        void enqueue(const Passenger& passenger); //takes address to passenger
        int size();
        void print(ostream &output);
        
        Passenger createPassenger(int id, int from, int to);
        
    private:
        vector<Passenger> *vectorInLine;
        vector<Passenger> inLine; 
        int first;
        int last;
};

#endif
