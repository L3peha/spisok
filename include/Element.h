#pragma once

class element
{
public:
	element* getNext();
	element* getPrev();
	int getData();
	void setNext(element* next);
	void setPrev(element* prev);
	void setData(int data);
private:
	element* next;
	element* prev;
	int data;
};

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