#pragma once

#include "Element.h"
#include <iostream>

using namespace std;

class list
{
public:
	list();
	~list();
	void addElement(int data, int pos);
	void deletePosition(int pos);
	void addToEnd(int data);
	void addToRoot(int data);
	void print();
	int getLenght();
	bool exist(int data);
	void deleteAllElementsLikeThis(int data);
private:
	element* end;
	element* root;
	int lenght;
};

list::list()
{
	this->root = NULL;
	this->end = NULL;
	this->lenght = 0;
}

list::~list()
{
	while (this->lenght != 0)
	{
		deletePosition(0);
	}
}

int list::getLenght()
{
	return this->lenght;
}

void list::addElement(int data, int pos)
{
	element* NewElement = new element;
	NewElement->setData(data);
	element* Insert = root;

	if (pos < 0 || pos > this->lenght)
	{
		system("cls");
		cout << "Incorrect position in \"addElement\"\n";
		system("pause");
		return;
	}

	if (pos == 0)
	{
		this->addToRoot(data);
		return;
	}

	if (pos == lenght)
	{
		this->addToEnd(data);
		return;
	}

	int i = 1;
	while (i <= pos)
	{
		Insert = Insert->getNext();
		i++;
	}

	element* PrevIns = Insert->getPrev();

	PrevIns->setNext(NewElement);
	Insert->setPrev(NewElement);
	NewElement->setPrev(PrevIns);
	NewElement->setNext(Insert);

	this->lenght++;
}

void list::deletePosition(int pos) 
{

	element* Delete = root;

	if (pos < 0 || pos > lenght) 
	{
		system("cls");
		std::cout << "Incorrect position in \"deleteElement\"\n";
		system("pause");
		return;
	}

	int i = 0;
	while (i < pos) 
	{
		Delete = Delete->getNext();
		i++;
	}

	element* NextDelete = Delete->getNext();
	element* PrevDelete = Delete->getPrev();


	if (PrevDelete != NULL && lenght != 1)
		PrevDelete->setNext(NextDelete);
	if (NextDelete != NULL && lenght != 1)
		NextDelete->setPrev(PrevDelete);

	if (pos == 0)
		root = NextDelete;
	if (pos == lenght - 1) 
	{
		PrevDelete->setNext(NULL);
		end = PrevDelete;
	}

	delete Delete;
	lenght--;
}

void list::addToEnd(int data) 
{

	element* NewElement = new element;
	NewElement->setData(data);
	NewElement->setNext(NULL);
	NewElement->setPrev(end);

	if (end != NULL)
		end->setNext(NewElement);
	if (lenght == 0)
		root = end = NewElement;
	else
		end = NewElement;

	lenght++;
}

void list::addToRoot(int data) 
{

	element* NewElement = new element;
	NewElement->setData(data);
	NewElement->setNext(root);
	NewElement->setPrev(NULL);

	if (root != 0)
		root->setPrev(NewElement);
	if (lenght == 0)
		root = end = NewElement;
	else
		root = NewElement;

	lenght++;
}

void list::print() 
{
	element* Current = root;
	std::cout << "----Current List----Lenght = " << lenght << "\n";
	while (Current->getNext() != NULL) {
		std::cout << Current->getData() << "\n";
		Current = Current->getNext();
	}
	std::cout << Current->getData() << "\n";
}

bool list::exist(int data) 
{
	element* Current = root;
	while (true) {
		if (Current->getData() == data)
			return true;

		if (Current->getNext() == NULL)
			break;
		Current = Current->getNext();
	}
	return false;
}

void list::deleteAllElementsLikeThis(int data) 
{
	element* Current = root;
	element* temp;
	int i = 0;
	while (true) {
		temp = Current->getNext();
		if (Current->getData() == data)
			this->deletePosition(i);
		i++;
		if (temp != NULL)
			Current = temp;
		else
			break;
	}
}