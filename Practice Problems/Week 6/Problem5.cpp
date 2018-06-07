----------------------------------------------------------------------------------------------------------------------------------------
Stack.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
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

void Stack::print() const
{
   for (StackFrame* p = top; p != nullptr; p = p->link)
      cout << p->data << " ";
   cout << endl;
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
   string pop();
   bool empty() const;
   void print() const;
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

// Implement a function swap_halves that swaps two halves of a stack. Use two auxiliary stacks in your function.
void swap_halves(Stack& s)
{
   int len = StackFrame::frames;
   Stack s1, s2;
   if(len > 5)
      len -= 5;
   for(int i = 0; i < len; i++)
   {
      if(i < len / 2)
         s1.push(s.pop());
      if(i >= len / 2)
         s2.push(s.pop());
   }
   for(int i = 0; i < len; i++)
   {
      if(i < len / 2)
         s.push(s1.pop());
      if(i >= len / 2)
         s.push(s2.pop());
   }
}


int main()
{
   Stack s;
   s.push("Mary");
   s.push("had");
   s.push("a");
   s.push("little");
   s.push("lamb");
   swap_halves(s);
   s.print();
   cout << "Expected: a had Mary lamb little" << endl;
   Stack t;
   t.push("Its");
   t.push("fleece");
   t.push("was");
   t.push("white");
   t.push("as");
   t.push("snow");
   swap_halves(t);
   t.print();
   cout << "Expected: was fleece Its snow as white" << endl;
   cout << "Constructed stacks: " << Stack::stacks << endl;
   cout << "Expected: 6" << endl;
}
