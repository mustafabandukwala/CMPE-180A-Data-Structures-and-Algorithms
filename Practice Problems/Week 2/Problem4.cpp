#include <string>
using namespace std;


/**
   Return a string that mixes the characters in the string a 
   with the characters in b reversed. For example,
   intertwine("Fred", "Mary") yields "FyrreadM".

   If one string is longer than the other, append the unused
   characters (in reverse order if the second string is longer).
   intertwine("Sue", "Peggy") yields "SyugegeP".
*/
string intertwine(string a, string b)
{
	int m = a.length();
	int n = b.length();
	int max;
	string cat;

	if (m > n)
	{
		max = n;
		for (int i = 0; i < max ; i++)
		{
			cat += a.at(i);
			cat += b.at(b.length()-1-i);
		}
		for (int i = max ; i < m ; i++)
		{
			cat += a.at(i);
		}
	}
	else if (m == n)
	{
		max = m;
		for (int i = 0; i < max ; i++)
		{
			cat += a.at(i);
			cat += b.at(b.length()-1-i);
		}
	}
	else if (n > m)
		{
			max = m;
			for (int i = 0; i < max ; i++)
			{
				cat += a.at(i);
				cat += b.at(b.length()-1-i);
			}
			for (int i = (b.length() - a.length() - 1) ; i >= 0 ; i--)
			{
				cat += b.at(i);
			}
		}
	return cat;
}
