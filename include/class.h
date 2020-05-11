#pragma once
#ifndef CLASS_H
#define CLASS_H

#include "Element.h"

using namespace std;

class Container
{
public:
	// Виртуальные методы, должны быть реализованы вашим контейнером
	virtual void insert(int data) = 0;
	virtual bool exists(int data) = 0;
	virtual void remove(int data) = 0;

	

	// И этот тоже, хотя к нему потом ещё вернёмся
	virtual void print() = 0;

	// Виртуальный деструктор (пока просто поверьте, что он нужен)
	virtual ~Container() { };
};

class list:public Container
{
public:
	list();
	~list();
	void addElement(int data, int pos);
	void deletePosition(int pos);
	void insert(int data);  //addToEnd
	void addToRoot(int data);
	void print();
	int getLenght();
	bool exists(int data);
	void remove(int data); //deleteAllElementsLikeThis
private:
	element* end;
	element* root;
	int lenght;
};
#endif