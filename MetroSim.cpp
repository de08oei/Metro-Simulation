/*
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "MetroSim.h"

MetroSim::MetroSim()
{
    
}

MetroSim::~MetroSim()
{
    
}

void MetroSim::initializeStations(string filename)
{
    ifstream in; //read in file ifstream = read in, ofstream = out 
    in.open(filename);
    bool file_found = false;
    
    while (file_found == false) {
        if (not in.is_open()) {
            cerr << "Error: could not open file " << filename;
            exit(1);
        }
        else {
            file_found = true;
        }
    }
    
    //station temp;
    station newStation;
                    //size 
    for (int i = 0; getline(in, newStation.name); i++ ) {

        newStation.stationNum = i + 1;
        
        if (i == 0) {
            newStation.trainPresent = true;
        }
        else {
            newStation.trainPresent = false;
        }
        
        newStation.atStation = PassengerQueue();
        
        allStations.push_back(newStation);
        
    }
    
    in.close();
    
}

void MetroSim::printMap(ostream &output)
{
    int stationsSize = allStations.size();
    for (int i = 0; i < stationsSize; i++) {
        if (allStations[i].trainPresent == true) {
            output << "TRAIN: ";
        }
        else {
            output << "       ";
        }
        
        output << "[" << allStations[i].stationNum << "] "
               << allStations[i].name << "{";
        allStations[i].atStation.print(cout);
        output << "}" << endl;
        
    }
}

void MetroSim::getDirections(string directionsFile)
{
    ifstream in;
    in.open(directionsFile);
    
    if (not in.is_open()) {
        askForDirections();
    }
    else {
        string direction;
        getline(in, direction);
        executeDirections(direction);
    }
    
    in.close();
}

void MetroSim::askForDirections()
{
    string direction = "none";
    string frontInstruction = " ";
    string secondInstruction = " ";
    int fromArg, toArg;
    
    while (direction != "m f") {
        cout << "Command? ";
        
        getline(cin, direction)
        
        executeDirections(direction);
    }
}

void MetroSim::executeDirections(string direction)
{
    cerr << "the direction is: " << direction << endl;
    if (direction == "m m") {
        cerr << "Move metro";
    }
    else if (direction == "m f") {
        cerr << "Exit " << endl;
    }
    else {
        string frontLetter;
        int theFrom;
        int theTo;
        
        cin >> frontLetter;
        
    }
}

void MetroSim::addPassengerDirection(string direction)
{
    
}



