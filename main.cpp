/*
*  COMP 15 HW 3 Metro Simulator
*
*  main.cpp
*
*  Driver file for MetroSim, PassengerQueue, and Passenger classes. Contains
*  main() function, reads in files, and executes the simulation. 
*
*  Deanna Oei 
*  October 6, 2020 
*/  

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3 or argc > 4) { //if no station file or more than needed, abort
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]\n";
        return(1);
    }

    string directionType;
    MetroSim instance(argv[1], argv[2], argv[3], argc);
    directionType = instance.findDirections();
    instance.readInStations();
    instance.initializeTrain();

    
    if (directionType == "user") {
        instance.userMove();
    }
    else {
        cerr << "Read in file" << endl;
        instance.readInstructions();
    }
}
