/*********************************************************************
 * Name        : City.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to city
 *********************************************************************/

#include "City.h"

// Getter for name
string City::get_name()
{
	return name;
}

// Getter for state
string City::get_state()
{
	return state;
}

// Setter for name
void City::set_name(string nm)
{
	name = nm;
}

// Setter for state
void City::set_state(string st)
{
	state = st;
}

// Getter for Coordinate
Coordinate& City::get_coordinate()
{
	return coordinate;
}

// Setter for Coordinate
void City::set_coordinate(Coordinate co)
{
	coordinate = co;
}

// Overload operator >>
istream& operator >>(istream& ins, City& city)
{
	string temp;

	getline(ins, temp, ',');
	city.set_name(temp);
	getline(ins, temp, ',');
	city.set_state(temp);
	getline(ins, temp, ',');
	city.coordinate.set_latitude(std::stod(temp));
	getline(ins, temp);
	city.coordinate.set_longitude(std::stod(temp));
  
	return ins;
}
