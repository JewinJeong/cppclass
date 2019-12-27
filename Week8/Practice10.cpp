#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
using namespace std;


class Wordlist {
private:
	vector<string> dictionary;
	list<string> wordlist;

public:
	Wordlist() {
		string temp;
		ifstream ifs("dict.txt");
		if (!ifs.is_open()) {
			cout << "file error" << endl;
			exit(1);
		}
		while (ifs >> temp) {
			dictionary.push_back(temp);
		}

	}
	void checkdictionary(string str) {
		 vector<string> ::iterator i = find(begin(dictionary), end(dictionary), str);
		 if (i == dictionary.end()) {
			 throw string("Not exist word in dictionary");
		 }
	}
	void checkduplication(string str) {
		list<string>::iterator i = find(begin(wordlist), end(wordlist), str);
		if (i == wordlist.end()) {
			throw string("It's Duplication");
		}
	}
	void checkconfirm(string str) {
		string endWord = wordlist.back();
		if (str[0] != endWord[endWord.length()-1]) {
			throw string("Not same as the previous word alphabet");
		}

	}
	void add(string str) {
		try {
			checkdictionary(str);
			checkduplication(str);
			checkconfirm(str);
			wordlist.push_back(str);
		}
		catch (string err) {
			cout << "You Lose. " + err << endl;
			exit(0);
		}
	}
	void startgame() {
		string str;
		cout << "Game Start" << endl;
		while (1) {
			cout << "Input word : "; cin >> str;
			add(str);
			for (list<string>::iterator it = wordlist.begin(); it != wordlist.end(); it++) {
				printf("%d ", *it);
			}
			cout << endl;
		}
	}
};
int main() {
	Wordlist wl;
	wl.startgame();

	return 0;
}