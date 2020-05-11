
#include "../include/Element.h";


void element::setData(int data)
{
	this->data = data;
}

void element::setNext(element* next)
{
	this->next = next;
}

void element::setPrev(element* prev)
{
	this->prev = prev;
}

int element::getData()
{
	return this->data;
}

element* element::getNext()
{
	return this->next;
}

element* element::getPrev()
{
	return this->prev;
}