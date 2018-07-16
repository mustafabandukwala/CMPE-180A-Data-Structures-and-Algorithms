/*********************************************************************
 * Name        : City.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to city
 *********************************************************************/

#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:

	// Getter for name
	string get_name();
	// Getter for state
	string get_state();
	// Setter for name
	void set_name(string);
	// Setter for state
	void set_state(string);
	// Getter for Coordinate
	Coordinate& get_coordinate();
	// Setter for Coordinate
	void set_coordinate(Coordinate);

    // Overloaded stream I/O operators.
    friend ostream& operator <<(ostream& outs, const City& city);
    friend istream& operator >>(istream& ins, City& city);

private:
    string name;
    string state;
    Coordinate coordinate;
};

#endif /* CITY_H_ */
