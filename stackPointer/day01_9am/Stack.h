#ifndef STACK_H
#define STACK_H

#include <memory>	//	for auto_ptr
#include <cassert>	//	for unit testing
#include <iostream>
#include <vector>
#include <functional>
//	#include "qbit.h"		//	Testing Framework


//	Question 01	- Start: Implement a templated fixed-size stack. Ensure that all operations are strongly exception safe
template <typename T>
class Stack
{
	T * data;			// Dynamically allocated.
	size_t size,		// Number of elements in the stack.
		index,			// Index of last element.
		max;			// Number of elements we have room for.

	//	Added ::pop and ::top methods, for strongly exception safe operation 
	void pop()
	{
		--index;
	}

	void push(const T& item)
	{
		reserve(size + 1);
		data[size++] = item;
	}

	T top() const
	{
		return data[index - 1];
	}

	//	Swap
	void swap(Stack& other)
	{
		// The std::swap() algorithm is safe to use here
		std::swap(data, other.data);
		std::swap(size, other.size);
		std::swap(index, other.index);
		std::swap(max, other.max);
	}

	//	Constructor
	Stack(size_t sz)
		: data(new T[sz]), size(sz), index(sz), max(sz)
	{
		if (sz < 1)
		{
			// Don't call 'top'
		}
	}
	//	Destructor
	~Stack()
	{
		delete[] data;
	}

	//	Copy Constructor
	Stack(const Stack & rhs)
		: data(new T[size])
	{
		// Jump through hoops to avoid leaking resources
		// if ’new’ throws an exception.
		int * temp = new int(*rhs.data1);
		try
		{
			data2 = new int(*rhs.data2);
		}
		catch (...)
		{
			// If ’new’ threw, release all resources, and re-throw.
			// Safe to use delete because the variables were
			// initialised to null pointers.
			delete temp;
			throw;
		}
		// Finish constructing.
		data1 = temp;

		//	This is for question 2
		//std::auto_ptr<int> temp(new int(*rhs.data1));
		//data2 = new int(*rhs.data2);
		//data1 = temp.release();
	}

	//	Copy Operator
	Stack& operator=(const Stack& rhs)
	{
		Stack temp(rhs);
		swap(temp);
		return *this;
	}
};

#endif