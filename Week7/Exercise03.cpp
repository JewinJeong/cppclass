#include <iostream>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

int main() {
	const string prompt = "enter an algebraic expression: ";
	const char lparen = '(';
	const char rparen = ')';

	stack <char> s;
	string buf;

	cout << prompt << endl;
	getline(cin, buf);

	for (int i = 0; i < buf.length(); i++) {
		if (!isspace(buf[i]))
			s.push(buf[i]);
	}

	cout << "og expression: " << buf << endl;

	cout << "expression in reverse : ";

	while (!s.empty()) {
		char t = s.top();
		s.pop();

		if (t == lparen) t = rparen;
		else if (t == rparen) t = lparen;

		cout << t;
	}
	cout << endl;
	system("pause");
	return 0;
}