/***************************************************************************
 * Name        : DataSorted.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to DataSorted
 ***************************************************************************/

#include "DataSorted.h"

DataSorted::DataSorted() : DataGenerator("Already sorted")
{

}

DataSorted::~DataSorted()
{

}

void DataSorted::generate_data(vector<Element>& data, const int size)
{
	for(int i=0; i<size; i++)
		data.push_back(Element(i));
}
