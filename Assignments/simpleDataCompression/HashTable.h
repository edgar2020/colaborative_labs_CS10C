#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include "WordEntry.h"

using namespace std;

class HashTable {

 private:
	int size;
	// WordEntry** hashTable;
	WordEntry* hashTable;

 public:
	HashTable(int size);
	
	WordEntry* getArray() {return hashTable;}
	

	int contains(const string &);
	void put(const string &);
	void put( WordEntry &);
 
 private:
	int computeHash(const string &);
};

#endif
