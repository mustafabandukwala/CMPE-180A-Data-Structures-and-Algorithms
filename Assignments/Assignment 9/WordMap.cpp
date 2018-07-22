/***************************************************************************************
 * Name        : WordMap.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Map functionality
 ***************************************************************************************/

#include <map>
#include <string>
#include <iostream>
#include "WordMap.h"

using namespace std;

WordMap::WordMap() {}

WordMap::~WordMap() {}

int WordMap::size()
{
	return wordMap.size();
}

void WordMap::insert(const string text)
{
    steady_clock::time_point start_time = steady_clock::now();

	if(wordMap.find(text) == wordMap.end())
	{
		pair<string, Word> toInsert(text, Word(text));
        wordMap.insert(toInsert);
	}
	else
	{
		wordMap.at(text).increment_count();
	}

    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time, end_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();

	map<string, Word>::iterator it;
	it = wordMap.find(text);

    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time, end_time);

    return it;
}
