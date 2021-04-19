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
T getElement(vector<T> v, int index) {return v.at(index);}

vector<char> createVector(){
    int vecSize = rand() % 26;
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
    
        srand(time(0));
        vector<char> vals = createVector();
        char curChar;
        unsigned index;
        int numOfRuns = 10;
        while(--numOfRuns >= 0)
        {
            cout << "Enter a number: " << endl;
            cin >> index;
            // if (index >= vals.size() || index < 0)
            // {
            //     throw out_of_range("out of range exception occured"); 
            // }
            try 
            {
                vals.at(index);
                curChar = getElement(vals,index);
                cout << "Element located at " << index << ": is " << curChar << endl;           
            }
            catch (const out_of_range& excpt)
            {
                cout <</* excpt.what() << */"out of range exception occured" << endl;         
            }
        }

//testing for new template
    //     string curString;
    //     vector<string> strs;
    //     strs.push_back("Abc");
    //     strs.push_back("abc");
    //     strs.push_back("qwert");
    //     strs.push_back("asdf");
    //     strs.push_back("zxcv");
    //     strs.push_back("dfgh");
    //     strs.push_back("utry");
    //     strs.push_back("rth5");
    //     strs.push_back("34fgds");

    //    //It seems like its working properly.
    //    for(int i = 0; i < strs.size();i++)
    //    {
    //        cout<<strs.at(i)<<endl;
    //    }
    //    selection_sort(strs);
    //    cout<<endl;
    //     cout<<"selection sort"<<endl;
    //    for(int i = 0; i < strs.size();i++)
    //    {
    //        cout<<strs.at(i)<<endl;
    //    }

    //     numOfRuns=10;
    //     while(--numOfRuns >= 0)
    //     {
    //         cout << "Enter a number: " << endl;
    //         cin >> index;
    //         //curString = strs.at(index);//What does this do? So we can look at a certain index, just like the othe 
    //         curString = getElement(strs, index);//Why this not working!??????????No Idea it sould work THERE WE GO!!! I am an idot, when I copy and pasted
    //         //forgot to change the variable from char to a string NOICE
    //         cout << "Element located at " << index << ": is " << curString << endl;           
    //     }
//end of testing for string
    
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

