#include <memory>	//	for auto_ptr
#include <cassert>	//	for unit testing
#include <iostream>
#include <vector>
#include <functional>

#include <typeinfo>

#include "Sp.h"
#include "Stack.h"

int main()
{
	
	try
	{
		Sp<int> spi = new int(5);
		assert(*spi == 5);
		assert(spi.use_count() == 1);
		if ((spi.use_count() == 1)) { std::cout << "Test 01: PASSED" << std::endl; }

		//	Create an on-the-fly block.  Once the block goes out of scope, s2 is destroyed.
		{
			Sp<int> s2 = spi;
			std::cout << spi.use_count() << std::endl;

			Sp<int> spi2(spi);
			std::cout << *spi2 << std::endl;
			std::cout << spi2.use_count() << std::endl;

			Sp<int> spInt = new int(8);
			s2 = spInt;
			std::cout << *s2 << std::endl;
		}

		//	Since s2 has gone out of scope, the destructor is called, and the reference count is back down to 1 (since s1 still exists).
		std::cout << *spi << std::endl;
		std::cout << spi.use_count() << std::endl;

		Sp<std::string> sps(new std::string("hello"));
		std::cout << "X" << sps->length() << "Y" << std::endl;
		//assert(sps->length() == 5);


		std::vector<Sp<int>> v(1); 
		v.push_back(spi);
		v.at(0) = new int(11);
		std::cout << "Vector Data: " << *v[0] << std::endl;
		std::cout << "Vector Data: " << *v[1] << std::endl;
		std::cout << "Vector Size: " << v.size() << std::endl;

		Sp<int> spia(new int[5], Sp<int>::arrayDeleter);

		Sp<char> spv((char *)malloc(100), free);

		return 0;

	}
	catch (...)
	{
		return 1;
	}
}