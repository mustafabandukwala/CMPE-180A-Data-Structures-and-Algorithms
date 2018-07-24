/**********************************************************************************
 * Name        : DataReverseSorted.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to DataReverseSorted
 **********************************************************************************/

#include "DataReverseSorted.h"

DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted")
{

}

DataReverseSorted::~DataReverseSorted()
{

}


void DataReverseSorted::generate_data(vector<Element>& data, const int size)
{
	for (int i = 0; i < size; i++)
		data.push_back(Element(size-i));
}
