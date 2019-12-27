#include <iostream>
#include <string>
#include "MyString.h"
using namespace std;

MyString::MyString() {}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
MyString::~MyString() {
	delete[] string_content;
}

void MyString::setString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++) {
		string_content[i] = str[i];
	}
}
MyString MyString::getMyString() const{
	return *this;
}
char* MyString::getString() const {
	return string_content;
}

int MyString::length() const {
	return length();
}
int MyString::capacity() const {
	return capacity();
}
void MyString::println() const {
	for (int i = 0; i != string_length; i++) {
		cout << string_content[i];
	}
	cout << endl;
}
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++) {
			string_content[i] = prev_string_content[i];
		}
		delete[] prev_string_content;
	}
}
MyString& MyString::assign(const MyString& str) {
	if (str.string_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	for (int i = 0; i != str.string_length; i++) {
		string_content[i] = str.string_content[i];
	}
}
MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (string_length > memory_capacity) {
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for (int i = 0; i != str_length; i++) {
		string_content[i] = str[i];
	}
	string_length = str_length;

	return *this;
}

char MyString::at(int i) const {
	char ret = string_content[i];
	return ret;
}

MyString& MyString::insert(int loc, const MyString& str) {
	if (string_length + str.string_length > memory_capacity) {
		if (memory_capacity * 2 > string_length + str.string_length) {
			memory_capacity *= 2;
		}
		else {
			memory_capacity = string_length + str.string_length;
		}
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		int i;
		for (i = 0; i < loc; i++) {
			string_content[i] = prev_string_content[i];
		}
		for (int j = 0; j != str.string_length; j++) {
			string_content[i + j] = str.string_content[j];
		}
		for (; i < string_length; i++) {
			string_content[str.string_length + i] = prev_string_content[i];
		}
		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}
	for (int i = string_length - 1; i >= loc; i--) {
		string_content[i + str.string_length] = string_content[i];

	}
	for (int i = 0; i < str.string_length; i++) {
		string_content[i + loc] = str.string_content[i];
	}
	string_length = string_length + str.string_length;
	return *this;
}

MyString& MyString::insert(int loc, const char* str) {
	MyString a(str);
	return insert(loc, a);
}

int MyString::find(int find_from, const MyString& str) const {
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i < string_length - str.string_length; i++) {
		for (j = 0; j < str.string_length; j++) {
			if (string_content[i + j] != str.string_content[j]) {
				break;
			}
		}
		if (j == str.string_length)
			return i;
	}
	return -1;
}
int MyString::find(int find_from, const char* str)const {
	MyString a(str);
	return find(find_from, a);
}
MyString& MyString::erase(int loc, int num) {
	if (num < 0 || loc<0 || loc>string_length) return *this;
	for (int i = loc + num; i < string_length; i++) {
		string_content[i - num] = string_content[i];
	}
	string_length -= num;
	return *this;
}
