#include <iostream>
#include <string>
using namespace std;

class Base {
	string s;

public:
	Base() : s("Base") {
		cout << "Base Class" << endl;
	}
	void what() {
		cout << s << endl;
	}
};
class Derived : public Base {
	string s;
public:
	Derived() : s("Derived"), Base() {
		cout << "Derived Class" << endl; 
	}
	void what() {
		cout << s << endl;
	}
};
int main() {
	Base p;
	Derived c;

	Base* p_p = &p;

	Derived* p_c = static_cast<Derived*>(p_p);
	p_c->what();
	return 0;
}