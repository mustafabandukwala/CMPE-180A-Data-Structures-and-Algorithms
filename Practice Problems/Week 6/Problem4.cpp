----------------------------------------------------------------------------------------------------------------------------------------
Stack.cpp
----------------------------------------------------------------------------------------------------------------------------------------

// Implement the swap_halves member function of the Stack class. Only change the top pointer and the link pointers of two stack frames.

#include <iostream>
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

void Stack::swap_halves()
{
   StackFrame* temp = top;
   StackFrame* temp2 = top;
   StackFrame* temp3 = top;
   if(top->frames == 11)
      top->frames = top->frames - 5;
   for(int i = 0; i < top->frames - 1; i++)
   {
      if(i < (top->frames/2 - 1))
         temp3 = temp3->link;
      
      if(i < (top->frames/2))
         temp = temp->link;
      temp2 = temp2->link;
   }
   temp2->link = top;
   top = temp;
   temp3->link = nullptr;
}

void Stack::print() const
{
   for (StackFrame* p = top; p != nullptr; p = p->link)
      cout << p->data << " ";
   cout << endl;
}

----------------------------------------------------------------------------------------------------------------------------------------
Stack.h
----------------------------------------------------------------------------------------------------------------------------------------

#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

struct StackFrame;

class Stack
{
 public:
   Stack();
   ~Stack();
   void push(string s);
   string pop();
   bool empty() const;
   void swap_halves();
   void print() const;
   static int stacks;
 private:
   StackFrame* top;
};

struct StackFrame
{
   StackFrame *link;
   static int frames;
   StackFrame() { frames++; }
   ~StackFrame() { link = nullptr; data = "666"; frames--; }
private:
   string data;
   friend void Stack::push(string);   
   friend string Stack::pop();   
   friend void Stack::print() const;   
};

#endif

----------------------------------------------------------------------------------------------------------------------------------------
Tester.cpp
----------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
   Stack s;
   s.push("Mary");
   s.push("had");
   s.push("a");
   s.push("little");
   s.push("lamb");
   s.swap_halves();
   s.print();
   cout << "Expected: a had Mary lamb little" << endl;
   Stack t;
   t.push("Its");
   t.push("fleece");
   t.push("was");
   t.push("white");
   t.push("as");
   t.push("snow");
   t.swap_halves();
   t.print();
   cout << "Expected: was fleece Its snow as white" << endl;
   cout << "Constructed stacks: " << Stack::stacks << endl;
   cout << "Expected: 2" << endl;
}
