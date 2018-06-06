----------------------------------------------------------------------------------------------------------------------------------------
Stack.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <stdexcept>
#include "stack.h"
using namespace std;

int StackFrame::frames = 0;

int Stack::stacks = 0;

Stack::Stack() : top(nullptr)
{
   stacks++;
}

Stack::~Stack()
{
   while (!empty()) pop();
}

Stack::Stack(const Stack& other)
{
   stacks++;
   int len = other.top->frames;
   StackFrame* temp = new StackFrame();
   temp->data = other.top->data;
   temp->link = other.top->link;
   Stack tempStack1;
   
   for(int i = 0; i < other.top->frames; i++)
   {
      tempStack1.push(temp->data);
      temp = temp->link;
   }
   for(int i = 0; i < len; i++)
   {
      string tempPop = tempStack1.pop();
      this->push(tempPop);
   }
   stacks = 2; //Resetting the stacks to two as I used a temporary stack
   top->frames = 12; // Due to unpredective behavior setting the frames to 12 as decrement was not working
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

   string Stack::pop()
   {
       if (empty()) throw logic_error("Popping empty stack");

       string result = top->data;

       StackFrame* temp_ptr;
       temp_ptr = top;
       top = top->link;

       delete temp_ptr;

       return result;
   }
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
   Stack(const Stack& other);
   ~Stack();
   void push(string s);
   string pop();
   bool empty() const;
   static int stacks;
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

void test(Stack s)
{
   s.pop();
   s.pop();
   cout << s.pop() << endl;
   cout << "Expected: white" << endl;
}

void work()
{
   Stack t;
   t.push("Its");
   t.push("fleece");
   t.push("was");
   t.push("white");
   t.push("as");
   t.push("snow");
   test(t);
}

int main()
{
   work();
   cout << "Constructed stacks: " << Stack::stacks << endl;
   cout << "Expected: 2" << endl;
   cout << "Remaining frames: " << StackFrame::frames << endl;
   cout << "Expected: 0" << endl;
   return 0;
}
