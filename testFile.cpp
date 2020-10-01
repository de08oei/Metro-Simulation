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

int main(int argc, char *argv[])
{
	cerr << "Testing!" << endl;
	// test_enque();
	// test_createPassenger();
    // test_dequeue();
    // test_size();
    // test_front();
    // test_passenger_print();
	return 0;
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
    instanceOne.print(); //what should this do?
    
    cout << "There should be 2 passengers. [1, 2->3] [2, 3->4]" << endl;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
    Passenger newPass2 = instanceOne.createPassenger(2,3,4);
	instanceOne.enqueue(newPass);
	instanceOne.enqueue(newPass2);
	instanceOne.print();
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
	instanceOne.print();
    
    instanceOne.dequeue();
    cout << "Dequeued once: ";
    instanceOne.print();
    instanceOne.dequeue();
    cout << "Dequeued twice: ";
    instanceOne.print();
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
	instanceOne.print();
    cout << "Size is " << instanceOne.size() << endl;
    
    instanceOne.dequeue();
    instanceOne.dequeue();
    cout << "Dequeued twice: ";
    instanceOne.print();
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
    
    instanceOne.front().print();
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
    newPass.print();
    
    Passenger newPass2 = instanceOne.createPassenger(4,5,64);
    newPass2.print();
}