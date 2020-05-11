
#include "../include/class.h"
#include <iostream>

template<typename T>

list<T>::list()
{
	this->root = NULL;
	this->end = NULL;
	this->lenght = 0;
}

template<typename T>

list<T>::~list()
{
	while (this->lenght != 0)
	{
		deletePosition(0);
	}
}

template<typename T>

int list<T>::getLenght() const
{
	return this->lenght;
}

template<typename T>

void list<T>::addElement(T& data, int pos)
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
		this->insert(data);
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

template<typename T>

void list<T>::deletePosition(int pos)
{
	element* Delete = root;

	if (lenght == 1) {
		delete root;
		return;
	}

	if (pos < 0 || pos > lenght)
	{
		system("cls");
		cout << "Incorrect position in \"deletePosition\"\n";
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

template<typename T>

void list<T>::insert(const T& data)
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

template<typename T>

void list<T>::addToRoot(T& data)
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

template<typename T>

void list<T>::print() const
{
	element* Current = root;
	cout << "----Current List----Lenght = " << lenght << "\n";
	while (Current->getNext() != NULL)
	{
		cout << Current->getData() << "\n";
		Current = Current->getNext();
	}
	cout << Current->getData() << "\n";
}

template<typename T>

bool list<T>::exists(const T& data) const
{
	element* Current = root;
	while (true)
	{
		if (Current->getData() == data)
			return true;

		if (Current->getNext() == NULL)
			break;
		Current = Current->getNext();
	}
	return false;
}

template<typename T>

void list<T>::remove(const T& data)
{
	element* Current = root;
	element* temp;
	int i = 0;
	int j = 0;
	while (true)
	{
		temp = Current->getNext();
		if (Current->getData() == data)
		{
			this->deletePosition(i - j);
			j++;
		}
		i++;
		if (temp != NULL)
			Current = temp;
		else
			break;
	}
}