#include <iostream>
using namespace std;

class Person {
private:
	unsigned age;
public:
	void setAge(unsigned n);
	unsigned getAge();
};
void Person::setAge(unsigned n) {
	age = n;
}
unsigned Person::getAge() {
	return age;
}
int main() {
	Person p1;
	p1.setAge(11);
	cout << p1.getAge() << '\n';
	Person& p2 = p1;
	cout << p2.getAge() << '\n';
	Person* p3;
	//p3->setAge(13);
	cout << p3->getAge() << '\n';
	system("pause");
}