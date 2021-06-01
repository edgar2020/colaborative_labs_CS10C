#include "HashTable.h"
#include "WordEntry.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) {
    // 1) Create an array of Word Entry with size s
    size = s;
    //WordEntry* words[size];
	hashTable = new WordEntry[size];
}

/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(const string &s) {
    unsigned hash  = 0;
    
    for( char c :  s)
    {
        // hash += c;
		hash = (((hash * 378551)%size) + c);
    }

   return (hash) % size;
}

int HashTable::contains(const string & s)
{
	int index = computeHash(s);
     //look if already exists
     while(hashTable[index].getWord() != "")//.getWord() != " ")
	 {
         if(hashTable[index].getWord() == s)
         {
			 return hashTable[index].getKey();
         }
		 index++;
		 if(index >= size)
		 {
			 index = 0;
		 }
		 
     }
	 return hashTable[index].getKey();
}

/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(const string &s) {
	 //go to array index of hash
	 
     int index = computeHash(s);
     //look if already exists
     while(hashTable[index].getWord() != "")//.getWord() != " ")
	 {
         if(hashTable[index].getWord() == s)
         {
			 hashTable[index].addNewAppearance();
			 return;
         }
		 index++;
		 if(index >= size)
		 {
			 index = 0;
		 }
		 
     }
    //  WordEntry temp =
	hashTable[index].setWord(s);
	hashTable[index].setAppearences(1);
}

void HashTable::put( WordEntry &s) {
	 //go to array index of hash
	 
     int index = computeHash(s.getWord());
     //look if already exists
     while(hashTable[index].getWord() != "")//.getWord() != " ")
	 {
		 index++;
		 if(index >= size)
		 {
			 index = 0;
		 }
		 
     }
    //  WordEntry temp =
	hashTable[index] = s;
}
// void HashTable::put(const string &s) {
// 	 //go to array index of hash
	 
//      int index = computeHash(s);
//      //look if already exists
//      while(*(hashTable + index) != nullptr)//.getWord() != " ")
// 	 {
//          if((*hashTable + index)->getWord() == s)
//          {
// 			 (*hashTable + index)->addNewAppearance();
//          }
// 		 index++;
//      }
//     //  WordEntry temp =
// 	hashTable[index] = new WordEntry(s);
// }