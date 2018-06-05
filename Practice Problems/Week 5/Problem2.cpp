----------------------------------------------------------------------------------------------------------------------------------------
Path.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include "path.h"
/*
  Provide a function backtrack that, given a path, produces and prints 
  a path that starts like the given path and then goes back to 
  the beginning. For example, when given the path (1,2)->(3,4)->(5,6)
  you should produce and print (1,2)->(3,4)->(5,6)->(3,4)->(1,2).

  DO NOT COPY the Path parameter into the function. Use a reference 
  parameter.

  DO NOT COPY Point objects. Note that Point::at(int) returns a 
  reference, and Point::add(Point&) receives a reference. 

  The Point class is instrumented to print messages for all copies.
*/

void backtrack(Path &p)
{
  for (int i = p.length() - 2; i >= 0; i--)
  {
    p.add(p.at(i));
  }
  p.add(p.at(i));
}

----------------------------------------------------------------------------------------------------------------------------------------
Path.h
----------------------------------------------------------------------------------------------------------------------------------------

#ifndef PATH_H
#define PATH_H
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
      Creates an empty path.
   */
   Path();      
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
#endif

----------------------------------------------------------------------------------------------------------------------------------------
Point.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include "point.h"

Point::Point() { _x = 0; _y = 0; }
Point::Point(int x, int y) { _x = x; _y = y; }
int Point::x() const { return _x; }
int Point::y() const { return _y; }

Point::Point(const Point& other)
{
   cout << "Copying (" << other.x() << "," << other.y() << ")" << endl;
   _x = other._x;
   _y = other._y;
}

Point& Point::operator=(const Point& other)
{
   cout << "Assigning (" << other.x() << "," << other.y() << ") to (" << x() << "," << y() << ")" << endl;
   _x = other._x;
   _y = other._y;
}

Point::~Point()
{
   cout << "Destroying (" << x() << "," << y() << ")" << endl;
}

----------------------------------------------------------------------------------------------------------------------------------------
Point.h
----------------------------------------------------------------------------------------------------------------------------------------

#ifndef POINT_H
#define POINT_H

class Point
{
public:
   Point();
   Point(int x, int y);
   Point(const Point& other);
   Point& operator=(const Point& other);
   ~Point();
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
#include "prog.h"

int main()
{
   cout << "Adding to p1" << endl;
   Path p1;
   p1.add(1, 2);
   p1.add(2, 6);
   p1.add(3, 8);
   p1.add(4, 3);
   p1.add(5, 0);
   p1.add(6, -1);
   cout << "Calling backtrack(p1)" << endl;
   backtrack(p1);

   cout << "Adding to p2" << endl;
   Path p2;
   p2.add(3, 4);
   p2.add(5, 6);
   p2.add(7, 8);
   cout << "Calling backtrack(p2)" << endl;
   backtrack(p2);
   cout << "All done" << endl;
   
   return 0;
}
