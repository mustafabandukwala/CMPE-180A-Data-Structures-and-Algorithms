/*************************************************************************************
 * Name        : WordVector.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Vector functionality
 *************************************************************************************/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include "WordVector.h"

using namespace std;

WordVector::WordVector() {}

WordVector::~WordVector() {}

int WordVector::size()
{
	return wordVector.size();
}

void WordVector::insert(const string text)
{

    steady_clock::time_point start_time = steady_clock::now();

	int found = find(text, 0, wordVector.size()-1);
	if(found >= 0)
	{
		vector<Word>::iterator it = wordVector.begin();
		advance(it, found);
		it->increment_count();
	}
	else
	{
        found *= -1;
        wordVector.insert(wordVector.begin()+found-1, Word(text));
	}

    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time, end_time);
}

vector<Word>::iterator WordVector::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();

	int found = find(text, 0, wordVector.size()-1);
	vector<Word>::iterator it;
	if(found >= 0)
	{
		it = wordVector.begin();
		advance(it, found);
	}

    steady_clock::time_point end_time = steady_clock::now();
    this->increment_elapsed_time(start_time, end_time);

    return it;
}

int WordVector::find(const string text, int low, int high) const
{
	int mid;
	bool found = false;
	while(low <= high && !found)
	{
		mid = (low + high) /2;
		if (wordVector[mid].get_text() == text)
			found = true;
		else if (wordVector[mid].get_text() > text)
			high = mid-1;
		else
			low = mid + 1;
	}
	if (found)
		return mid;
	return -(low+1);
}

Word& WordVector::operator[](const int index)
{
	return wordVector.at(index);
}
