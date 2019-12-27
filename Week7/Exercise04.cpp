////#include <iostream>
////#include <cstdlib>
////#include <ctime>
////#include <queue>
////
////using namespace std;
////
////int main() {
////	const int howMany = 8;
////	int i;
////	priority_queue<int> nums;
////
////	srand(time(0));
////	for (i = 0; i < howMany; i++) {
////		int next = rand();
////		cout << next << endl;
////		nums.push(next);
////	}
////	cout << "\n ** Priority by value: " << endl;
////	for (i = 0; i < howMany; i++) {
////		cout << nums.top() << endl;
////		nums.pop();
////	}
////	system("pause");
////	return 0;
////}
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//#include <deque>
//#include <string>
//
//using namespace std;
//
//int main(void) {
//
//	deque<int> q;
//	int cmd_cnt = 0;
//	cin >> cmd_cnt;
//
//	while (cmd_cnt--) {
//		string str;
//		cin >> str;
//		if (str == "push_front") {
//			int num = 0;
//			cin >> num;
//			q.push_front(num);
//		}
//		else if (str == "push_back") {
//			int num = 0;
//			cin >> num;
//			q.push_back(num);
//		}
//		else if (str == "pop_front") {
//			if (!q.empty()) {
//				cout << q.front() << endl;
//				q.pop_front();
//			}
//			else {
//				cout << "-1" << endl;
//			}
//		}
//		else if (str == "pop_back") {
//			if (!q.empty()) {
//				cout << q.back() << endl;
//				q.pop_back();
//			}
//			else {
//				cout << "-1" << endl;
//			}
//		}
//		else if (str == "size") {
//			cout << q.size() << endl;
//		}
//		else if (str == "empty") {
//			if (!q.empty()) {
//				cout << "0" << endl;
//			}
//			else {
//				cout << "1" << endl;
//			}
//		}
//		else if (str == "empty") {
//			if (!q.empty()) {
//				cout << "0" << endl;
//			}
//			else {
//				cout << "1" << endl;
//			}
//		}
//		else if (str == "front") {
//			if (!q.empty()) {
//				cout << q.front() << endl;
//			}
//			else {
//				cout << "-1" << endl;
//			}
//		}
//		else if (str == "back") {
//			if (!q.empty()) {
//				cout << q.back() << endl;
//			}
//			else {
//				cout << "-1" << endl;
//			}
//		}
//	}
//	return 0;
//}