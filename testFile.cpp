/*
 *
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
//Passenger Testing Functions
void test_passenger_print();
//MetroSim Testing Functions 
void test_initializeStations(string testFile);
void test_getDirections(string testFile, string directionsFile);
void test_printTrain();
//Main Testing Functions
void readInStations(MetroSim *instance, string filename);

int main(int argc, char *argv[])
{
	cerr << "Testing!" << endl;
	MetroSim *instance = new MetroSim;
	readInStations(instance, "testStations.txt");
	instance->printTrain(cout);
	instance->printMap(cout);
	instance->getDirections("test_commands.txt");
	
	// test_enque();
	// test_createPassenger();
    // test_dequeue();
    // test_size();
    // test_front();
    // test_passenger_print();
    // test_initializeStations("testStations.txt");
    // test_getDirections("testStations.txt", "Hi");
	// test_printTrain();
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

void findDirections(string directionsFile)
{
    instruction newInstruction;
    ifstream in;
    in.open(directionsFile);
    
    if (not in.is_open()) {
        cerr << "File not found" << endl;
        MetroSim::askForInstructions();
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
    instanceOne.print(cout); //what should this do?
    
    cout << "There should be 2 passengers. [1, 2->3] [2, 3->4]" << endl;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    Passenger newPass2 = instanceOne.createPassenger(2,3,4);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
	instanceOne.print(cout);
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
    
    instanceOne.dequeue();
    cout << "Dequeued once: ";
    instanceOne.print(cout);
    instanceOne.dequeue();
    cout << "Dequeued twice: ";
    instanceOne.print(cout);
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

void test_getDirections(string testFile, string directionsFile)
{
    cout << "***** Testing getDirections() *****" << endl;
    MetroSim instanceOne;
    instanceOne.initializeStations(testFile);
    instanceOne.printMap(cout);
    instanceOne.getDirections(directionsFile);
}

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




