----------------------------------------------------------------------------------------------------------------------------------------
Path.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include "path.h"

/*
  Produce a class Path that represents a path of points.
  Use a vector to store Point objects.
*/

void Path::add(int x, int y)
{
   points.push_back(Point(x, y));
}

void Path::add(const Point& p)
{
   points.push_back(Point(p.x(), p.y()));
}

Point& Path::at(int index)
{
   return points.at(index);
}

int Path::length()
{
   return points.size();
}

void Path::print()
{
   for (int i = 0; i < length(); i++)
   {
      if (i > 0) cout << "->";
      cout << "(" << at(i).x() << "," << at(i).y() << ")";
   }
   cout << endl;
}

----------------------------------------------------------------------------------------------------------------------------------------
Path.h
----------------------------------------------------------------------------------------------------------------------------------------

#include <vector>
#include <iostream>

using namespace std;

#include "point.h"

/*
  A Path represents a path of points.
*/
class Path
{
 public:
   /**
      Adds the given point to the end of this path.
   */
   void add(int x, int y);
   /**
      Adds the given point to the end of this path.
   */
   void add(const Point& p);
   /**
      Yields a reference to the point with the given index.
      The index must be >= 0 and < length().
   */
   Point& at(int index);
   /**
      The length of this path.
   */
   int length();
   /**
      Prints this path.
   */
   void print();
 private:
   vector<Point> points;
};

----------------------------------------------------------------------------------------------------------------------------------------
Point.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include "point.h"

Point::Point(int x, int y) { _x = x; _y = y; }
int Point::x() const { return _x; }
int Point::y() const { return _y; }
point.h

#ifndef POINT_H
#define POINT_H

class Point
{
public:
   Point(int x, int y);
   int x() const;
   int y() const;
private:
   int _x;
   int _y;
};

#endif

----------------------------------------------------------------------------------------------------------------------------------------
Tester.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include "path.h"

int main()
{
   Path p1;
   p1.add(3, 4);
   p1.add(5, 6);
   p1.add(7, 8);
   p1.add(4, 3);
   p1.print();
   cout << "Expected: (3,4)->(5,6)->(7,8)->(4,3)" << endl;

   Path p2;
   p2.add(Point(3, 4));
   p2.add(Point(5, 4));
   p2.add(Point(7, 8));
   p2.at(1) = Point(9, 10);
   p2.print();
   cout << "Expected: (3,4)->(9,10)->(7,8)" << endl;
   
   return 0;
}
