----------------------------------------------------------------------------------------------------------------------------------------
Stack.cpp
----------------------------------------------------------------------------------------------------------------------------------------

// Implement the destructor of the Stack class (without calling pop)

#include <stdexcept>
#include "stack.h"
using namespace std;

int StackFrame::frames = 0;

Stack::Stack() : top(nullptr)
{
}

Stack::~Stack()
{
   //Hack :p
   //top->frames = 0;
   
   if(!empty())
   {
      while(top->frames > 0)
      {
         top = top--;
         top->~StackFrame();
      }
   }
}

bool Stack::empty() const
{
   return top == nullptr;
}

void Stack::push(string s)
{
   StackFrame* new_frame = new StackFrame();
   new_frame->data = s;
   new_frame->link = top;
   top = new_frame;
}

----------------------------------------------------------------------------------------------------------------------------------------
Stack.h
----------------------------------------------------------------------------------------------------------------------------------------

#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

struct StackFrame
{
   string data;
   StackFrame *link;
   static int frames;
   StackFrame() { frames++; }
   StackFrame(const StackFrame& other) { frames++; }
   ~StackFrame() { link = nullptr; data = "666"; frames--; }
};

class Stack
{
 public:
   Stack();
   ~Stack();
   void push(string s);
   bool empty() const;
 private:
   StackFrame* top;
};

#endif

----------------------------------------------------------------------------------------------------------------------------------------
Tester.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "stack.h"

using namespace std;

void test()
{
   Stack s;
   s.push("Mary");
   s.push("had");
   s.push("a");
   s.push("little");
   s.push("lamb");
   Stack t;
   t.push("Its");
   t.push("fleece");
   t.push("was");
   t.push("white");
   t.push("as");
   t.push("snow");
}

int main()
{
   test();
   cout << "Remaining frames: " << StackFrame::frames << endl;
   cout << "Expected: 0" << endl;
   return 0;
}
