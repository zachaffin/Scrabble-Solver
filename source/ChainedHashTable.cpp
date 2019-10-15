#pragma once
#include "stdafx.h"
#include "ChainedHashTable.h"
#include <algorithm>
#include <iostream>

ChainedHashTable::ChainedHashTable(int n) {
	MAX_SIZE = n;
	table = new list<string>[MAX_SIZE];
}

int ChainedHashTable::hash(string word) {//hash func..sum of ascii
	int index = 0;
	for (auto i = word.begin(); i != word.end(); i++) {
		index += (int)tolower((*i));
	}
	return index;
}

void ChainedHashTable::insertWord(string word) {
	table[hash(word)].push_back(word);
}

list<string> ChainedHashTable::findAnagrams(string word) {
	list<string> result;
	list<string> chain = table[hash(word)]; //collisions
	string str1 = word;
	transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	sort(str1.begin(), str1.end());
	for (auto i = chain.begin(); i != chain.end(); i++) {
		if ((*i).length() == word.length()) {
			string str2 = (*i);
			transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
			sort(str2.begin(), str2.end());
			if (str1.compare(str2) == 0 && (*i).compare(word) != 0) { //is anagram..add
				result.push_back(*i);
			}
		}
	}
	return result;
}