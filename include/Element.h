#pragma once
#ifndef ELEMENT_H
#define ELEMENT_H

template<typename T>

class element
{
public:
	element* getNext() const;
	element* getPrev() const;
	int getData() const;
	void setNext(element* next);
	void setPrev(element* prev);
	void setData(T& data);
private:
	element* next;
	element* prev;
	T& data;
};

//template class element<int>;
//template class element<std::string>;

#endif
