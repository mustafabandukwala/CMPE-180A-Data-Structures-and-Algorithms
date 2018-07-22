/******************************************************************************
 * Name        : DataGenerator.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to DataGenerator
 ******************************************************************************/

#include <string>
#include <vector>
#include "DataGenerator.h"

DataGenerator::DataGenerator(string name) : name(name)
{}

DataGenerator::~DataGenerator()
{}

string DataGenerator::get_name()
{
	return name;
}
