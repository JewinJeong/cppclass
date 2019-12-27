#include <iostream>
#include <string>

using namespace std;

class Animal {
	string species;
public:
	Animal() {
		species = "Animal";
	}
	Animal(const char* s) {
		species = s;
	}
};

class Primate : public Animal {
private:
	int heart_cham;
public:
	Primate():Animal("Primate"){}
	Primate(int n) : Animal("Primate") {
		heart_cham = n;
	}
};
int main() {
	Animal slug;
	Animal tweety("canary");
	Primate godzilla;
	Primate human(4);
	system("pause");
	return 0;
}