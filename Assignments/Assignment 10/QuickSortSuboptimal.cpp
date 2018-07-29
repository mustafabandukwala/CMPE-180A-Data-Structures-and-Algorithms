/************************************************************************************
 * Name        : QuickSortSuboptimal.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to QuickSortSuboptimal
 ************************************************************************************/

#include "QuickSortSuboptimal.h"

QuickSortSuboptimal::QuickSortSuboptimal() : QuickSorter("Quicksort suboptimal")
{

}

QuickSortSuboptimal::~QuickSortSuboptimal()
{

}
Element& QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right)
{
   return data[left];
}
