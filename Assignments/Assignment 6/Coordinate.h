/***************************************************************************
 * Name        : Coordinate.h
 * Version     : 1.0
 * Description : File which contains various functions related to Coordinate
 ***************************************************************************/

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
public:

	// Setter for latitude
	void set_latitude(double);
	// Setter for longitude
	void set_longitude(double);
	// Getter for latitude
	double get_latitude();
	// Getter for longitude
	double get_longitude();

    // Overloaded input stream extraction operator.
    friend istream& operator >>(istream& ins, Coordinate& coordinate);

    // Constants for this app's input data.
    static const double MAX_LATITUDE;
    static const double MIN_LONGITUDE;

private:
    double latitude;
    double longitude;
};

#endif /* COORDINATE_H_ */
