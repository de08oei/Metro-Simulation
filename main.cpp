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

int main(int argc, char *argv[])
{
	cerr << "Hey" << endl;
	PassengerQueue instanceOne;
	instanceOne.size();
	Passenger *newPass = instanceOne.createPassenger(1,2,3);
	//instanceOne.enqueue(*newPass);
	//test_createPassenger();
	return 0;
}

void test_createPassenger()
{
	PassengerQueue instanceTwo;
	Passenger *newOne = instanceTwo.createPassenger(1, 2, 3);
	cerr << "id is " << newOne->id;
}
