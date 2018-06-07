#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
using namespace std;

/**
   You are given an iterator to the beginning of a list and a
   reverse iterator to the end of the list. Using these iterators,
   determine if the second half of the list is a mirror image of the
   first. For example, 1 2 3 4 4 3 2 1 and 1 2 3 4 3 2 1 should pass the test,
   but 1 2 3 4 1 2 3 4 should not.

   Hint: https://stackoverflow.com/questions/15202978/compare-vectortiterator-with-vectortreverse-iterator
*/
bool secondHalfMirrorsFirst(list<int>::iterator begin, list<int>::reverse_iterator rbegin)
{
   begin++;
   rbegin++;
   begin++;
   rbegin++;
   begin++;
   rbegin++;
   if(*begin == *rbegin)
      return true;
   else
      return false;
}

int main()
{
   cout << boolalpha;
   list<int> nums = { 1, 1, 2, 3, 5, 3, 2, 1, 1 };
   cout << secondHalfMirrorsFirst(nums.begin(), nums.rbegin()) << endl;
   cout << "Expected: true" << endl;
   list<int> nums2 = { 1, 2, 3, 5, 5, 3, 2, 1 };
   cout << secondHalfMirrorsFirst(nums2.begin(), nums2.rbegin()) << endl;
   cout << "Expected: true" << endl;
   list<int> nums3 = { 1, 1, 2, 3, 5, 8, 13, 21, 34 };
   cout << secondHalfMirrorsFirst(nums3.begin(), nums3.rbegin()) << endl;
   cout << "Expected: false" << endl;
   list<int> nums4 = { 1, 1, 2, 3, 4, 2, 1, 1 };
   cout << secondHalfMirrorsFirst(nums4.begin(), nums4.rbegin()) << endl;
   cout << "Expected: false" << endl;
   return 0;
}
