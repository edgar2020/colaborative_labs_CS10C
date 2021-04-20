#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
using namespace std;

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList
{
    private:
        IntNode *dummyHead;
        IntNode *dummyTail;

    public: 
        IntList();//Initializes an empty list with dummy head and dummy tail.
        ~IntList();// Deallocates all remaining dynamically allocated memory

        /**These must be an O(1)**/
        void push_front(int value);     //Inserts a data value at the front end of the list
        void pop_front();               // Removes the node at the front of the list. Does nothing if the list is empty
        void push_back(int value);      //Inserts a new node at the back end of the list
        void pop_back();                //Removes the node at the end of the list. Does nothing if the list is already empty

        bool empty() const;         // literaly returns true if nothing is stored in the list
        void printReverse() const;  // prints int values stored in the list in REVERSE order
        friend ostream & operator<<(ostream &out, const IntList &rhs);//A freiend function to print contents of list
};

#endif