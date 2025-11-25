/* ************************************************************************** */











#include "MutantStack.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
	std::cout << "\033[1;34m=== CPP Module 08 - Exercise 02: MutantStack ===\033[0m" << std::endl;

	std::cout << "\n\033[1;32m--- Subject Test ---\033[0m" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top element: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size after pop: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << "Iterating through stack:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		std::stack<int> s(mstack);
	}

	std::cout << "\n\033[1;32m--- Comparison with std::list ---\033[0m" << std::endl;
	{
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << "List back element: " << lst.back() << std::endl;

		lst.pop_back();

		std::cout << "List size after pop: " << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;

		std::cout << "Iterating through list:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	std::cout << "\n\033[1;32m--- Advanced Iterator Tests ---\033[0m" << std::endl;
	{
		MutantStack<int> mstack;


		for (int i = 1; i <= 10; ++i)
		{
			mstack.push(i);
		}

		std::cout << "Stack contents (forward): ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Stack contents (reverse): ";
		for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;


		const MutantStack<int>& constStack = mstack;
		std::cout << "Stack contents (const): ";
		for (MutantStack<int>::const_iterator it = constStack.begin(); it != constStack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n\033[1;32m--- STL Algorithm Tests ---\033[0m" << std::endl;
	{
		MutantStack<int> mstack;


		mstack.push(42);
		mstack.push(17);
		mstack.push(3);
		mstack.push(99);
		mstack.push(7);

		std::cout << "Original stack: ";
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;


		MutantStack<int>::iterator found = std::find(mstack.begin(), mstack.end(), 99);
		if (found != mstack.end())
		{
			std::cout << "Found element 99 at position: " << std::distance(mstack.begin(), found) << std::endl;
		}


		int count = 0;
		for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		{
			if (*it > 20)
				count++;
		}
		std::cout << "Elements greater than 20: " << count << std::endl;


		std::vector<int> vec(mstack.begin(), mstack.end());
		std::sort(vec.begin(), vec.end());
		std::cout << "Stack elements sorted: ";
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n\033[1;32m--- Copy and Assignment Tests ---\033[0m" << std::endl;
	{
		MutantStack<int> original;
		original.push(1);
		original.push(2);
		original.push(3);


		MutantStack<int> copy(original);
		std::cout << "Original size: " << original.size() << ", Copy size: " << copy.size() << std::endl;


		MutantStack<int> assigned;
		assigned.push(99);
		assigned = original;
		std::cout << "Assigned size: " << assigned.size() << std::endl;


		original.push(4);
		std::cout << "After modifying original - Original: " << original.size() << ", Copy: " << copy.size() << std::endl;


		std::cout << "Copy contents: ";
		for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Original contents: ";
		for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "\n\033[1;32m--- String Stack Test ---\033[0m" << std::endl;
	{
		MutantStack<std::string> strStack;

		strStack.push("Hello");
		strStack.push("World");
		strStack.push("42");
		strStack.push("School");

		std::cout << "String stack contents: ";
		for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;


		MutantStack<std::string>::iterator found = std::find(strStack.begin(), strStack.end(), "42");
		if (found != strStack.end())
		{
			std::cout << "Found '42' in string stack" << std::endl;
		}
	}

	std::cout << "\n\033[1;34m=== All tests completed successfully! ===\033[0m" << std::endl;

	return 0;
}
