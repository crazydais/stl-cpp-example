#ifndef SP_H
#define SP_H

#include <memory>
#include <cassert>	//	for unit testing
#include <iostream>
#include <vector>
#include <functional>

template <typename T>
class Sp
{
private:

	T * obj;
	int * count;
	typedef std::function<void(T*)> DelFunc;
	DelFunc delFunc;

public:

	static void deleter(T *t)
	{
		delete t;
	}
	static void arrayDeleter(T *t)
	{
		std::cout << "Array Deleter" << std::endl;
		delete[] t;
	}

	//Sp()	//	Default Constructor
	//	//: obj(new T(NULL)), count(new int(1))
	//	: obj(NULL), count(NULL)
	//{

	//}

	Sp(T *t = 0, DelFunc f = deleter)		//	Sp(T *t = 0)	- This can also work as the default constructor, but it isn't optimised.  Set the default DelFunc to be the deleter(T *t) function.
	{
		std::auto_ptr<T> temp(t);
		count = new int(1);
		obj = temp.release();
		delFunc = f;
	}

	///*
	//Sp(T *t)							//	Sp(T *t = 0)	- This can also work as the default constructor, but it isn't optimised
	//	:obj(t), count(new int(1))
	//{

	//}
	//*/

	Sp(const Sp &other)
		: obj(other.obj), count(other.count), delFunc(other.delFunc)
	{
		std::cout << "Copy constructor called!" << std::endl;
		(*count)++;
	}

	~Sp()
	{
		int c = *count;		//	Define the count before count is decremented or deleted
		if (--(*count) == 0)
		{
			try{ delFunc(obj); }
			//	If the obj has no 'delFunc', then catch the exception, and just delete the obj as normal
			catch (...){ delete obj; }
			delete count;
		}
		std::cout << "DESTROYED type: " << typeid(obj).name() << " with a count of: " << c << std::endl;
	}

	struct Printer
	{
		//	Struct member var
		T * obj;
		
		//	Struct constructor, taking an arg of (T *obj).  
		Printer(T * obj) 
			: obj(obj) 
		{ 
			std::cout << "Struct Created\n";
		}
		//	Struct destructor
		~Printer() 
		{ 
			std::cout << "Struct Destroyed\n"; 
		}
		//	Overload the '->' symbol
		T * operator->() const 
		{ 
			return obj; 
		}
		//Printer(){};	//	This resolves the C2512 by providing a default constructor for the struct Printer.  However, with this implementation, the logic is lost and the program will crash.
	};

	//	Overload the '->' symbol
	Printer operator->() const
	{
		return Printer(obj);
	}

	  // Simple overload for the '->' pointer symbol.  This returns a pointer to the type of  object referenced by the Sp pointer. 	
	//T* operator->() const 
	//{ 
	//	return obj; 
	//}

	T& operator*() const
	{
		std::cout << "Dereference '*' operator overload" << std::endl;
		return *obj;
	}

	void swap(Sp &other)
	{
		std::swap(obj, other.obj);
		std::swap(count, other.count);
		std::swap(delFunc, other.delFunc);
	}

	Sp& operator= (const Sp &rhs)
	{
		std::cout << "Equals '=' operator overload" << std::endl;
		Sp temp(rhs);
		swap(temp);
		return *this;
	}

	int use_count() const
	{
		return *count;
	}
};

#endif