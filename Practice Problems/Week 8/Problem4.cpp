#include <string>
#include <vector>

using namespace std;

int altSumHelper(vector<int> vec, int result)
{
   if(vec.size() == 0)
      return result;
   else
   {
      if(vec.size() % 2 == 0)
         result = result - vec[vec.size() - 1];
      else
         result = result + vec[vec.size() - 1];
   }
   vec.pop_back();
   return(altSumHelper(vec, result));
}

/*
   Given a vector of integers, return the alternating sum 
   v[0] - v[1] + v[2] - v[3] + ...
   If the vector is empty, the alternating sum is zero.
   Use a recursive helper method. Do not use loops.

*/
int altSum(vector<int> v)
{
   return altSumHelper(v, 0);
}
