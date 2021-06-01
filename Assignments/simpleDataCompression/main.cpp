#include <iostream>
#include <limits>
#include "HashTable.h"
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

bool isSymbol(char);
void Quicksort_medianOfThree(WordEntry[], int, int);//O(N log N)
const int ENCODER_SIZE = 20;

int main( ) 
{
    string inputFile = "AliceInWonderland.txt";
    string outputFile = "AliceInWonderland_COMP.txt";
    const int SIZE = 10000;
    HashTable table = HashTable(SIZE);    
    //LOAD FILE
    ifstream inFS;
    inFS.open(inputFile);

    if(!inFS.is_open())
    {
        cout << "Could not open file: " << inputFile;
        return 0;
    }
    
    string curr;
    // cout<<"test1"<<endl;
    while (inFS >> curr)
    {
        while (!curr.empty() && isSymbol(curr.back()))
        {
            if(curr!="" && curr!=" ")
                table.put(string(1, curr.back()));
            curr.pop_back();          
        }
        while (!curr.empty() && isSymbol(curr.front()))
        {
            if(curr!="" && curr!=" ")
                table.put(string(1, curr.front()));
            curr.replace(0,1, "");
                //insert symbol into tree
                //remove the symbol
        }
        if(curr!="" && curr!=" ")
            table.put(curr);
        //insert what is left of word into tree
        // tree.inOrder();
    }//end of while
    
    // cout<<"test2"<<endl;

    WordEntry* ourArray = table.getArray();
    Quicksort_medianOfThree(ourArray, 0, SIZE-1);
    HashTable encoder = HashTable(500); 
    cout<<endl;
    //cout<<"Word/Character\tAppearences\tID"<<endl;
    for(int i = 0; i < ENCODER_SIZE; i++)
    {
        ourArray[i].setKey(i + 1);
        //cout<<ourArray[i].getWord()<<"\t\t"<<ourArray[i].getAppearences()<<"\t\t"<<ourArray[i].getKey()<<endl;
        encoder.put(ourArray[i]);
        // encoder.  
    }

    ofstream outFS;
    outFS.open(outputFile);

    if(!outFS.is_open())
    {
        cout << "Could not open file: " << outputFile;
        return 0;
    }
    inFS.close();
    inFS.open(inputFile);

    if(!inFS.is_open())
    {
        cout << "Could not open file: " << inputFile;
        return 0;
    }

    while (getline(inFS, curr))
    {
        //cout << "Line: $" << curr << '$' << endl;
        istringstream inSS(curr);
        string temp;
        while (inSS >> temp)
        {
            int front = 0;
            int back = temp.length() - 1;
            // curr.replace(curr.find(" "), 0, "");
            while ((back - front) >= 1 && isSymbol(temp.substr(front, back + 1).back()))
            {
                //cout << '$' << temp << "$ BACK: \'"<< temp.substr(front, back + 1).back() << '\'' << endl;
                int key = encoder.contains(string(1, temp.substr(front, back + 1).back()));
                //cout << "Key: " << key << " Last index: " << back << endl;
                if(key > 0)
                { 
                    temp.replace(back, 1, to_string(key));
                }
                back--; 
            }
            //cout<<"test2"<<endl;
            while ((back - front) >= 1 && isSymbol(temp.substr(front, back).front()))
            {
                int key = encoder.contains(string(1, temp.substr(front, back).front()));
                if(key > 0)
                {
                    temp.replace(front, 1, to_string(key));
                }
                front++;
            }
            
            //cout<<"test3"<<endl;
            int key = encoder.contains(temp.substr(front, back + 1));
            //cout << temp.substr(front, back + 1) << " Key: " << key << " Last index: " << back << endl;
            //throw runtime_error("STOP");
            if(key > 0)
            { 
                temp.replace(front, back - front + 1, to_string(key));
            }
            
            outFS << temp << ' ' << flush;
        }
        outFS << endl;
        //insert what is left of word into tree
    }//end of while

    inFS.close();
    outFS.close();

    
    cout<<endl;
    cout<<"Word/Character\tAppearences\tID"<<endl;
    for(int i = 0; i < ENCODER_SIZE; i++)
    {
        cout<<ourArray[i].getWord()<<"\t\t"<<ourArray[i].getAppearences()<<"\t\t"<<ourArray[i].getKey()<<endl;
        // encoder.  
    }
    return 0;
}    //ADD FILE WORD

bool isSymbol(char c) {
    return c <= 47 || (c >= 59 && c <= 64) || (c >=91 && c <= 96) || c >= 123;
}

void Quicksort_medianOfThree(WordEntry words[], int i, int k)//O(N log N)
{
    if (i >= k) return;

    int low = i;
    int high = k;
    int pivot = i + (k - i) / 2;
    if (words[i].getAppearences() > words[pivot].getAppearences())
    {
        if (words[pivot].getAppearences() < words[k].getAppearences())
            pivot = k;
    }
    else if (words[k].getAppearences() > words[pivot].getAppearences())
    {
        if (words[pivot].getAppearences() < words[i].getAppearences())
            pivot = i;
    }
    pivot = words[pivot].getAppearences();
    // cout<<"test3"<<endl;
    //sort lower and higher side of midpoints
    bool done = false;
    while(!done) 
    {
        while (words[i].getAppearences() > pivot) i++;
        while (words[k].getAppearences() < pivot) k--;

        if (i >= k) done = true;
        else
        {
            // cout<<"test4"<<endl;
            WordEntry temp;
            temp.setWord(words[i].getWord());
            temp.setAppearences(words[i].getAppearences());
            // cout<<"test5.1"<<endl;
            // cout<<i<<" "<<k<<endl;
            words[i].setWord(words[k].getWord());
            // cout<<"test5.21"<<endl;
            words[i].setAppearences(words[k].getAppearences());
            // cout<<"test5.2"<<endl;
            // words[k] = temp;
            words[k].setWord(temp.getWord());
            words[k].setAppearences(temp.getAppearences());
            // cout<<"test5.3"<<endl;
             // Update lowIndex and highIndex
             
            i++;
            k--;
            // cout<<"test5"<<endl;
        }
    }
    //call it again for left and right
    Quicksort_medianOfThree(words, low, k);
    Quicksort_medianOfThree(words, k + 1, high);
}