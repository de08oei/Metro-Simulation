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
        // TODO: print the passenger information to cout
        //       as described in the homework specification
        cout << "[" << id << ", " << from << "->" << to << "]" << endl;
}
