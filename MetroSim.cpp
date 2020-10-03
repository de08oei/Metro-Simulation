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
    
    station newStation;
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
    instruction newInstruction;
    ifstream in;
    in.open(directionsFile);
    
    if (not in.is_open()) {
        while (newInstruction.metroFinish == false) {
            newInstruction = askForInstructions();
            executeInstructions(newInstruction);
            if (newInstruction.metroFinish == false) {
                printMap(cout);
            }
        }
    }
    else {
        //getline(in, direction);
        //execute
    }
    
    in.close();
}

MetroSim::instruction MetroSim::askForInstructions()
{
    instruction direction;
    char frontInstruction, secondInstruction;
    
    cout << "Command? ";
    cin >> frontInstruction;
    if (frontInstruction == 'm') {
        cin >> secondInstruction;
        if (secondInstruction == 'm') {
            direction.moveMetro = true;
        }
        else if (secondInstruction == 'f') {
            direction.metroFinish = true;
        }
    }
    else if (frontInstruction == 'p') {
        direction.add = true;
        cin >> direction.fromHere;
        cin >> direction.toHere;
    }
    
    return direction;
}

void MetroSim::executeInstructions(MetroSim::instruction direction)
{
    if (direction.moveMetro == true) {
        cerr << "Move metro" << endl;
    }
    else if (direction.metroFinish == true) {
        cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    }
    else if (direction.add == true) {
        cerr << "add passenger" << endl;
        // int fromArg = direction.fromHere;
        // int toArg = direction.toHere;
        int stationInd = direction.fromHere - 1;
        addPassenger(direction.fromHere, direction.toHere, stationInd);
    }
}

void MetroSim::addPassenger(int addFrom, int addTo, int stationIndex)
{
    Passenger newPass;
    newPass = allStations.at(stationIndex).atStation.createPassenger(nextId, addFrom, addTo);
    allStations.at(stationIndex).atStation.enqueue(newPass);
    nextId++;
}

