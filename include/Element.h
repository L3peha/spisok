#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H

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
#endif
