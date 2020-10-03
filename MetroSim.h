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

class MetroSim
{
public:
    MetroSim();
    ~MetroSim();
    
    void initializeStations(string newStationName);
    void getDirections(string directionsFile);
    
    void printTrain(ostream &output);
    void printMap(ostream &output);
    
    //void readDirections();
    
    
    //temporary 
    // void printMap(ostream &output);
    // struct train {
    //     int currentStation = 0;
    //     PassengerQueue onBoard = PassengerQueue();
    // };
    // train theTrain;
    

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

    void metroMove();
    void embark();
    void disembark();
    
    
    int nextId = 1;
    int numOfStations = 0;

};

#endif
