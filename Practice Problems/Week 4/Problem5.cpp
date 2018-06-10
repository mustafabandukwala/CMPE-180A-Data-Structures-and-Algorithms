/*
A LoveBug (google it if you dare) can occupy any floating-point coordinates (x, y). Its initial position is given in the constructor.
Its move member function has another LoveBug as a parameter. If it is closer than 0.1 to that love bug, this love bug's happiness goes
up by 1. Otherwise, it

Moves itself halfway towards the position of the other love bug
Asks the other love bug to move it closer to this one. (Hint: *this). Yes, this will cause this bug recursively to move closer again.
Love is like that.
“Mathematicians are like lovers… Grant a mathematician the least principle, and he will draw from it a consequence which you must
grant him also, and from this consequence another.”—Bernard Le Bovier de Fontenelle
However, no love bug loves itself. If the move method is called with the same bug as parameter, it does nothing.
*/

----------------------------------------------------------------------------------------------------------------------------------------
LoveBug.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <cmath>
#include "LoveBug.h"

using namespace std;

LoveBug::LoveBug(double x, double y)
{
   X = x;
   Y = y;
   happiness = false;
}

void LoveBug::move(LoveBug& other)
{
   if(X != other.X && Y != other.Y)
   {
      double dist = 0;
      dist = distance(other);
      if(dist > 0.1)
      {
         X = abs(X + other.X)/2;
         Y = abs(Y + other.Y)/2;
         other.move(*this);
      }
      if(dist < 0.1)
         happiness = true;
   }
}

double LoveBug::get_x() const
{
  return x;
}

double LoveBug::get_y() const
{
  return y;
}

double LoveBug::distance(const LoveBug& other) const
{
   double dx = get_x() - other.get_x();
   double dy = get_y() - other.get_y();
   return sqrt(dx * dx + dy * dy);
}

int LoveBug::get_happiness() const
{
   if(happiness)
      return 1;
   else
      return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------
LoveBug.h
----------------------------------------------------------------------------------------------------------------------------------------

#ifndef LOVE_BUG
#define LOVE_BUG

class LoveBug
{
 private:
   double X, Y;
   bool happiness;
 public:
   LoveBug(double x, double y);
   void move(LoveBug& other);
   double distance(const LoveBug& other) const;
   double get_x() const;
   double get_y() const;
   int get_happiness() const;
};

#endif

----------------------------------------------------------------------------------------------------------------------------------------
Tester.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "LoveBug.h"

using namespace std;

int main()
{
   LoveBug harry(0, 0);
   LoveBug sally(0.05, 0.05);
   harry.move(sally);
   cout << harry.get_happiness() << endl;
   cout << "Expected: 1" << endl;
   cout << sally.get_happiness() << endl;
   cout << "Expected: 0" << endl;
   cout << "(" << harry.get_x() << "," << harry.get_y() << ")" << endl;
   cout << "Expected: (0,0)" << endl;
   cout << "(" << sally.get_x() << "," << sally.get_y() << ")" << endl;
   cout << "Expected: (0.05,0.05)" << endl;

   LoveBug romeo(0, 0);
   LoveBug juliet(10, 10);
   juliet.move(romeo);
   cout << juliet.get_happiness() << endl;
   cout << "Expected: 1" << endl;
   cout << romeo.get_happiness() << endl;
   cout << "Expected: 0" << endl;
   cout << "(" << juliet.get_x() << "," << romeo.get_y() << ")" << endl;
   cout << "Expected: (3.35938,3.32031)" << endl;
   cout << "(" << romeo.get_x() << "," << romeo.get_y() << ")" << endl;
   cout << "Expected: (3.32031,3.32031)" << endl;

   LoveBug narcissus(5, 5);
   narcissus.move(narcissus);
   cout << narcissus.get_happiness() << endl;
   cout << "Expected: 0" << endl;
   cout << "(" << narcissus.get_x() << "," << narcissus.get_y() << ")" << endl;
   cout << "Expected: (5,5)" << endl;
}
