#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {

 private:
	string word;
	int numAppearances;
    int key;
 public:
	WordEntry(const string text) : word(text), numAppearances(1) {}
    WordEntry() : word(""), numAppearances(0), key(-1) {}
    
	int getAppearences() {return numAppearances;}
	void addNewAppearance() {numAppearances++;}
    void setWord(const string s) {word = s;}
    void setKey(const int num) {key = num;}
    
    int getKey() {return key;}
    void setAppearences(int num) {numAppearances = num;}
	string & getWord() {return word;}

    // WordEntry & operator=(WordEntry&);
    
};
#endif