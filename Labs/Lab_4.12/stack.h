#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

// stack(): constructs an empty stack.
// push(T val): inserts a new element (val) of type T (T could be integer or string) into the data. If the data array is full, this function should throw an overflow_error exception with error message "Called push on full stack.".
// pop(): removes the last element from data. If the data array is empty, this function should throw an outofrange exception with error message "Called pop on empty stack.".
// top(): returns the top element of stack (last inserted element). If stack is empty, this function should throw an underflow_error exception with error message "Called top on empty stack.".
// empty(): returns true if the stack is empty otherwise it returns false.

template<typename T>
class stack
 {
    private:
        const int MAX_SIZE = 20;
        T wakStac[20];
        int size = 0;
    public:   
        stack();
        void push(T val);
        void pop();
        T top() const;
        bool empty() const;
 };




template<typename T>
stack<T>::stack()
{
    // ??????
}

 template<typename T>
 void stack<T>::push(T val)
 {
     if(size == MAX_SIZE)
     {
         throw overflow_error("Called push on full stack.");
     }
     else
     {
         wakStac[size++] = val;
     }
 }

 template<typename T>
 void stack<T>::pop()
 {
     if(size == 0)
     {
         throw out_of_range("Called pop on empty stack.");
     }
     size--;
 }

template<typename T>
T stack<T>::top() const 
{
    if (empty())
    {
        throw underflow_error("Called top on empty stack.");
    }
    return wakStac[size - 1];
}

template<typename T>
bool stack<T>::empty() const
{
    if (size == 0)
    {
        return true;
    }
    return false;
}

 #endif