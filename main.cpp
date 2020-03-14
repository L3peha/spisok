#include <iostream>
#include <cstdlib>
#include "include/class.h"


using namespace std;

int main()
{
	Container* c = new list;
	for (int i = 1; i < 10; i++)
		c->insert(i * i);

	cout << "Container after creation:" << endl;
	c->print();

	if (c->exists(25))
		cout << "Search for value 25: found" << endl;

	if (!c->exists(111))
		cout << "Search for value 111: not found" << endl;

	c->remove(25);
	cout << "Container after deletion of the element:" << endl;
	c->print();

	delete c;
	return 0;
}