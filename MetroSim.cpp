/*
*  COMP 15 HW 3 Metro Simulator
*
*  MetroSim.cpp
*
*  PURPOSE
*
*  Deanna Oei 
*  October 6, 2020 
*/  

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "MetroSim.h"

/* Default Constructor 
*    Purpose: initialize MetroSim class 
* Parameters: None 
*    Returns: None 
*/
MetroSim::MetroSim()
{
    
}

/* Destructor 
*    Purpose: recycle memory associated with MetroSim class 
* Parameters: None 
*    Returns: None 
*/
MetroSim::~MetroSim()
{
    
}

/* initializeStations
*    Purpose: initialize station and push into allStations
* Parameters: string newStationName - name of new station being pushed 
*    Returns: None 
*/
void MetroSim::initializeStations(string newStationName)
{
    //with pointers
    /*station *newStation = new station;
    newStation->name = newStationName;    
    newStation->stationNum = numOfStations;
    if (ptrAllStations.size() == 0) {
        cerr << "train present" << endl;
        newStation->trainPresent = true;
    }
    else {
        cerr << "train not present" << endl;
        newStation->trainPresent = false;
    }
    ptrAllStations.push_back(newStation);
    numOfStations++;*/
    //end with pointers
    
    station newStation;
    newStation.name = newStationName;
    newStation.stationNum = numOfStations;
    vector<Passenger> newP;
    newStation.atStation = newP;
    if (allStations.size() == 0) {
        newStation.trainPresent = true;
    }
    else {
        newStation.trainPresent = false;
    }
    allStations.push_back(newStation);
    numOfStations++;
}

/* printMap
*    Purpose: print out map of stations and passengers in queue 
* Parameters: ostream object  
*    Returns: None 
*/
void MetroSim::printMap(ostream &output)
{
    //with pointers below 
    // int stationSize = ptrAllStations.size();
    // for (int i = 0; i < stationSize; i++) {
    //     station *thisStation = ptrAllStations.at(i);
    //     if (thisStation->trainPresent == true) {
    //         output << "TRAIN: ";
    //     }
    //     else {
    //         output << "       ";
    //     }
    // 
    //     output << "["
    //            << thisStation->stationNum + 1
    //            << "] "
    //            << thisStation->name 
    //            << " {";
    // 
    // 
    //     int stationQueueSize = thisStation->atStation.size();
    //     //cerr << "Station queue size: " << stationQueueSize << endl;
    //     for (int a = 0; a < stationQueueSize; a++) {
    //         thisStation->atStation.at(a).print(cout);
    //     }
    //     output << "}" << endl;
    // }
    //end with pointers 
    
    int stationSize = allStations.size();
    for (int i = 0; i < stationSize; i++) {
        if (allStations.at(i).trainPresent == true) {
            output << "TRAIN: ";
        }
        else {
            output << "       ";
        }
        
        output << allStations.at(i).name;
        
        output << " {";
    
        int queueSize = allStations.at(i).atStation.size();
        
        for (int a = 0; a < queueSize; a++) {
            allStations.at(i).atStation.at(a).print(cout);
        }
    
        output << "}"
               << endl;
    }
    
}

/* askForInstructions
*    Purpose: get user inputted instructions 
* Parameters: None 
*    Returns: MetroSim::instruction - instruction to be executed  
*/
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

/* executeInstructions
*    Purpose: execute instructions 
* Parameters: MetroSim::instruction direction - instruction to be executed 
*    Returns: None 
*/
void MetroSim::executeInstructions(MetroSim::instruction direction)
{
    if (direction.moveMetro == true) {
        metroMove();
        direction.moveMetro = false;
    }
    else if (direction.metroFinish == true) {
        cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    }
    else if (direction.add == true) {
        addPassenger(direction.fromHere, direction.toHere);
        direction.add = false;
    }
}

/* addPassenger
*    Purpose: add a passenger to a station 
* Parameters: int addFrom - passenger's original station 
*             int addTo - passenger's destination station 
*    Returns: None 
*/
void MetroSim::addPassenger(int addFrom, int addTo)
{
    // cerr << "add passenger" << endl;
    // int stationIndex = addFrom - 1;
    // station *addAtStation = ptrAllStations.at(stationIndex);
    // cerr << "adding at station " << addAtStation->name << endl;
    // PassengerQueue newQueue;
    // Passenger newPass = newQueue.createPassenger(nextId, addFrom, addTo);
    // cerr << "new passenger: ";
    // newPass.print(cout);
    // newQueue.enqueue(newPass);
    // newQueue.print(cout);
    // addAtStation->atStation.push_back(newQueue);
    // 
    // nextId++;
    
    int stationIndex = addFrom - 1;
    PassengerQueue newQueue;
    Passenger newPass = newQueue.createPassenger(nextId, addFrom, addTo);
    // newQueue.enqueue(newPass);
    allStations.at(stationIndex).atStation.push_back(newPass);
    
    nextId++;
}

void MetroSim::metroMove()
{
    cerr << "Move metro " << endl;
    int trainAtStation = theTrain.currentStation;
    embark(trainAtStation); //put passengers from station on train 

    allStations.at(trainAtStation).trainPresent = false; //move the train 
    theTrain.currentStation = nextStationInd(trainAtStation);
    allStations.at(theTrain.currentStation).trainPresent = true;
    trainAtStation = theTrain.currentStation;
    
    disembark(trainAtStation);
}

/* embark 
*    Purpose: get Passengers from current station onto train's PassengerQueue
* Parameters: None 
*    Returns: None 
*/
void MetroSim::embark(int station)
{
    int stationQueueSize = allStations.at(station).atStation.size();
    cerr << "stationQueueSize" << stationQueueSize << endl;
    
    //go through each passenger at the station 
    for (int i = 0; i < stationQueueSize; i++) {
        //get the passenger 
        Passenger embarking = allStations.at(station).atStation.at(i);
        //find their destination 
        int destinationInd = embarking.to - 1;
        //add them to the correct passenger queue on the train 
        cerr << "Their destination idx " << destinationInd << endl;
        theTrain.onBoard.at(destinationInd).enqueue(embarking);
    }
    
    for (int i = 0; i < stationQueueSize; i++) {
        allStations.at(station).atStation.pop_back();
    }

}

/* initializeTrain
*    Purpose: initialize size of PassengerQueue vector 
* Parameters: None 
*    Returns: None 
*/
void MetroSim::initializeTrain()
{
    //int numStations = allStations.size();
    //vector<PassengerQueue> initializedPQ(numStations);
    theTrain.onBoard.resize(allStations.size());
}


void MetroSim::printTrain(ostream &output)
{
    output << "Passengers on the train: {";
    int size = theTrain.onBoard.size();
    for (int i = 0; i < size; i++) {
        theTrain.onBoard.at(i).print(output);
    }
    
    output << "}" << endl;
}

int MetroSim::nextStationInd(int currentInd)
{
    int nextInd = currentInd + 1;
    int totalStations = allStations.size();
    if (nextInd > totalStations - 1) {
        nextInd = 0;
    }
    return nextInd;
}

void MetroSim::disembark(int station)
{
    bool allGone = false;
    while (allGone == false) {
        int carSize = theTrain.onBoard.at(station).size();
        if (carSize > 0) {
            for (int i = 0; i < carSize; i++) {
                theTrain.onBoard.at(station).dequeue();
            }
        }
        allGone = true;
    }
}

