/*
 *
 */
#include "Passenger.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * Remember to write a complete function contract here!
 */
void Passenger::print()
{
        cout << "[" << id << ", " << from << "->" << to << "]" << endl;
}
