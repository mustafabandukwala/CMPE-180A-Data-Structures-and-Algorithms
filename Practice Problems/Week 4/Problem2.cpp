/*
A vacuum bug lives in a rectangular region of width w and height h, at an integer position (x, y), 0 ≤ x < w and 0 ≤ y < h. It wants to
clean the entire region. It starts at (0, 0), traverses the row (x, 0) where x goes from 0 to w - 1. Then it traverses the row above, 
but backwards, going from (w - 1, 1) to (0, 1). Then it traverses the next row forward. Each call to move moves the vacuum bug one
step in this journey. When the bug reaches the final position in the topmost row, a call to move has no further effect.
*/

---------------------------------------------------------------------------------------------------------------------------------------
VacuumBug.cpp
---------------------------------------------------------------------------------------------------------------------------------------

#include "VacuumBug.h"

VacuumBug::VacuumBug(int region_width, int region_height)
{
   regionWidth = region_width;
   regionHeight = region_height;
   x = 0;
   y = 0;
   counter=0;
   right = true;
   left = false;
   up = false;
}

void VacuumBug::move()
{
	if(counter < ((regionHeight*regionWidth)-1))
	{
	   counter++;
		if(y % 2 == 0)
		{
			if(x < regionWidth)
				x++;
			if(x == regionWidth)
			{
				y++;
				x--;
			}
		}
		else
		{
			if(x >= 0)
				x--;
			if(x == -1)
			{
				y++;
				x++;
			}
		}
	}
}

int VacuumBug::get_x() const
{
  return x;
}

int VacuumBug::get_y() const
{
  return y;
}

---------------------------------------------------------------------------------------------------------------------------------------
VacuumBug.h
---------------------------------------------------------------------------------------------------------------------------------------

#ifndef VACUUM_BUG
#define VACUUM_BUG

class VacuumBug
{
 private:
   int regionWidth, regionHeight, x, y, counter;
   bool right, left, up;
 public:
   VacuumBug(int region_width, int region_height);
   void move();
   int get_x() const;
   int get_y() const;
};

#endif

---------------------------------------------------------------------------------------------------------------------------------------
Tester.cpp
---------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include "VacuumBug.h"

using namespace std;

int main()
{
   int width;
   int height;
   int moves;   
   cin >> width >> height >> moves;
   
   vector<vector<char>> region;
   for (int y = 0; y < height; y++)
   {
      region.push_back(vector<char>());
      for (int x = 0; x < width; x++)
         region[y].push_back(' ');
   }
   VacuumBug b(width, height);
   region[0][0] = '0';
   for (int move = 1; move <= moves; move++)
   {
      b.move();
      region[b.get_y()][b.get_x()] = '0' + (move % 10);
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;
   for (int y = height - 1; y >= 0; y--)
   {
      cout << "|";
      for (int x = 0; x < width; x++)
      {
         cout << region[y][x];
      }
      cout << "|" << endl;
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;
}
