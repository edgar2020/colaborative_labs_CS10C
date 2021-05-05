#include "WordLadder.h"

 WordLadder::WordLadder(const string &inputFile)
 {
    ifstream inFS;
    inFS.open(inputFile);
    
    if(!inFS.is_open())
    {
        cout << "Could not open file: " << inputFile;
        return;
    }
    
    string curr;
    while (inFS >> curr)
    {
        if (curr.length()!= 5)
        {
            cout << "Not All Words are of length 5" << endl;
            return;
        }
        dict.push_back(curr);  
    }//end of while

    inFS.close();
 }//end of WordLadder constructor

 void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile)
 {
    ofstream outFS;
    string deleteThisWords;
    outFS.open(outputFile);//.c_str());
    bool exist = false;
    if(!outFS.is_open())
    {
        cout << "Could not open file: " << outputFile << endl;
        return;
    }

    for(string s: dict)
    {
        deleteThisWords = s;
        if(s == start)
        {
            exist = true;
        }
    
    }
    dict.remove(deleteThisWords);
// cout<<"test test test"<<endl;
    if(!exist)
    {
        cout<<"Start word does not exist"<<endl;
        return;
    }
    exist=false;
    try
    {
        if(start == end)
        {
            throw logic_error("Error when ladder should just be one word.");
            return;
        }
    }
    catch(const logic_error& e)
    {
        outFS<<start;
        cout << e.what() << '\n';
        return;
    }
    
    
    for(string s: dict)
    {
        if(s == end)
        {
            exist = true;
        }
    }
    if(!exist)
    {
        cout<<"End word does not exist"<<endl;
        return;
    }

    stack<string> wakStac;
    wakStac.push(start);
    queue<stack<string>> queueOfStacks;
    queueOfStacks.push(wakStac);
    
    
    //We know the file files can open, the start and end words are of length 5
    //What we need to do
        //find difference between start and end
            //repeat
        //find second difference between start and end


    // cout << "Starting Word: " << start << endl;

    string prev; 
    while (!queueOfStacks.empty()) 
    {
        if(prev != "")
        {
            dict.remove(prev);
        }
        
        string word = queueOfStacks.front().top();

        for (string curr : dict)
        {
            // int currentDif = countDiferences(word, end);
            // cout<<"test 1"<<endl;
            if (countDiferences(word, curr) == 1)
            {
                // cout<<"test 2"<<endl;
                stack<string> newStack;
                newStack = queueOfStacks.front();
                newStack.push(curr);
                // cout<<curr<<endl;
                if (newStack.top() == (end)) //Outputs Word Ladder if complete
                {
                    // cout<<"test 3"<<endl;
                    // newStack.push(end);
                    printLadder(outFS, newStack);
                    return;  
                } 
                else //enqueue this new Stack and removes curr from the dictionary
                {
                    // cout<<"test 4"<<endl;
                    prev = curr;
                    queueOfStacks.push(newStack);
                    // prev = curr;
                }
            }
            
        }
        // cout<<"test 5"<<endl;
         queueOfStacks.pop();
    }   
    // cout<<"test 6"<<endl;
    outFS<<"No Word Ladder Found.";
 }//END OF OUTPUT

 void WordLadder::printLadder( ofstream &outFS, stack<string> newStack)
 {
     if(newStack.empty())
     {
         return;
     }
     stack<string> secondStack = newStack;
     secondStack.pop();
     printLadder(outFS, secondStack); 
     outFS<<newStack.top() << " ";
 }

int WordLadder::countDiferences(const string& word, const string& curr)
{
    int count = 0;
    for (unsigned int i = 0; i < 5; i++)
    {
        if (curr.at(i) != word.at(i))
        {
            count++;
        }
    }
    return count;
}