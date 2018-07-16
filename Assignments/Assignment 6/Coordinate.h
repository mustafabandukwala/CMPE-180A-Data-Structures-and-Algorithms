/***************************************************************************
 * Name        : Coordinate.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Coordinate
 ***************************************************************************/

#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;

// Getter for latitude
double Coordinate::get_latitude()
{
	return latitude;
}

// Getter for longitude
double Coordinate::get_longitude()
{
	return longitude;
}

// Setter for latitude
void Coordinate::set_latitude(double lat)
{
	latitude = lat;
}

// Setter for longitude
void Coordinate::set_longitude(double lon)
{
	longitude = lon;
}

// Overload operator >>
istream& operator >>(istream& ins, Coordinate& coordinate)
{
	string temp;

	getline(ins, temp, ',');
	coordinate.set_latitude(std::stod(temp));
	getline(ins, temp);
	coordinate.set_longitude(std::stod(temp));
	return ins;
}
