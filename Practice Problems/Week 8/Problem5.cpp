#include <string>
#include <vector>

using namespace std;

void digitsHelper(string str, string lastValue, vector<string> &result)
{
	if(str.length() > 0)
	{
		if((lastValue[0] >= 48 && lastValue[0] <= 57) || lastValue == "")
		{
			if(str[0] >= 48 && str[0] <= 57)
			{
				lastValue = lastValue + str[0];
			}
			else
			{
				if(lastValue[0] >= 48 && lastValue[0] <= 57)
				{
					result.push_back(lastValue);
				}
				lastValue = "";

			}
			digitsHelper(str.substr(1), lastValue, result);
		}
	}
	if(str.length() == 0)
	{
		if(lastValue[0] >= 48 && lastValue[0] <= 57)
			result.push_back(lastValue);
	}
}

/*
   Given a string, return a vector of all substrings consisting of 
   digits contained in it. For example, if str is "I like 7 and 13",
   return a vector containing "7" and "13".
   Use a recursive helper method. Do not use loops.
   A digit is a character between '0' and '9' inclusive.

*/
vector<string> digitGroups(string str)
{
   vector<string> result;
   digitsHelper(str, "", result);
   return result;
}
