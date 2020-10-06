/*
*  COMP 15 HW 3 Metro Simulator
*
*  testFile.cpp
*
*  Test driver file for MetroSim, PassengerQueue, and Passenger classes. 
*  Contains functions for unit testing functions among those 3 classes above 
*  and main().
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
//void test_createPassenger();
void test_enque();
void test_dequeue();
void test_size();
void test_front();
void test_passengerQueue_print();
//Passenger Testing Functions
void test_passenger_print();
//MetroSim Testing Functions 
void test_initializeStations(string testFile);
void test_printTrain();
//Main Testing Functions
void readInStations(MetroSim instance, string filename);
string findDirections(string directionsFile);
void readInstructions(MetroSim metroInstance, string directionsFile);

int main(int argc, char *argv[])
{
	if (argc < 3 or argc > 4) { //if no station file or more than needed, abort
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]\n";
        return(1);
    }

    string commands;
    string directionType;
    if (argc == 3) {
        commands = "none";
    }
    else {
        commands = argv[3];
    }
	
    MetroSim instance(argv[1], argv[2], commands, argc);
    directionType = instance.findDirections();
    instance.readInStations();
    instance.initializeTrain();
    
    if (directionType == "user") {
        instance.userMove();
    }
    else {
        cerr << "Read in file" << endl;
        instance.readInstructions();
    }

	// test_enque();
	// test_createPassenger();
    // test_dequeue();
    // test_size();
    // test_front();
	// test_back();
    // test_passenger_print();
	// test_passengerQueue_print();
    // test_initializeStations("testStations.txt");
	// test_printTrain();
	
	return 0;
}

/* ******************** Main Function Tests ******************** */

/* readInStations
*    Purpose: set station names according to file of names given
* Parameters: MetroSim metroInstance - instance of MetroSim to be working with
*             string filename  - name of the file with station names 
*    Returns: None 
*/
void readInStations(MetroSim metroInstance, string filename)
{
    ifstream in; //read in file ifstream = read in, ofstream = out 
    in.open(filename);

	if (not in.is_open()) {
		cerr << "Error: could not open file " << filename << endl;
		exit(1);
	}

	string newStationName;

    for (int i = 0; getline(in, newStationName); i++ ) {
		cerr << "new station name " << newStationName << endl;
        metroInstance.initializeStations(newStationName);
    }

    in.close();
}

/* findDirections
*    Purpose: find which kind of input the program will use for directions
* Parameters: string directionsFile - name of file with directions  
*    Returns: string - tells if directions will be given by a "file" or "user" 
*/
// string findDirections(string directionsFile)
// {
//     MetroSim::instruction newInstruction;
//     ifstream in;
//     in.open(directionsFile);
// 
//     if (not in.is_open()) {
//         cerr << "Directions file not found" << endl;
//         return "user";
//     }
//     else {
//         cerr << "Directions file found" << endl;
//         return "file";
//     }
// 
//     in.close();
// }

/* readInstructions
*    Purpose: read and execute directions given by a file 
* Parameters: MetroSim metroInstance - instance of MetroSim to work with
*             string directionsFile - name of file with directions 
*    Returns: None 
*/
// void readInstructions(MetroSim metroInstance, string directionsFile)
// {
// 	MetroSim::instruction direction;
// 
//     char frontInstruction, secondInstruction;
// 
//     ifstream in;
//     in.open(directionsFile);
// 
// 	while (direction.metroFinish == false) {
// 		direction.moveMetro = false;
// 		direction.metroFinish = false;
// 		direction.add = false;
// 		in >> frontInstruction;
// 		if (in.fail()) {
// 			direction.metroFinish = true;
// 		}
// 	    if (frontInstruction == 'm') {
// 	        in >> secondInstruction;
// 	        if (secondInstruction == 'm') {
// 	            direction.moveMetro = true;
// 	        }
// 	        else if (secondInstruction == 'f') {
// 	            direction.metroFinish = true;
// 	        }
// 	    }
// 	    else if (frontInstruction == 'p') {
// 	        direction.add = true;
// 	        in >> direction.fromHere;
// 	        in >> direction.toHere;
// 	    }
// 
// 		metroInstance.printTrain(cout);
// 		metroInstance.printMap(cout);
// 		metroInstance.executeInstructions(direction);
// 	}
// 
//     in.close();
// }

/* test_createPassenger
*    Purpose: test createPassenger()
* Parameters: None 
*    Returns: None 
*/
// void test_createPassenger()
// {
//     cout << "***** Testing createPassenger() *****" << endl;
// 	PassengerQueue instanceTwo;
// 	Passenger newOne = instanceTwo.createPassenger(1, 2, 3);
// 	cerr << "id is "   << newOne.id << endl;
//     cerr << "from is " << newOne.from << endl;
//     cerr << "to is "   << newOne.to << endl;
// }

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
	Passenger newPass(1,2,3);
    Passenger newPass2(2,3,4);
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
	Passenger newPass(1,2,3);
    Passenger newPass2(2,3,4);
    Passenger newPass3(3,4,5);
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
	Passenger newPass(1,2,3);
    Passenger newPass2(2,3,4);
    Passenger newPass3(3,4,5);
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
	Passenger newPass(1,2,3);
    Passenger newPass2(2,3,4);
    Passenger newPass3(3,4,5);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
    instanceOne.enqueue(newPass3);

    instanceOne.front().print(cout);
}

/* test_passengerQueue_print
*    Purpose: test the print functino in PassengerQueue class 
* Parameters: None 
*    Returns: None 
*/
void test_passengerQueue_print()
{
	cout << "***** Testing passengerQueue print() *****" << endl;
	PassengerQueue instanceOne;
	Passenger newPass(1,2,3);
	instanceOne.enqueue(newPass);
	instanceOne.print(cout);
}

/* test_passenger_print
*    Purpose: test passenger class's print()
* Parameters: None 
*    Returns: None 
*/
void test_passenger_print()
{
    cout << "***** Testing passenger class print() *****" << endl;
	Passenger newPass(1,2,3);
    newPass.print(cout);

    Passenger newPass2(4,5,64);
    newPass2.print(cout);
}

/* test_initializeStations
*    Purpose: test the initializeStations function in MetroSim class
* Parameters: string testFile - name of file with station names  
*    Returns: None 
*/
void test_initializeStations(string testFile)
{
    cout << "***** Testing initializeStations() *****" << endl;
    MetroSim instanceOne("a1", "a2", "a3", 1);
    instanceOne.initializeStations(testFile);
    //instanceOne.printMap(cout);
}
