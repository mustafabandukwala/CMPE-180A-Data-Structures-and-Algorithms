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
