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
    void askForDirections();
    //void readDirections();
    void executeDirections(string direction);
    
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
    
    vector<PassengerQueue> onTrain;
    vector<station> allStations;
    train theTrain;

    void moveTrain();
    void embark();
    void disembark();

};

#endif
