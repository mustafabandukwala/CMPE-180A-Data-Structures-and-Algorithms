#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
  You are given two time intervals with given start and end.
  Compute the number of seconds in their overlap, or 0 if the
  time intervals don't overlap.
*/
int seconds_in_overlap(steady_clock::time_point start1,
   steady_clock::time_point end1,
   steady_clock::time_point start2,
   steady_clock::time_point end2)
  {
    bool flag1 = false, flag2 = false;
    int timeDifference=0;


    //start2 lies between start1 and end1
    //OR
    //end1 lies between start2 and end2
    if(start2 >= start1 && start2 <= end1 && end1 <= end2)
    {
       timeDifference = duration_cast<seconds>(end1 - start2).count();
    }

    //start1 lies between start2 and end2
    //OR
    //end2 lies between start1 and end1
    if(start1 >= start2 && start1 <= end2 && end2 <= end1)
    {
       timeDifference = duration_cast<seconds>(end2 - start1).count();
    }

    //start1 and end1 lies between start2 and end2
    if(start1 >= start2 && start1 <= end2 && end1 <= end2)
    {
       timeDifference = duration_cast<seconds>(end1 - start1).count();
    }

    //start2 and end2 lies between start1 and end1
    if(start2 >= start1 && start2 <= end1 && end1 >= end2)
    {
       timeDifference = duration_cast<seconds>(end2 - start2).count();
    }

    return timeDifference;
}

int main()
{
   steady_clock::time_point now = steady_clock::now();
   steady_clock::time_point later1 = now + std::chrono::seconds(4);
   steady_clock::time_point later2 = now + std::chrono::seconds(10);
   steady_clock::time_point later3 = now + std::chrono::seconds(20);
   steady_clock::time_point earlier = now + std::chrono::seconds(-10);
   cout << seconds_in_overlap(now, later2, earlier, later1) << endl;
   cout << "Expected: 4" << endl;
   cout << seconds_in_overlap(earlier, later1, now, later2) << endl;
   cout << "Expected: 4" << endl;
   cout << seconds_in_overlap(earlier, now, later1, later2) << endl;
   cout << "Expected: 0" << endl;
   cout << seconds_in_overlap(later1, later2, earlier, now) << endl;
   cout << "Expected: 0" << endl;
   cout << seconds_in_overlap(earlier, later2, now, later1) << endl;
   cout << "Expected: 4" << endl;      
   cout << seconds_in_overlap(later1, later2, earlier, later3) << endl;
   cout << "Expected: 6" << endl;
   cout << seconds_in_overlap(now, later1, later2, later3) << endl;
   cout << "Expected: 0" << endl;
   cout << seconds_in_overlap(now, later2, now, later3) << endl;
   cout << "Expected: 10" << endl;
   cout << seconds_in_overlap(now, later3, now, later3) << endl;
   cout << "Expected: 20" << endl;   
   cout << seconds_in_overlap(earlier, later3, now, later2) << endl;
   cout << "Expected: 10" << endl;   
}
