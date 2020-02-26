#include <iostream>
#include <cstdlib>
#include "class.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	list* test = new list;

	for (int i = 1; i < 10; i++) {
		test->addToEnd(i * i);
	}
	test->addToRoot(7);
	test->addElement(25, 4);


	test->print();

	if (test->exist(25))
		cout << "Search for value 25: found" << endl;

	if (!test->exist(111))
		cout << "Search for value 111: not found" << endl;

	test->deleteAllElementsLikeThis(7);

	cout << "---";

	test->print();

	cout << "\n";
	system("pause");
}