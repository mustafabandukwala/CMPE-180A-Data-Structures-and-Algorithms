/******************************************************************************
 * Name        : InsertionSort.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to InsertionSort
 ******************************************************************************/

#include "Sorter.h"
#include "Element.h"
#include "VectorSorter.h"
#include "InsertionSort.h"

InsertionSort::InsertionSort() : VectorSorter("Insertion sort")
{

}

InsertionSort::~InsertionSort()
{

}

/*
 *Reference http://www.sanfoundry.com/cpp-program-sort-array/
 */
void InsertionSort::run_sort_algorithm()
{
   for (int i=1; i<size; i++)
   {
      for (int j = i; j > 0; j--)
      {
         compare_count++;

         if (data[j] < data[j-1])
            swap(j, j-1);
         else
            break;
      }
   }
}
