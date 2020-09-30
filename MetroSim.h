/*
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <vector>
#include "Passenger.h"

// Put any other necessary includes here


// Put any other structs you need here

class MetroSim
{
public:

private:
    
    struct station {
        string name;
        int stationNum;
        vector<Passenger> waiting;
        bool trainPresent;
    };

};

#endif
