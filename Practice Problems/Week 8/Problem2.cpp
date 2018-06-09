#include <string>

using namespace std;

/**
   Shuffle two strings by alternating characters from them. If one string
   runs out before the other, just pick from the longer one.
   For example, shuffle("Fred", "Wilma") is "FWrieldma". 
   Use recursion. Do not use loops.
   Hint: str.substr(1) is the substring of str from position 1 to
   the end.
*/
string shuffle(string a, string b)
{
   string result = "";
   bool aTrue = false, bTrue = false;
   if(a.length() == 0 && b.length() == 0)
      return "";
   if(a.length() > 0)
   {
      result = result + a[0];
      aTrue = true;
   }
   if(b.length() > 0)
   {
      result = result + b[0];
      bTrue = true;
   }
   if(aTrue && bTrue)
      return result + shuffle(a.substr(1), b.substr(1));
   else if(aTrue && !bTrue)
      return result + shuffle(a.substr(1), "");
   else if(!aTrue && bTrue)
      return result + shuffle("", b.substr(1));
   else
      return result;
}
