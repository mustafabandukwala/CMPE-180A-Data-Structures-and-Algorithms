#include <string>

using namespace std;

/**
   Return true if the given string contains at least two
   different characters. Use recursion. Do not use loops.   
   Hint: If str[0] is not the same as str[1], you have 
   your answer. Otherwise, look at str.substr(1) (the substring of str
   from position 1 to the end).
*/
bool someDifferent(string str)
{
   if(str.length() == 0)
      return false;
   else if(str[0] != str[1] && str.length() > 1)
      return true;
   else
      return someDifferent(str.substr(1));
}
