#include "../include/Element.h";

template<typename T>
element<T>::element(const T& data) {
	this->data = data;
	next = NULL;
	prev = NULL;
}


/*
template<typename T>
element<T>::element(const element<T> &other) {
	other->data = this->data;
	other->next = this->next;
	other->prev = this->prev;
}
*/


template<typename T>
void element<T>::setData(const T& data)
{
	this->data = data;
}

template<typename T>

void element<T>::setNext(element<T>* next)
{
	this->next = next;
}

template<typename T>

void element<T>::setPrev(element<T>* prev)
{
	this->prev = prev;
}

template<typename T>

T element<T>::getData() const
{
	return data;
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