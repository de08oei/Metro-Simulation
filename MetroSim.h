/*
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include <vector>
#include <string>
#include "Passenger.h"
#include "PassengerQueue.h"

using namespace std;

// Put any other necessary includes here


// Put any other structs you need here



class MetroSim
{
public:
    MetroSim();
    ~MetroSim();
    
    void initializeStations(string filename);
    void getDirections(string directionsFile);
    
    //void readDirections();
    
    
    //temporary 
    void printMap(ostream &output);
    

private:
    
    struct station { 
        string name;
        int stationNum;
        PassengerQueue atStation;
        bool trainPresent;
    };
    
    struct train {
        int currentStation = 0;
        PassengerQueue onBoard = PassengerQueue();
    };
    
    struct instruction {
        bool moveMetro = false;
        bool metroFinish = false;
        bool add = false;
        int fromHere, toHere;
    };
    
    instruction askForInstructions();
    void executeInstructions(instruction direction);
    void addPassenger(int addFrom, int addTo, int stationIndex);
    
    vector<PassengerQueue> onTrain;
    vector<station> allStations;
    train theTrain;

    void moveMetro();
    void embark();
    void disembark();
    
    int nextId = 1;

};

#endif
