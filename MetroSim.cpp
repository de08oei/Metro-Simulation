/*
 *
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
*    Purpose: initialize stations and push into allStations
* Parameters: string newStationName - name of new station being pushed 
*    Returns: None 
*/
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
    ptrAllStations.push_back(&newStation);
    numOfStations++;
}

/* printMap
*    Purpose: print out map of stations and passengers in queue 
* Parameters: ostream object  
*    Returns: None 
*/
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

/* getUserInstruction
*    Purpose: public function that calls private function asking user for 
* Parameters: None 
*    Returns: MetroSim::instruction - instruction to execute  
*/
// MetroSim::instruction MetroSim::getUserInstruction()
// {
//     instruction newInstruction;
//     newInstruction = askForInstructions();
//     return newInstruction;
// }


// void MetroSim::getDirections(string directionsFile)
// {
//     instruction newInstruction;
//     ifstream in;
//     in.open(directionsFile);
// 
//     if (not in.is_open()) {
//         cerr << "File not found" << endl;
//         while (newInstruction.metroFinish == false) {
//             newInstruction = askForInstructions();
//             executeInstructions(newInstruction);
//             if (newInstruction.metroFinish == false) {
//                 printMap(cout);
//             }
//         }
//     }
//     else {
//         cerr << "File found" << endl;
//         instruction direction;
//         char frontInstruction, secondInstruction;
// 
//         in >> frontInstruction;
//         if (frontInstruction == 'm') {
//             in >> secondInstruction;
//             if (secondInstruction == 'm') {
//                 newInstruction.moveMetro = true;
//             }
//             else if (secondInstruction == 'f') {
//                 newInstruction.metroFinish = true;
//             }
//         }
//         else if (frontInstruction == 'p') {
//             newInstruction.add = true;
//             in >> newInstruction.fromHere;
//             in >> newInstruction.toHere;
//         }
//         executeInstructions(newInstruction);
//     }
// 
//     in.close();
// }

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
        cerr << "Move metro" << endl;
        metroMove();
    }
    else if (direction.metroFinish == true) {
        cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
    }
    else if (direction.add == true) {
        cerr << "add passenger" << endl;
        addPassenger(direction.fromHere, direction.toHere);
    }
}

/* addPassenger
*    Purpose: add a passenger to a station 
* Parameters: int addFrom - passenger's original station 
*             int addTo - passenger's destination station 
*             int stationIndex - current station being added to 
*    Returns: None 
*/
void MetroSim::addPassenger(int addFrom, int addTo)
{
    Passenger newPass;
    int stationIndex = addFrom - 1;
    newPass = allStations.at(stationIndex).atStation.createPassenger(nextId, addFrom, addTo);
    allStations.at(stationIndex).atStation.enqueue(newPass);
    nextId++;
}

void MetroSim::metroMove()
{
    int trainAtStation = theTrain.currentStation;
    embark(trainAtStation);
    //get passengers at current station , embark 
    //move metro 
    //disembark 
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
    for (int i = 0; i < stationQueueSize; i++) {
        PassengerQueue nextPass = allStations.at(station).atStation.inLine.at(i);
        theTrain.onBoard.push_back(nextPass);
    }
    
    for (int i = 0; i < stationQueueSize + 1; i++) {

        allStations.at(station).atStation.dequeue();

    }

}

void MetroSim::printTrain(ostream &output)
{
    int size = theTrain.onBoard.size();
    output << "Passengers on the train: {";
    
    for (int i = 0; i < size; i++) {
        
        theTrain.onBoard.at(i).print(output);
    }

    output << "}" << endl;
}