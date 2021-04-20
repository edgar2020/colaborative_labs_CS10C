#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList()
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * IntList constructor, initailizess dummyHead and   *
     * dummyTail and pre and next to eachother other     *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
}//end of IntList constructor

IntList::~IntList()
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * IntList destructor, itierates through the list    *
     * starting at dummyHead->next, and deletes it until *
     * only dummyHead remains, this prompts the code to  *
     * exit the while loop and then deleates dummyHead   *
     * as well                                           *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    while(dummyHead->next != nullptr)
    {
        IntNode *temp = dummyHead->next->next;
        dummyHead->next = temp;
        delete dummyHead->next;
    }
    delete dummyHead;
}//end of IntList destructorm

void IntList::push_front(int value) 
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * Creates new node with new value, and updates the  *
     * new node's next to be dummyHead's current next,   *
     * then sets the node after temp's prev pointer to   *
     * temp, then sets dummyHead's next node pointer to  *
     * the new node(temp), followed by the new node's    *
     * prev pointer being set to point to dummyHead,     *
     * baiscaly jsut updating prev and next for all      *
     * affected ndoes                                    *                                         
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    IntNode* temp = new IntNode(value);
    temp->next = dummyHead->next;
    temp->next->prev = temp;
    dummyHead->next = temp;
    temp->prev = dummyHead;
}

void IntList::pop_front()
{
     /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * Checks that list isn't already empty. Then it     *
     * creates a temporary value to hold dummyTail's     *
     * previous value, assigns that precvious value to   *
     * the one before, and then assigns that value's next*
     * to dummyTail, lastly deleting the temporary node. *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    if (dummyHead->next != dummyTail) 
    {
        IntNode* temp = dummyHead->next;
        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;
    }
} 

void IntList::push_back(int value)
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * Creates new node with new value, and updates the  *
     * new node's prev to be dummyTail current prev, then*
     * sets temp's next node pointer to be dummyTail,    *
     * then it updates the previous node to point to temp* 
     * rather than dummyTail, and updates dummy tail to  *
     * temp. basically just updating where each affected *
     * node point to                                     *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    IntNode* temp = new IntNode(value);
    temp->prev = dummyTail->prev;
    temp->next = dummyTail;
    dummyTail->prev->next = temp;
    dummyTail->prev = temp;
}

void IntList::pop_back()
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * Checks that list isn't already empty. Then it     *
     * creates a temporary value to hold dummyTail's     *
     * previous value, assigns that precvious value to   *
     * the one before, and then assigns that value's next*
     * to dummyTail, lastly deleting the temporary node. *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    if (dummyHead->next != dummyTail) 
    {
        IntNode* temp = dummyTail->prev;
        dummyTail->prev = temp->prev;
        temp->prev->next = dummyTail;
        delete temp;
    }
}

bool IntList::empty() const
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * returns true if list is empty, else returns false  *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    return (dummyHead->next == dummyTail);
}

void IntList::printReverse() const 
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * Iterates through the linked list starting at      *
     * dummyTail's prev, and interates until it reaches  *
     * the value after dummyHead, then it exits the loop *
     * and prints the first value after dummyHead without*
     * the following space                               *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    if(dummyTail != dummyHead->next)
    {
        for (IntNode* curr = dummyTail->prev; curr != dummyHead->next; curr = curr->prev)
        {
            cout << curr->data << ' ';
        }
        cout<<dummyHead->next->data;
    }
}

ostream & operator<<(ostream &out, const IntList &rhs)
{
    /* * * * * * * * * * * * * * * * * * * * * * * * * * * 
     * Iterates through the linked list starting at      *
     * dummyHead's next, and iterates until it reaches   *
     * the second to last value before dummyTail, then it*
     * exits the loop and prints the last value before   *
     * dummyTail without a following space               *
     * * * * * * * * * * * * * * * * * * * * * * * * * * */
    if(rhs.dummyTail != rhs.dummyHead->next)
    {
        for (IntNode* curr = rhs.dummyHead->next; curr != rhs.dummyTail->prev; curr = curr->next)
        {
            out << curr->data << ' ';
        }
        out << rhs.dummyTail->prev->data;
    }
    return out;
}//end of osstream