#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <string>

template<typename T>

class element
{
public:
	//element<T>(const T& data);
	//element<T>(const element<T> &other);
	element<T>(const T& data);
	element<T>* getNext() const;
	element<T>* getPrev() const;
	T getData() const;
	void setNext(element<T>* next);
	void setPrev(element<T>* prev);
	void setData(const T& data);
private:
	element<T>* next;
	element<T>* prev;
	T data;
};

template class element<int>;
template class element<std::string>;

#endif
