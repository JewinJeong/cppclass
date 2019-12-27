#pragma once
#include <iostream>
using namespace std;

class MyString {
private:
	char* string_content; // string 내용
	int string_length;// string 길이
	int memory_capacity; // 메모리 크기
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	void setString(const char* str);
	
	MyString getMyString() const;
	char* getString() const;
	int length() const;
	int capacity() const;
	void reserve(int size); // 할당할 크기

	void println() const;

	MyString& assign(const MyString& str); //  문자 변경
	MyString& assign(const char* str);

	char at(int i) const;

	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);

	int find(int find_from, const MyString& str) const;
	int find(int find_from, const char* str) const;

	MyString& erase(int loc, int num);
};

