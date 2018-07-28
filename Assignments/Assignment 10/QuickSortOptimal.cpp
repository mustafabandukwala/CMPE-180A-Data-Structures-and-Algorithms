/*********************************************************************************
 * Name        : QuickSortOptimal.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to QuickSortOptimal
 *********************************************************************************/

#include "QuickSortOptimal.h"

QuickSortOptimal::QuickSortOptimal() : QuickSorter("Quicksort optimal")
{

}

QuickSortOptimal::~QuickSortOptimal()
{

}

Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{
   int mid = (left+right)/2;

   compare_count++;
   if ( data[mid] < data[left] )
      swap(left,mid);

   compare_count++;
   if ( data[right] < data[left] )
      swap(left,right);

   compare_count++;
   if ( data[right] < data[mid] )
      swap(mid,right);

   swap(left,mid);

   return data[left];
}
