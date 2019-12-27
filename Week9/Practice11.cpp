#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stack>
#include <vector>

using namespace std;

int main() {
	stack<string> s;	
	
	ofstream ofs;
	ofs.open("output.txt");
	
	ifstream ifs;
	ifstream ifs2;
	
	char ch1, ch2;
	string a, b;
	ifs.open("calculation.txt");
	
	if (ifs.fail()) {
		cout << "can not open text file";
		return -1;
	}
	while (ifs >> ch1 >> a >> b ) {
		if (atoi(a.c_str()) != 0 && atoi(b.c_str()) != 0) {
			int num1 = atoi(a.c_str());
			int num2 = atoi(b.c_str());
			switch (ch1) {
			case '+':
				ofs << a << setw(10) << ch1 << setw(3) << b << setw(9) << "=" << setw(8) << dec << " dex : " << num1 + num2 << oct << " oct : " << num1 + num2 << hex << " hex : "<<num1 + num2 << endl;
				break;
			case '-':
				ofs << a << setw(10) << ch1 << setw(3) << b << setw(9) << "=" << setw(8) << dec << " dex : " << num1 - num2 << oct << " oct : " << num1 - num2 << hex  << " hex : " << num1 - num2 << endl;
				break;
			case '/':
				ofs << a << setw(10) << ch1 << setw(3) << b << setw(9) << "=" << setw(8) << (double)num1 / (double)num2 << endl;
				break;
			case '*':
				ofs << a << setw(9) << ch1 << setw(3) << b << setw(9) << "=" << setw(8) << dec << " dex : " << num1 * num2 << oct << " oct : " << num1 * num2 << hex << " hex : " << num1 * num2 << endl;
				break;
			default:
				ofs << "It is Wrong" << endl;
				break;
			}
		}
		else {
			long num1 = strtol(a.c_str(), NULL, 16);
			long num2 = strtol(b.c_str(), NULL, 16);
			cout.setf(ios::showbase);
			switch (ch1) {
			case '+':
				ofs << a << setw(7) << ch1 << setw(5) << b << setw(7) << "=" << setw(8) << dec << " dex : " << num1 + num2 << oct << " oct : " << num1 + num2 << hex << " hex : " << num1 + num2 << endl;
				break;
			case '-':
				ofs << a << setw(7) << ch1 << setw(5) << b << setw(7) << "=" << setw(8) << dec << " dex : " << num1 - num2 << oct << " oct : " << num1 - num2 << hex << " hex : " << num1 - num2 << endl;
				break;
			case '*':
				ofs << a << setw(7) << ch1 << setw(5) << b << setw(7) << "=" << setw(8) << dec << " dex : " << num1 * num2 << oct << " oct : " << num1 * num2 << hex << " hex : " << num1 * num2 << endl;
				break;
			default:
				ofs << "It is Wrong" << endl;
				break;
			}
		}
	}
	
	ifs.close();
	ofs.close();

	vector<string> file;
	string buf;

	ifs2.open("output.txt");
	if (ifs2.fail()) {
		cout << "can not open text file";
		return -1;
	}
	while (ifs2.peek() != EOF) {
		getline(ifs2, buf);
		file.push_back(buf);
	}
	
	for (int i = file.size()-1; i >= 0; i--) {
		cout << file[i] << endl;
		
	}
	system("pause");
	return 0;
}