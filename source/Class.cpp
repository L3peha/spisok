#include <iostream>
#include "../include/class.h"
template<typename T>

list<T>::list()
{
	this->root = NULL;
	this->end = NULL;
	this->length = 0;
}

template<typename T>

list<T>::~list()
{
	
}

template<typename T>

int list<T>::getLenght() const
{
	return this->length;
}

template<typename T>

void list<T>::addElement(T& data, int pos)
{
	element<T>* NewElement = new element<T>(data);
	element<T>* Insert = root;
	if (pos < 0 || pos > this->length)
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
	if (pos == length)
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
	element<T>* PrevIns = Insert->getPrev();
	PrevIns->setNext(NewElement);
	Insert->setPrev(NewElement);
	NewElement->setPrev(PrevIns);
	NewElement->setNext(Insert);
	this->length++;
}

template<typename T>

void list<T>::deletePosition(int pos)
{
	element<T>* Delete = root;

	if (length == 1) {
		root->setNext(NULL);
		root->setPrev(NULL);
		delete root;
		return;
	}
	if (pos < 0 || pos > length)
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
	element<T>* NextDelete = Delete->getNext();
	element<T>* PrevDelete = Delete->getPrev();
	if (PrevDelete != NULL && length != 1)
		PrevDelete->setNext(NextDelete);
	if (NextDelete != NULL && length != 1)
		NextDelete->setPrev(PrevDelete);
	if (pos == 0)
		root = NextDelete;
	if (pos == length - 1)
	{
		PrevDelete->setNext(NULL);
		end = PrevDelete;
	}
	Delete->setNext(NULL);
	Delete->setPrev(NULL);
	delete Delete;
	length--;
}

template<typename T>

void list<T>::insert(const T& data)
{
	element<T>* NewElement = new element<T>(data);
	NewElement->setData(data);
	NewElement->setNext(NULL);
	NewElement->setPrev(end);

	if (end != NULL)
		end->setNext(NewElement);
	if (length == 0)
		root = end = NewElement;
	else
		end = NewElement;

	this->length++;
}

template<typename T>

void list<T>::addToRoot(T& data)
{
	element<T>* NewElement = new element<T>(data);
	NewElement->setData(data);
	NewElement->setNext(root);
	NewElement->setPrev(NULL);

	if (root != 0)
		root->setPrev(NewElement);
	if (length == 0)
		root = end = NewElement;
	else
		root = NewElement;

	this->length++;
}

template<typename T>

void list<T>::print() const
{
	if (length == 0)
	{
		return;
	}
	element<T>* current = root;
	while (current->getNext())
	{
		cout << current->getData() << endl;
		current = current->getNext();
	}
	cout << current->getData() << endl;
}

template<typename T>

bool list<T>::exists(const T& data) const
{
	element<T>* Current = root;
	if (length == 0)
		return false;
	while (true)
	{
		if (Current == NULL)
			break;
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
	if (exists(data))
	{
		if (length == 0)
		{
			return;
		}
		element<T>* Current = root;
		while (true) {
			if (root->getData() == data) {
				element<T>* temp = root->getNext();
				delete root;
				root = temp;
				length--;
				break;
			}
			if (Current == end && end->getData() == data) {
				element<T>* temp = end->getPrev();
				delete end;
				end = temp;
				end->setNext(NULL);
				length--;
				break;
			}
			if (Current->getData() == data) {
				//element<T>* PrevDelete = Current->getPrev();
				//element<T>* NextDelete = Current->getNext();
				Current->getPrev()->setNext(Current->getNext());
				Current->getNext()->setPrev(Current->getPrev());
				delete Current;
				length--;
				break;
			}
			if (Current->getNext() != NULL)
				Current = Current->getNext();
			else
				break;
		}
	}
}