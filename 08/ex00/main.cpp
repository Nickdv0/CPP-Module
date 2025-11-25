/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "=== Testing easyfind Function Template ===" << std::endl;

	try
	{

		std::cout << "\n1. Testing with std::vector:" << std::endl;
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(5);
		vec.push_back(10);
		vec.push_back(15);
		vec.push_back(20);

		std::cout << "Vector contents: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;


		try
		{
			std::vector<int>::iterator found = easyfind(vec, 10);
			std::cout << "Found element 10 at position: " << (found - vec.begin()) << std::endl;
			std::cout << "Value at found position: " << *found << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}


		try
		{
			std::vector<int>::iterator found = easyfind(vec, 99);
			std::cout << "Found element 99 at position: " << (found - vec.begin()) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception when looking for 99: " << e.what() << std::endl;
		}


		std::cout << "\n2. Testing with std::list:" << std::endl;
		std::list<int> lst;
		lst.push_back(2);
		lst.push_back(4);
		lst.push_back(6);
		lst.push_back(8);

		std::cout << "List contents: ";
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;


		try
		{
			std::list<int>::iterator found = easyfind(lst, 6);
			std::cout << "Found element 6 in list" << std::endl;
			std::cout << "Value at found position: " << *found << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}


		try
		{
			std::list<int>::iterator found = easyfind(lst, 2);
			std::cout << "Found first element 2 in list at position: " << std::distance(lst.begin(), found) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}


		std::cout << "\n3. Testing with std::deque:" << std::endl;
		std::deque<int> deq;
		deq.push_back(100);
		deq.push_back(200);
		deq.push_back(300);

		std::cout << "Deque contents: ";
		for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		try
		{
			std::deque<int>::iterator found = easyfind(deq, 200);
			std::cout << "Found element 200 in deque at position: " << std::distance(deq.begin(), found) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}


		std::cout << "\n4. Testing with const container:" << std::endl;
		const std::vector<int> constVec(vec);
		try
		{
			std::vector<int>::const_iterator found = easyfind(constVec, 15);
			std::cout << "Found element 15 in const vector" << std::endl;
			std::cout << "Value: " << *found << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}


		std::cout << "\n5. Testing with empty container:" << std::endl;
		std::vector<int> emptyVec;
		try
		{
			easyfind(emptyVec, 1);
			std::cout << "Found element in empty vector (should not happen)" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception in empty vector: " << e.what() << std::endl;
		}


		std::cout << "\n6. Testing with multiple occurrences:" << std::endl;
		std::vector<int> multiVec;
		multiVec.push_back(5);
		multiVec.push_back(3);
		multiVec.push_back(5);
		multiVec.push_back(7);
		multiVec.push_back(5);

		std::cout << "Vector with multiple 5s: ";
		for (std::vector<int>::iterator it = multiVec.begin(); it != multiVec.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		try
		{
			std::vector<int>::iterator found = easyfind(multiVec, 5);
			std::cout << "Found first occurrence of 5 at position: " << (found - multiVec.begin()) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}


		std::cout << "\n7. Testing with large container:" << std::endl;
		std::vector<int> largeVec;
		for (int i = 0; i < 10000; ++i)
			largeVec.push_back(i);

		try
		{
			std::vector<int>::iterator found = easyfind(largeVec, 5555);
			std::cout << "Found element 5555 in large vector at position: " << (found - largeVec.begin()) << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		try
		{
			easyfind(largeVec, 99999);
			std::cout << "Found element 99999 (should not exist)" << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception when looking for 99999: " << e.what() << std::endl;
		}

	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
