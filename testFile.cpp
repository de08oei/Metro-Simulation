/*
*  COMP 15 HW 3 Metro Simulator
*
*  testFile.cpp
*
*  PURPOSE
*
*  Deanna Oei 
*  October 6, 2020 
*/  

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"

using namespace std;

//PassengerQueue Testing Functions 
void test_createPassenger();
void test_enque();
void test_dequeue();
void test_size();
void test_front();
void test_orderPassengers();
void test_back();

//Passenger Testing Functions
void test_passenger_print();
//MetroSim Testing Functions 
void test_initializeStations(string testFile);
//void test_getDirections(string testFile, string directionsFile);
void test_printTrain();
//Main Testing Functions
void readInStations(MetroSim *instance, string filename);
string findDirections(string directionsFile);
void readInstructions(MetroSim *metroInstance, string directionsFile);

int main(int argc, char *argv[])
{
	cerr << "Testing!" << endl;
	MetroSim *instance = new MetroSim;
	readInStations(instance, "testStations.txt");
	
	bool quitNow = false;
	string directionType;
	directionType = findDirections("test_commjands.txt");
	
	while (quitNow == false) {
		instance->printTrain(cout);
		instance->printMap(cout);
		MetroSim::instruction newInstruction;
	
		if (directionType == "user") {
			newInstruction = instance->askForInstructions();
			instance->executeInstructions(newInstruction);
			if (newInstruction.metroFinish == true) {
				quitNow = true;
			} 
		}
		else {
			cerr << "Read in file" << endl;
			readInstructions(instance, "test_commands.txt");
			quitNow = true;
		}
	}

	// test_enque();
	// test_createPassenger();
    // test_dequeue();
    // test_size();
    // test_front();
	// test_back();
    // test_passenger_print();
    // test_initializeStations("testStations.txt");
	// test_printTrain();
	// test_orderPassengers();
	
	return 0;
}

/* ******************** Main Function Tests ******************** */

void readInStations(MetroSim *metroInstance, string filename)
{
    ifstream in; //read in file ifstream = read in, ofstream = out 
    in.open(filename);
    bool file_found = false;
    
	if (not in.is_open()) {
		cerr << "Error: could not open file " << filename;
		exit(1);
	}
	else {
		file_found = true;
	}
    
	string newStationName;
	
    for (int i = 0; getline(in, newStationName); i++ ) {
		
        metroInstance->initializeStations(newStationName);
    }
    
    in.close();
}

string findDirections(string directionsFile)
{
    MetroSim::instruction newInstruction;
    ifstream in;
    in.open(directionsFile);
    
    if (not in.is_open()) {
        cerr << "File not found" << endl;
        return "user";
    }
    else {
        cerr << "File found" << endl;
        return "file";
    }
    
    in.close();
}

void readInstructions(MetroSim *metroInstance, string directionsFile)
{
	MetroSim::instruction direction;

    char frontInstruction, secondInstruction;
	
    ifstream in;
    in.open(directionsFile);
    
	while (direction.metroFinish == false) {
		direction.moveMetro = false;
		direction.metroFinish = false;
		direction.add = false;
		in >> frontInstruction;
	    if (frontInstruction == 'm') {
	        in >> secondInstruction;
	        if (secondInstruction == 'm') {
	            direction.moveMetro = true;
	        }
	        else if (secondInstruction == 'f') {
	            direction.metroFinish = true;
	        }
	    }
	    else if (frontInstruction == 'p') {
	        direction.add = true;
	        in >> direction.fromHere;
	        in >> direction.toHere;
	    }
		
		metroInstance->executeInstructions(direction);
	}
		
	
	
    in.close();
}

/* ******************** PassengerQueue Function Tests ******************** */

/* test_createPassenger
*    Purpose: test createPassenger()
* Parameters: None 
*    Returns: None 
*/
void test_createPassenger()
{
    cout << "***** Testing createPassenger() *****" << endl;
	PassengerQueue instanceTwo;
	Passenger newOne = instanceTwo.createPassenger(1, 2, 3);
	cerr << "id is "   << newOne.id << endl;
    cerr << "from is " << newOne.from << endl;
    cerr << "to is "   << newOne.to << endl;
}

/* test_enqueue 
*    Purpose: test enqueue()
* Parameters: None 
*    Returns: None 
*      Notes: Also tests print()
*/
void test_enque()
{
    cout << "***** Testing enqueue() *****" << endl;
    PassengerQueue instanceOne;
    cout << "Original: " << endl;
    instanceOne.print(cout); 
    
    cout << "The following should print below: [1, 2->3] [2, 3->4]" << endl;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    Passenger newPass2 = instanceOne.createPassenger(2,3,4);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
	cerr << "enqueued" << endl;
	instanceOne.print(cout);
	cout << endl;
}

/* test_dequeue 
*    Purpose: test dequeue() 
* Parameters: None 
*    Returns: None 
*/
void test_dequeue()
{
    cout << "***** Testing dequeue() *****" << endl;
    PassengerQueue instanceOne;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    Passenger newPass2 = instanceOne.createPassenger(2,3,4);
    Passenger newPass3 = instanceOne.createPassenger(3,4,5);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
    instanceOne.enqueue(newPass3);
    cout << "Original: ";
	instanceOne.print(cout);
	cout << endl;
    
    instanceOne.dequeue();
    cout << "Dequeued once: ";
    instanceOne.print(cout);
	cout << endl;
    instanceOne.dequeue();
    cout << "Dequeued twice: ";
    instanceOne.print(cout);
	cout << endl;
}

/* test_size 
*    Purpose: test size()
* Parameters: None 
*    Returns: None 
*/
void test_size()
{
    cout << "***** Testing size() *****" << endl;
    PassengerQueue instanceOne;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    Passenger newPass2 = instanceOne.createPassenger(2,3,4);
    Passenger newPass3 = instanceOne.createPassenger(3,4,5);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
    instanceOne.enqueue(newPass3);
    cout << "Original: ";
	instanceOne.print(cout);
    cout << "Size is " << instanceOne.size() << endl;
    
    instanceOne.dequeue();
    instanceOne.dequeue();
    cout << "Dequeued twice: ";
    instanceOne.print(cout);
    cout << "Size is " << instanceOne.size() << endl;
}

/* test_front 
*    Purpose: test front() 
* Parameters: None 
*    Returns: None
*/
void test_front()
{
    cout << "***** Testing front() *****" << endl;
    PassengerQueue instanceOne;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    Passenger newPass2 = instanceOne.createPassenger(2,3,4);
    Passenger newPass3 = instanceOne.createPassenger(3,4,5);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
    instanceOne.enqueue(newPass3);
    
    instanceOne.front().print(cout);
}

void test_orderPassengers() {
	cout << "***** Testing orderPassengers() *****" << endl;
	PassengerQueue instanceOne;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
	Passenger newPass2 = instanceOne.createPassenger(2,3,2);
	Passenger newPass3 = instanceOne.createPassenger(3,4,5);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
	instanceOne.enqueue(newPass3);

	instanceOne.print(cout);
	instanceOne.orderPassengers();
	instanceOne.print(cout);
}

/* test_back 
*    Purpose: test back() 
* Parameters: None 
*    Returns: None
*/
void test_back()
{
    cout << "***** Testing back() *****" << endl;
    PassengerQueue instanceOne;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    Passenger newPass2 = instanceOne.createPassenger(2,3,4);
    Passenger newPass3 = instanceOne.createPassenger(3,4,5);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
    instanceOne.enqueue(newPass3);
    
    instanceOne.back().print(cout);
}

/* ******************** Passenger Function Tests ******************** */

/* test_passenger_print
*    Purpose: test passenger class's print()
* Parameters: None 
*    Returns: None 
*/
void test_passenger_print()
{
    cout << "***** Testing passenger class print() *****" << endl;
    PassengerQueue instanceOne;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    newPass.print(cout);
    
    Passenger newPass2 = instanceOne.createPassenger(4,5,64);
    newPass2.print(cout);
}

/* ******************** MetroSims Function Tests ******************** */

void test_initializeStations(string testFile)
{
    cout << "***** Testing initializeStations() *****" << endl;
    MetroSim instanceOne;
    instanceOne.initializeStations(testFile);
    instanceOne.printMap(cout);
}

// void test_getDirections(string testFile, string directionsFile)
// {
//     cout << "***** Testing getDirections() *****" << endl;
//     MetroSim instanceOne;
//     instanceOne.initializeStations(testFile);
//     instanceOne.printMap(cout);
//     instanceOne.getDirections(directionsFile);
// }

// void test_printTrain()
// {
// 	cout << "***** Testing printTrain() *****" << endl;
// 	MetroSim msInstance;
// 	Passenger newPass = msInstance.theTrain.onBoard.createPassenger(1,2,3);
// 	Passenger newPass2 = msInstance.theTrain.onBoard.createPassenger(2,3,4);
// 	msInstance.theTrain.onBoard.enqueue(newPass);
// 	msInstance.theTrain.onBoard.enqueue(newPass2);
// 	msInstance.theTrain.onBoard.print(cout);
// }