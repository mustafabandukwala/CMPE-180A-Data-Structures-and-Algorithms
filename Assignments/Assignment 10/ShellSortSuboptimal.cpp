/************************************************************************************
 * Name        : ShellSortSuboptimal.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to ShellSortSuboptimal
 ************************************************************************************/

#include "Sorter.h"
#include "Element.h"
#include "ShellSortSuboptimal.h"

ShellSortSuboptimal::ShellSortSuboptimal() : VectorSorter("Shellsort suboptimal")
{

}

ShellSortSuboptimal::~ShellSortSuboptimal()
{

}

/*
 * Reference: http://www.sanfoundry.com/cplusplus-program-implement-shell-sort/
 */
void ShellSortSuboptimal::run_sort_algorithm()
{
   // Halving technique
   // h - shellsort increment narrowing the vector size by half
   for (int h = data.size()/2; h >= 1; h /= 2)
   {
      // Do a gapped insertion sort for this gap size.
      // The first gap elements a[0..gap-1] are already in gapped order
      // keep adding one more element until the entire array is gap sorted
      for (int i = h; i < data.size(); i++)
      {
         int j;
         for (j = i; j >= h; j -= h)
         {
            compare_count++;
            if (data[j - h] > data[i])
            {
               data[j] = data[j - h];
               move_count++;
            }
            else
               break;
         }

         data[j] = data[i];
         move_count++;
      }
   }
}
