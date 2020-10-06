/*
*  COMP 15 HW 3 Metro Simulator
*
*  MetroSim.h
*
*  Interface of MetroSim class. Declares the public and private functions and 
*  member variables of the MetroSim class.
*  Deanna Oei 
*  October 6, 2020 
*/  
#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <vector>
#include <string>
#include "Passenger.h"
#include "PassengerQueue.h"

using namespace std;

class MetroSim
{
public:
    MetroSim(string stations, string outputF, string directions, int args);
    ~MetroSim();
    
    void initializeStations(string newStationName);
    void initializeTrain();
    void readInstructions();
    string findDirections();
    void readInStations();
    void userMove();

private:
    
    struct station { 
        string name;
        int stationNum;
        vector<Passenger> atStation;
        bool trainPresent;
    };
    
    struct train {
        int currentStation = 0;
        vector<PassengerQueue> onBoard;
    };
    
    struct instruction {
        bool moveMetro = false;
        bool metroFinish = false;
        bool add = false;
        int fromHere, toHere;
    };
    
    vector<station> allStations;
    train theTrain;
    
    void printTrain(ostream &output);
    void printMap(ostream &output);
    instruction askForInstructions();
    void executeInstructions(instruction direction);
    void addPassenger(int addFrom, int addTo);
    void metroMove();
    void embark(int station);
    void disembark(int station);
    int nextStationInd(int currentInd);
    void writeOutput(int id, string station);

    int nextId = 1;
    int numOfStations = 0;
    
    string outputFile;
    string stationsFile;
    string directionsFile;
    int numArgs;
    
    ofstream outputObject;
};

#endif