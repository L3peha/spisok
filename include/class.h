#pragma once
#ifndef CLASS_H
#define CLASS_H

#include "Element.h"

using namespace std;

// Обновлённый интерфейс, теперь он шаблон
template<typename T>
class Container
{
public:
	// Виртуальный деструктор
	virtual ~Container() {};

	/*
	 * Виртуальные методы, должны быть реализованы вашим контейнером
	 */

	virtual void print() const = 0;

	 // Вставка элемента
	virtual void insert(const T& value) = 0;

	// Удаление элемента
	virtual void remove(const T& value) = 0;

	// Проверка наличия элемента
	virtual bool exists(const T& value) const = 0;
};

template <typename T>

class list:public Container<T>
{
public:
	list();
	~list();
	void addElement(T& data, int pos);
	void deletePosition(int pos);
	void insert(const T& data);  //addToEnd
	void addToRoot(T& data);
	void print() const;
	int getLenght() const;
	bool exists(const T& data) const;
	void remove(const T& data) override; //deleteAllElementsLikeThis
private:
	element<T>* end;
	element<T>* root;
	int length;
};

template class list<int>;
template class list<string>;
#endif