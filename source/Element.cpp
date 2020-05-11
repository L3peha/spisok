
#include "../include/Element.h";

template<typename T>

void element<T>::setData(T& data)
{
	this->data = data;
}

template<typename T>

void element<T>::setNext(element* next)
{
	this->next = next;
}

template<typename T>

void element<T>::setPrev(element* prev)
{
	this->prev = prev;
}

template<typename T>

int element<T>::getData() const
{
	return this->data;
}

template<typename T>

element<T>* element<T>::getNext() const
{
	return this->next;
}

template<typename T>

element<T>* element<T>::getPrev() const
{
	return this->prev;
}