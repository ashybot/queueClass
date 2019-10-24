//=========================================================
// Ashley Jacobs
// Complier:  g++
// Queue implementation file queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
  front=0;
  rear=-1;
  count=0;
}

//destructor 
queue::~queue()
{
  front=0;
  rear=-1;
  count=0;
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if (count==0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue:: isFull()
{
  if (count==(MAX_SIZE))
    {
      return true;
    }
  else
    {
      return false;
    }
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue:: add(el_t newElem)
{
  if (isFull()==false)
    {
      rear=(rear + 1)%MAX_SIZE;
      el[rear]=newElem;
      count++;
    }
  else
    {
      throw Overflow();
    }
}

// PURPOSE: if empty, throw Underflow
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue:: remove(el_t& removedElem)
{
  if (isEmpty()==false)
    {
      removedElem=el[front];
      front=(front+1)%MAX_SIZE;
      count--;
    }
  else
    {
      throw Underflow();
    }
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue:: frontElem(el_t& theElem)
{
  if (isEmpty())
    {
      throw Underflow();
    }
  else
    {
      theElem=el[front];
    }

}

// PURPOSE: returns the current size to make it accessible to the client caller
int queue:: getSize()
{
  return count;
}

// PURPOSE: display everything in the queue horizontally
// from front to rear enclosed in [   ]
// if empty, displays [ empty ]
void queue:: displayAll()
{  int j = front;
  cout << "[";
   for (int i = 1; i <= count; i++)
     { 
       cout << endl << el[j] << endl;
       j=(j+1)%MAX_SIZE;
     }
   cout << "]" << endl;   

}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//calling remove followed by add.
void queue:: goToBack()
{
  if (isEmpty())
    {
      throw Underflow();
    }
  else if (count>1)
    {
       el_t removed;       // ** comment a local variable
	  remove(removed);
	  add(removed);
	
    }
}


