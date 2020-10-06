/*
*  COMP 15 HW 3 Metro Simulator
*
*  MetroSim.cpp
*
*  Implementation of MetroSim class. Includes key functions allowing the user
*  to create, print, add passengers, execute instructions, and interact with
*  a metro simulation.
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
*    Purpose: initialize MetroSim class and opens output file 
* Parameters: string stations   - name of file with station names
*             string outputF    - name of file to print output to
*             string directions - name of file with directions to control the
*                                 simulation
*             int args          - number of arguments the user provides when 
*                                 starting the simulation 
*    Returns: None 
*/
MetroSim::MetroSim(string stations, string outputF, string directions, int args)
{
    outputFile = outputF;
    stationsFile = stations;
    directionsFile = directions;
    numArgs = args;
    outputObject.open(outputFile);
}

/* Destructor 
*    Purpose: recycles memory associated with MetroSim class,
*             closes output file
* Parameters: None 
*    Returns: None 
*/
MetroSim::~MetroSim()
{
    outputObject.close();
}

/* initializeStations
*    Purpose: create/initialize a station and push into vector allStations
* Parameters: string newStationName - name of new station being added 
*    Returns: None 
*/
void MetroSim::initializeStations(string newStationName)
{
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
* Parameters: ostream &output - reference to ostream object  
*    Returns: None 
*/
void MetroSim::printMap(ostream &output)
{
    int stationSize = allStations.size();
    
    //iterate through each station 
    for (int i = 0; i < stationSize; i++) { 
        if (allStations.at(i).trainPresent == true) {
            output << "TRAIN: ";
        }
        else {
            output << "       ";
        }
        
        output << "["
               << allStations.at(i).stationNum + 1
               << "] "
               << allStations.at(i).name
               << " {";
    
        int queueSize = allStations.at(i).atStation.size();
        
        //iterate through each passenger at the current station 
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
    if (frontInstruction == 'm') {          //handles "m m" and "m f" commands 
        cin >> secondInstruction;
        if (secondInstruction == 'm') {
            direction.moveMetro = true;
        }
        else if (secondInstruction == 'f') {
            direction.metroFinish = true;
        }
    }
    else if (frontInstruction == 'p') {     //handles "p" commands 
        direction.add = true;
        cin >> direction.fromHere;
        cin >> direction.toHere;
    }
    
    return direction;
}

/* executeInstructions
*    Purpose: execute a single instruction
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
    int stationIndex = addFrom - 1;
    Passenger newPass(nextId, addFrom, addTo);
    allStations.at(stationIndex).atStation.push_back(newPass);
    
    nextId++;
}

/* metroMove
*    Purpose: move the metro, passengers leave station and enter train 
* Parameters: None 
*    Returns: None 
*/
void MetroSim::metroMove()
{
    int trainAtStation = theTrain.currentStation;
    
    //move passengers from current station onto train 
    embark(trainAtStation); 

    //move the train 
    allStations.at(trainAtStation).trainPresent = false; 
    theTrain.currentStation = nextStationInd(trainAtStation);
    allStations.at(theTrain.currentStation).trainPresent = true;
    trainAtStation = theTrain.currentStation;
    
    //remove passengers who have reached their destination
    disembark(trainAtStation); 
}

/* embark 
*    Purpose: get Passengers from current station onto train's PassengerQueue
* Parameters: int station - index of station passengers are boarding from 
*    Returns: None 
*/
void MetroSim::embark(int station)
{
    int stationQueueSize = allStations.at(station).atStation.size();
    
    //go through each passenger at the station 
    for (int i = 0; i < stationQueueSize; i++) {
        //get the passenger 
        Passenger embarking = allStations.at(station).atStation.at(i);
        //find their destination 
        int destinationInd = embarking.to - 1;
        //add them to the correct passenger queue on the train 
        theTrain.onBoard.at(destinationInd).enqueue(embarking);
    }
    
    //remove passengers from current station b/c they just boarded the train
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
    theTrain.onBoard.resize(allStations.size());
}

/* printTrain 
*    Purpose: print out the train and its passengers
* Parameters: ostream &output - reference to ostream object  
*    Returns: None 
*/
void MetroSim::printTrain(ostream &output)
{
    output << "Passengers on the train: {";
    int size = theTrain.onBoard.size();
    for (int i = 0; i < size; i++) {
        theTrain.onBoard.at(i).print(output);
    }
    
    output << "}" << endl;
}

/* nextStationInd
*    Purpose: provide the index of the next station the train will visit 
* Parameters: int currentInd - index of the train's current station  
*    Returns: int - index of the next station the train visits 
*/
int MetroSim::nextStationInd(int currentInd)
{
    int nextInd = currentInd + 1;
    int totalStations = allStations.size();
    if (nextInd > totalStations - 1) {
        nextInd = 0;
    }
    return nextInd;
}

/* disembark
*    Purpose: remove passengers from the station passenger queue 
* Parameters: int station - index of the station passengers are leaving  
*    Returns: None 
*/
void MetroSim::disembark(int station)
{
    bool allGone = false;
    while (allGone == false) {
        //find how many passengers are to disembark at this station 
        int carSize = theTrain.onBoard.at(station).size();
        if (carSize > 0) {
            for (int i = 0; i < carSize; i++) {
                int id = theTrain.onBoard.at(station).front().id;
                string stationName = allStations.at(station).name;
                //passenger disembarks 
                theTrain.onBoard.at(station).dequeue();
                //record to output
                writeOutput(id, stationName);    
            }
        }
        allGone = true;
    }
}

/* writeOutput
*    Purpose: record which passenger leaves the train and at which station 
* Parameters: int id         - id number of the passenger leaving 
*             string station - name of the station the passenger left at 
*    Returns: None 
*/
void MetroSim::writeOutput(int id, string station)
{
    outputObject << "Passenger "
                 << id
                 << " left train at station "
                 << station 
                 << endl;
}

/* readInStations
*    Purpose: set station names according to file of names given
* Parameters: None
*    Returns: None 
*/
void MetroSim::readInStations()
{
    ifstream in;
    in.open(stationsFile);
    
	if (not in.is_open()) {
		cerr << "Error: could not open file " << stationsFile << endl;
		exit(1);
	}
    
	string newStationName;
	
    for (int i = 0; getline(in, newStationName); i++ ) {
        initializeStations(newStationName);
    }
    
    in.close();
}

/* findDirections
*    Purpose: find which kind of input the program will use for directions
* Parameters: None
*    Returns: string - tells if directions will be given by a "file" or "user" 
*/
string MetroSim::findDirections()
{
    MetroSim::instruction newInstruction;
    ifstream in;
    in.open(directionsFile);
    
    if (not in.is_open()) {
        return "user";
    }
    else {
        return "file";
    }
    
    in.close();
}

/* readInstructions
*    Purpose: read and execute directions given by a file 
* Parameters: None 
*    Returns: None 
*/
void MetroSim::readInstructions()
{
	MetroSim::instruction direction;
    char frontInstruction, secondInstruction;
    ifstream in;
    in.open(directionsFile);
	while (direction.metroFinish == false) {
		direction.moveMetro = false;        //initialize instruction
		direction.metroFinish = false;
		direction.add = false;
		in >> frontInstruction;
        bool condition1 = in.fail() or in.eof();
		if (condition1 or secondInstruction == 'f') {
			direction.metroFinish = true;
		}
	    else if (frontInstruction == 'm') {
	        in >> secondInstruction;
	        if (secondInstruction == 'm') {
	            direction.moveMetro = true;
	        }
	    }
	    else if (frontInstruction == 'p') {
	        direction.add = true;
	        in >> direction.fromHere;
	        in >> direction.toHere;
	    }
        cout << "Command? ";
		printTrain(cout);
		printMap(cout);
		executeInstructions(direction);
	}
    in.close();
}

/* userMove
*    Purpose: execute user inputted instructions
* Parameters: None 
*    Returns: None 
*/
void MetroSim::userMove()
{
    bool quitNow = false;
    while (quitNow == false) {
        MetroSim::instruction newInstruction;
        printTrain(cout);
        printMap(cout);
        newInstruction = askForInstructions();
        executeInstructions(newInstruction);
        if (newInstruction.metroFinish == true) {
            quitNow = true;
        } 
    }
}