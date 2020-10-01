/*
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <vector>
#include <string>
#include "Passenger.h"
#include "PassengerQueue.h"

using namespace std;

// Put any other necessary includes here


// Put any other structs you need here

struct station { //outside or in class
    string name;
    int stationNum;
    PassengerQueue waiting;
    bool trainPresent;
};

class MetroSim
{
public:
    //create station 

private:
    
    
    
    vector<PassengerQueue> onTrain;

};

#endif
