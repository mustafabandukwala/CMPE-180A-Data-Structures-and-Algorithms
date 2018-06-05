----------------------------------------------------------------------------------------------------------------------------------------
Path.cpp
----------------------------------------------------------------------------------------------------------------------------------------

/**
   The eagle-eyed among you will have noticed that in the preceding
   exercise many points were constructed, and few were destroyed.
   Fix that by providing a destructor forr the Path class. You will 
   also need to provide the constructor and add method again since 
   we don't want to give away the solution to the preceding problem.
*/
#include "path.h"

Path::Path(int n)
{
	_capacity = n;
	_points = new Point[n];
}

Path::~Path()
{
   delete [] _points;
}

/*
  Produce a class Path that represents a path of points.
  Use a vector to store Point objects.
*/
void Path::add(int x, int y)
{
	if(_length < _capacity)
	{
	   vector<Point*> addPoint;
	   addPoint.push_back(new Point(x, y));
	   _points[_length++] = *addPoint[0];
	   delete addPoint[0];
	}
}

Point& Path::at(int index)
{  
   return _points[index];  
}

int Path::length()
{  
   return _length;  
}

void Path::print()
{
   for (int i = 0; i < length(); i++)
   {
      if (i > 0) cout << "->";
      Point& p = at(i);
      cout << "(" << p.x() << "," << p.y() << ")";
   }
   cout << endl;
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
      Creates a path with up to n points.
   */
   Path(int n);      
   /**
      Destroys this pathh.
   */
   ~Path();      
   /**
      Adds the given point to the end of this path if there is space.
   */
   void add(int x, int y);
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
   Point* _points;
   int _capacity;
   int _length;
};
#endif

----------------------------------------------------------------------------------------------------------------------------------------
Point.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;
#include "point.h"

Point::Point()
{
   _x = 0; _y = 0;
   cout << "Constructing (" << _x << ", " << _y << ")" << endl;
}

Point::Point(int x, int y)
{
   _x = x; _y = y;
   cout << "Constructing (" << _x << ", " << _y << ")" << endl;
}

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

int main()
{
   cout << "Adding to p1" << endl;
   Path p1(8);
   p1.add(1, 2);
   p1.add(2, 6);
   p1.add(3, 8);
   p1.add(4, 3);
   p1.add(5, 0);
   p1.add(6, -1);
   p1.print();
   cout << "Adding to p2" << endl;
   Path p2(2);
   p2.add(3, 4);
   p2.add(5, 6);
   p2.add(7, 8);
   p2.print();
   cout << "All done" << endl;
   
   return 0;
}
