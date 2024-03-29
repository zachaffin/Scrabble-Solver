#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <cctype>
#include "ChainedHashTable.h"

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
	cout << "Loading dictionary..." << endl; 
	//string path = argv[1]; //could use other dictionary


	auto start = high_resolution_clock::now();
	ChainedHashTable h(5000);
	ifstream in("dictionary.txt"); //need input checking
	string str;
	while (getline(in, str)) {
		h.insertWord(str);
	}
	in.close();

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start).count();
	cout << "Dictionary loaded in " << duration << "ms" << endl;

	string input;
	while (cin >> input && input != "exit") {
		auto start = high_resolution_clock::now();

		list<string> ans = h.findAnagrams(input);

		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(stop - start).count();

		cout << ans.size() << " anagrams found for " << input << " in " << duration << "ms" << endl;
		for (auto i = ans.begin(); i != ans.end(); i++) {
			cout << *i;
			if (i != --ans.end()) {
				cout << ", ";
			}
		}
		cout << endl;

		int placesSpecified = 0;

		for (int i = 0; i < input.length(); i++) {
			if (isupper(input.at(i))) { //user specified position of character
				placesSpecified = 1;
				list<string> toRemove;
				for (auto j = ans.begin(); j != ans.end(); j++) {
					string str = *j;
					if (toupper(str.at(i)) != (input.at(i))) {
						toRemove.push_back(str);
					}
				}
				for (string s : toRemove) {
					ans.remove(s);
				}
			}
		}

		if (placesSpecified) {
			cout << ans.size() << " words found for " << input << endl;
			for (auto i = ans.begin(); i != ans.end(); i++) {
				cout << *i;
				if (i != --ans.end()) {
					cout << ", ";
				}
			}
			cout << endl;
		}
	}
    return 0;
}

