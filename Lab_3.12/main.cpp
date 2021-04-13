#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <stdexcept>

using namespace std;

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index);

template<typename T>
void selection_sort(vector<T> &vals);

template<typename T>
T getElement(vector<T> vals, int index);

vector<char> createVector(){
    int vecSize = rand() % 26;
    //cout << "Size: " << vecSize << endl;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){

    //Part B
    try 
    {
        srand(time(0));
        vector<char> vals = createVector();
        char curChar;
        unsigned index;
        int numOfRuns = 10;
        while(--numOfRuns >= 0)
        {
            cout << "Enter a number: " << endl;
            cin >> index;
            if (index >= vals.size() || index < 0)
            {
                throw out_of_range("out of range exception occured"); 
            }
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;           
        }
    }
    catch (const out_of_range& excpt)
    {
        cout << excpt.what() << endl;         
    }
    return 0;
}//end of main

template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned min = index;
    for (unsigned i = index + 1; i < vals.size(); i++) 
        if (vals.at(i) < vals.at(min)) min = i;
    return min;
}//end of min_index

template<typename T>
void selection_sort(vector<T> &vals)
{
    T temp;
    if(vals.size() > 1)
    {
        for(unsigned i = 0; i < vals.size(); i++)
        {
            unsigned minIndex = min_index(vals, i);
            temp = vals.at(i);
            vals.at(i) = vals.at(minIndex);
            vals.at(minIndex) = temp; 
        }
    }
}//end of selection sort

template<typename T>
T getElement(vector<T> vals, int index)
{
    return vals.at(index);

    // try {
    //     if (index >= vals.size() || index < 0)
    //     {
    //         throw out_of_range("out of range exception occured"); 
    //     }
    //     else return vals.at(index);
    // }
    // catch (const out_of_range& excpt)
    // {
    //     cout << excpt.what() << endl;
    //     return ' ';
    // }
    
}