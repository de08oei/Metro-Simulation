/*
*  COMP 15 HW 3 Metro Simulator
*
*  Passenger.h
*
*  Interface of Passenger class. Contains definition of struct Passenger.
*
*  Deanna Oei 
*  October 6, 2020 
*/  

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <ostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);

};

#endif
