/***************************************************************************
 * Name        : DataRandom.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to DataRandom
 ***************************************************************************/

#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"

DataRandom::DataRandom() : DataGenerator("Unsorted random")
{

}

DataRandom::~DataRandom()
{

}

void DataRandom::generate_data(vector<Element>& data, int size)
{
    data.clear();

    if (random_data.size() == size)
    {
        data = random_data;
    }
    else
    {
        random_data.clear();
        srand(time(NULL));

        for (int i=0; i<size; i++)
        {
            Element element(rand()%size);
            random_data.push_back(element);
            data.push_back(element);
        }
    }
}
