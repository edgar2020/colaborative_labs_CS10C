#include "Heap.h"
#include <iostream>

using namespace std;
Heap::Heap()
{
    numItems = 0;
}//end onf constructor

void Heap::enqueue(PrintJob* job)
{
    if(numItems < MAX_HEAP_SIZE)
    {
        arr[numItems++] = job;
        
        int currIndex = numItems - 1;
        while(arr[0] != job && arr[(currIndex - 1) / 2]->getPriority() < arr[currIndex]->getPriority())
        {
            //cout << "Test 1" << endl;
            PrintJob* temp = arr[(currIndex - 1) / 2];
            arr[(currIndex - 1) / 2] = arr[currIndex];
            arr[currIndex] = temp;
            currIndex = (currIndex - 1) / 2;
            //cout << "Test 2" << endl;
        }
    }
}//end of enqueue

void Heap::dequeue()
{
    if(numItems > 1)  
    {  
        PrintJob* temp = arr[0];
        arr[0] = arr[numItems - 1];
        arr[numItems - 1] = temp;
        numItems--;

        //cout<<"test 1"<<endl;
        trickleDown(0);
    }//end of if
}//end of deque

void Heap::trickleDown(int i)
{
    PrintJob* temp;// = arr[i];
    while(i < (numItems - 1) / 2 && ( arr[i]->getPriority() < arr[2*i + 1]->getPriority() || arr[i]->getPriority() < arr[2*i + 2]->getPriority()))
    {
        //cout<<"test 2"<<endl;
        if(arr[2*i + 1]->getPriority() > arr[2*i + 2]->getPriority())
        {
            //cout<<"test left"<<endl;
            temp = arr[i];
            arr[i] = arr[i * 2 + 1];
            arr[i * 2 + 1] = temp;
            i = i * 2 + 1;
        }
        else
        {
            // cout<<"test right"<<endl;
            temp = arr[i];
            arr[i] = arr[i * 2 + 2];
            arr[i * 2 + 2] = temp;
            i = i * 2 + 2;
        }
        // cout<<"test end of while"<<endl;
    }//end of while
}//end of TRickle Down

PrintJob* Heap::highest ( ) 
{  
    if (numItems > 0)
        return arr[0];
    else
        return nullptr;
}

void Heap::print()
{
    cout << "Priority: " << arr[0]->getPriority();
    cout << ", Job Number: " << arr[0]->getJobNumber();
    cout << ", Number of Pages: " << arr[0]->getPages()<<endl;

    //dequeue();
    // printHeap();
}//end of print

void Heap::printHeap()
{
    for(int i = 0; i < numItems; i++) 
    {
        cout << arr[i]->getPriority() << ' ';
    }
    cout << endl;
}