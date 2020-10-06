/*
*  COMP 15 HW 3 Metro Simulator
*
*  main.cpp
*
*  Driver file for MetroSim, PassengerQueue, and Passenger classes. Contains
*  main() function, reads in files, and executes the metro simulation. 
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
    //check if user provided appropriate amount of files 
    if (argc < 3 or argc > 4) { 
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]\n";
        return(1);
    }

    string commands;
    string directionType;
    if (argc == 3) {
        commands = "none";
    }
    else {
        commands = argv[3];
    }

    MetroSim instance(argv[1], argv[2], commands, argc);
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
