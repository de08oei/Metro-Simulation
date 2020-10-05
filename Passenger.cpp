/*
*  COMP 15 HW 3 Metro Simulator
*
*  Passenger.cpp
*
*  Implementation of the Passenger class. Contains function to print out 
*  passengers.
*
*  Deanna Oei 
*  October 6, 2020 
*/  
#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;

/* print 
*    Purpose: print out a passenger's information such as id, initial station,
*             and destination station
* Parameters: ostream object output  
*    Returns: None 
*/
void Passenger::print(ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
}
