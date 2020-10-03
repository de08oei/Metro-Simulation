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

void MetroSim::initializeStations(string newStationName)
{
    station newStation;
    
    newStation.name = newStationName;
    
    newStation.stationNum = numOfStations;
    
    if (numOfStations == 0) {
        newStation.trainPresent = true;
    }
    else {
        newStation.trainPresent = false;
    }

    newStation.atStation = PassengerQueue();
    allStations.push_back(newStation);

    numOfStations++;
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
        output << "[" 
               << allStations[i].stationNum 
               << "] "
               << allStations[i].name 
               << "{";
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
        cerr << "File not found" << endl;
        while (newInstruction.metroFinish == false) {
            newInstruction = askForInstructions();
            executeInstructions(newInstruction);
            if (newInstruction.metroFinish == false) {
                printMap(cout);
            }
        }
    }
    else {
        cerr << "File found" << endl;
        instruction direction;
        char frontInstruction, secondInstruction;

        in >> frontInstruction;
        if (frontInstruction == 'm') {
            in >> secondInstruction;
            if (secondInstruction == 'm') {
                newInstruction.moveMetro = true;
            }
            else if (secondInstruction == 'f') {
                newInstruction.metroFinish = true;
            }
        }
        else if (frontInstruction == 'p') {
            newInstruction.add = true;
            in >> newInstruction.fromHere;
            in >> newInstruction.toHere;
        }
        executeInstructions(newInstruction);
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

void MetroSim::metroMove()
{
    //get passengers at current station , embark 
    //move metro 
    //disembark 
}

/* embark 
*    Purpose: get Passengers from current station onto train's PassengerQueue
* Parameters: None 
*    Returns: None 
*/
void MetroSim::embark()
{
    //get current station 
    //get passengers at current station onto train 
    
    
}

void MetroSim::printTrain(ostream &output)
{
    output << "Passengers on the train: {";
    theTrain.onBoard.print(output);
    output << "}" << endl;
}
