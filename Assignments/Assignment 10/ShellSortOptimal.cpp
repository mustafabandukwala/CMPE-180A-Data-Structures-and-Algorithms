/*********************************************************************************
 * Name        : ShellSortOptimal.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to ShellSortOptimal
 *********************************************************************************/

#include "ShellSortOptimal.h"

ShellSortOptimal::ShellSortOptimal() :VectorSorter("Shellsort optimal")
{

}

ShellSortOptimal::~ShellSortOptimal()
{

}

/*
 * Reference: ftp://ftp.cs.princeton.edu/pub/cs226/linksort/shellsort.c
 */
void ShellSortOptimal::run_sort_algorithm()
{
   int h = 1; //shellsort increment
   int done; //flag to stop pass early if no exchanges

   // determine the initial increment sequence h
   for (h = 1; h <= data.size() / 3; h = 3*h + 1);

   while (h >= 1)
   {
      done = 0;
      while (done != 1)
      {
         done = 1;
         for (int i = data.size() - 1; i >= h; i--)
         {
            compare_count++;
            if (data[i] < data[i-h])
            {
               swap(i,i-h);
               done = 0;
            }
         }
      }
      h /= 3;
   }
}
