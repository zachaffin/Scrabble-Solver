#pragma once
#include <string>
#include <list>

using namespace std;

class ChainedHashTable {
	int MAX_SIZE;
	list<string> *table;

public:
	ChainedHashTable(int MAX_SIZE);

	int hash(string);

	void insertWord(string);

	list<string> findAnagrams(string word);
};