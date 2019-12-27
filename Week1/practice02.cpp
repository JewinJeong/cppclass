#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
	ifstream inFile("calculation.txt");
	char buf[100];
	string num1,num2;
	int result;
	string s;
	char ch, a;
	
	if (!inFile.is_open()) {
		cout << "Can not find file" << endl;
		return 0;
	}
	while (inFile >> num1 >> ch >> num2 >> a) {
		if (atoi(num1.c_str()) == 0) {
			strtoul(num1.c_str(), nullptr, 16);
			strtoul(num2.c_str(), nullptr, 16);
			switch (ch) {
			case '+':
				result = atoi(num1.c_str()) + atoi(num2.c_str());
				break;
			case '-':
				result = atoi(num1.c_str()) - atoi(num2.c_str());
				break;
			case '*':
				result = atoi(num1.c_str()) * atoi(num2.c_str());
				break;
			case '/':
				result = atoi(num1.c_str()) / atoi(num2.c_str());
				break;
			}
			cout << showbase << hex << left << setw(6) << num1 << ch << " " << setw(6)
				<< num2 << " = " << right << setw(6) << result << endl;
		}
		else {
			switch (ch) {
			case '+':
				result = atoi(num1.c_str()) + atoi(num2.c_str());
				break;
			case '-':
				result = atoi(num1.c_str()) - atoi(num2.c_str());
				break;
			case '*':
				result = atoi(num1.c_str()) * atoi(num2.c_str());
				break;
			case '/':
				result = atoi(num1.c_str()) / atoi(num2.c_str());
				break;
			}
		}
			
		cout << left << setw(6) << num1 << ch << " " << setw(6)
			<< num2 << " = " << right << setw(6) << result << endl;
	}
	inFile.close();
	system("pause");
}