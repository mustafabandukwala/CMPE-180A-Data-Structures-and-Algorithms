#include <iostream>

using namespace std;

/**
   Duplicate the beginning and the end of the given array
   numbers. You are given the number of elements of the array.

   For example, 1 2 4 8 should turn into 1 1 2 4 8 8.

   Allocate a new array and place all numbers into it (that is,
   the duplicates at the beginning and the end, and all numbers
   in between). 

   If the array is empty, return an array holding two zeroes.

   Use the C++ style new operator.

   Return a pointer to the new array. Do not modify the original array.
*/

int* dupefirstlast(int numbers[], int size)
{
   int* result = new int[size + 2];
   int i = 0, index = 0;
   //Copy the first element
   if(size > 0)
      result[index++] = numbers[0];
   //Copy the remaining elements
   for(i = 0; i < size; i++)
   {
      result[index] = numbers[i];
      index++;
   }
   //Copy the last element again
   if(size > 0)
      result[index] = numbers[i-1];
   return result;
}
   
void print_array(int a[], int n)
{
   if (n == 0) { cout << "{}" << endl; return; }
   cout << "{ ";
   for (int i = 0; i < n; i++)
   {
      if (i > 0) cout << ", ";
      cout << a[i];
   }
   cout << " }" << endl;
}

int main()
{
   int a[] = { 1, 4, 9, 16, 25, 36, 49, 64};
   int* b = dupefirstlast(a, 8);
   print_array(b, 10);
   cout << "Expected: { 1, 1, 4, 9, 16, 25, 36, 49, 64, 64 }" << endl;
   delete[] b;

   int* c = dupefirstlast(a, 3);
   print_array(c, 5);
   cout << "Expected: { 1, 1, 4, 9, 9 }" << endl;
   delete[] c;

   int* d = dupefirstlast(a, 5);
   print_array(d, 7);
   cout << "Expected: { 1, 1, 4, 9, 16, 25, 25 }" << endl;
   delete[] d;

   int* e = dupefirstlast(a, 0);
   print_array(e, 2);
   cout << "Expected: { 0, 0 }" << endl;
   delete[] e;
   
   int* f = dupefirstlast(a, 1);
   print_array(f, 3);
   cout << "Expected: { 1, 1, 1 }" << endl;
   delete[] f;
	
   return 0;
}
