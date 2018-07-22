/*****************************************************************************
 * Name        : DataAllZeros.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to DataAllZeros
 *****************************************************************************/

#include "DataAllZeros.h"

DataAllZeros::DataAllZeros() : DataGenerator("All zeroes")
{
}

DataAllZeros::~DataAllZeros()
{
}

void DataAllZeros::generate_data(vector<Element>& data, const int size)
{
	for (int i = 0; i < size; i++)
		data.push_back(Element());
}
