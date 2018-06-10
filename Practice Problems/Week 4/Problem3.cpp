/*
A bug lives in a box of width w and height h, at an integer position (x, y), 0 ≤ x < w and 0 ≤ y < h. In each move, it moves diagonally
until it hits one of the walls or a corner. If it hits a wall, its direction is reflected. If it hits a corner, it turns around. When
constructed with a given position, the bug initially moves towards increasing x- and y-positions.

Here is a trace of a bug in a box of width 10 and height 3 when move is called 5 times.

+----------+
|      1 5 |
|     0 2 4|
|        3 |
+----------+
*/

-----------------------------------------------------------------------------------------------------------------------------------------
BoxBug.cpp
-----------------------------------------------------------------------------------------------------------------------------------------

#include "BoxBug.h"

BoxBug::BoxBug(int initial_x, int initial_y, int box_width, int box_height)
{
	x = initial_x;
	y = initial_y;
	boxWidth = box_width;
	boxHeight = box_height;
	height = true;
	width = true;
}

void BoxBug::move()
{
	if(height && width)
	{
		x++;
		y++;
		if(x == (boxWidth-1) && y == (boxHeight-1))
		{
			height = false;
			width = false;
		}
		else if(x == (boxWidth-1) && y != (boxHeight-1))
		{
			height = true;
			width = false;
		}
		else if(x != (boxWidth-1) && y == (boxHeight-1))
		{
			height = false;
			width = true;
		}
	}
	else if(!height && width)
	{
		x++;
		y--;
		if(x == (boxWidth-1) && y == 0)
		{
			height = true;
			width = false;
		}
		else if(x == (boxWidth-1) && y != 0)
		{
			height = false;
			width = false;
		}
		else if(x != (boxWidth-1) && y == 0)
		{
			height = true;
			width = true;
		}
	}
	else if(!height && !width)
	{
		x--;
		y--;
		if(x == 0 && y == 0)
		{
			height = true;
			width = true;
		}
		else if(x != (boxWidth-1) && y == 0)
		{
			height = true;
			width = false;
		}
		else if(x == (boxWidth-1) && y != 0)
		{
			height = false;
			width = true;
		}
	}
	else if(height && !width)
	{
		x--;
		y++;
		if(x == 0 && y == (boxHeight-1))
		{
			height = false;
			width = true;
		}
		else if(x == 0 && y != (boxHeight-1))
		{
			height = true;
			width = true;
		}
		else if(x != 0 && y == (boxHeight-1))
		{
			height = false;
			width = false;
		}
	}
}

int BoxBug::get_x() const
{
  return x;
}

int BoxBug::get_y() const
{
  return y;
}

-----------------------------------------------------------------------------------------------------------------------------------------
BoxBug.h
-----------------------------------------------------------------------------------------------------------------------------------------

#ifndef BOX_BUG
#define BOX_BUG

class BoxBug
{
 private:
   int x, y, boxWidth, boxHeight;
   bool width, height; 
 public:
   BoxBug(int initial_x, int initial_y, int box_width, int box_height);
   void move();
   int get_x() const;
   int get_y() const;
};

#endif

-----------------------------------------------------------------------------------------------------------------------------------------
Tester.cpp
-----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include "BoxBug.h"

using namespace std;

int main()
{
   int width;
   int height;
   int initial_x;
   int initial_y;
   int moves;   
   cin >> width >> height >> initial_x >> initial_y >> moves;
   
   vector<vector<char>> box;
   for (int y = 0; y < height; y++)
   {
      box.push_back(vector<char>());
      for (int x = 0; x < width; x++)
         box[y].push_back(' ');
   }
   BoxBug b(initial_x, initial_y, width, height);
   box[initial_y][initial_x] = '0';
   for (int move = 1; move <= moves; move++)
   {
      b.move();
      box[b.get_y()][b.get_x()] = '0' + (move % 10);
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;
   for (int y = height - 1; y >= 0; y--)
   {
      cout << "|";
      for (int x = 0; x < width; x++)
      {
         cout << box[y][x];
      }
      cout << "|" << endl;
   }
   cout << '+';
   for (int x = 0; x < width; x++) cout << '-';
   cout << '+' << endl;
}
