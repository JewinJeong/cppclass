#include <iostream>
#include <string>
using namespace std;

int operator/(string str, string find) {
	int count = 0;
	int index = -1;
	while ((index = str.find(find)) != -1) {
		str.erase(index,find.length());
		count++;
	}
	return count;
}
string operator-(string str, string find) {
	int index = -1;
	while ((index = str.find(find)) != -1) {
		str.erase(index, find.length());
	}
	return str;
}
string operator*(string str, int numStr) {
	string newStr;
	for (int i = 0; i < numStr; i++) {
		newStr.append(str);
	}
	return newStr;
}

int main() {
	string s1 = "this is test string. test is ok";
	string s2, s3, s4;
	int n;
	n = s1 / "test";
	cout << n << endl;
	s2 = s1 - "test";
	cout << s2 << endl;
	
	string word1 = "test";
	s4 = word1 * 3;
	cout << s4 << endl;

	s2 = s1 - "test" - "this";
	cout << s2 << endl;
	string word2 = "bbaq";
	s4 = word2 * 3 * 2;
	cout << s4 << endl;
	system("pause");
	return 0;
}