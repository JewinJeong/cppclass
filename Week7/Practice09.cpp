#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int main() {
	deque<int> q;
	string str;
	while (1) {
		cin >> str;
		if (str == "push_front") {
			int num;
			cin >> num;
			q.push_front(num);
		}
		else if (str == "push_back") {
			int num;
			cin >> num;
			q.push_back(num);
		}
		else if (str == "pop_fornt") {
			q.pop_front();
		}
		else if (str == "pop_back") {
			q.pop_back();
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			cout << q.empty() << endl;
		}
		else if (str == "front") {
			cout << q.front() << endl;
		}
		else if (str == "back") {
			cout << q.back() << endl;
		}
		else if (str == "end") {
			break;
		}
	}
	system("pause");
	return 0;
}