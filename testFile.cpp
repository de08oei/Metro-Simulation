/*
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"
#include "PassengerQueue.h"

using namespace std;

//Testing functions 
void test_createPassenger();
void test_enque();

int main(int argc, char *argv[])
{
	cerr << "Hey" << endl;
	test_enque();
	// PassengerQueue instanceOne;
	// instanceOne.size();
	// Passenger newPass = instanceOne.createPassenger(1,2,3);
	// instanceOne.enqueue(newPass);
	//cout << "instance 1 id is: " << instanceOne.front().id << endl;
	//test_createPassenger();
	//instanceOne.print();
	return 0;
}

/*
Passenger front();
void dequeue();
void enqueue(const Passenger& passenger); //takes in an address to passenger
int size();
void print();
*/

void test_enque()
{
    cout << "There should be 2 passengers. [1, 2->3] [2, 3->4]" << endl;
	PassengerQueue instanceOne;
	Passenger newPass = instanceOne.createPassenger(1,2,3);
	instanceOne.enqueue(newPass);
	Passenger newPass2 = instanceOne.createPassenger(2,3,4);
	instanceOne.enqueue(newPass2);
	instanceOne.print();
}

void test_createPassenger()
{
	PassengerQueue instanceTwo;
	Passenger newOne = instanceTwo.createPassenger(1, 2, 3);
	cerr << "id is " << newOne.id;
}