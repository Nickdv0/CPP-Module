/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:35:06 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:40:41 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>

int main()
{
	std::cout << "\033[1;34m=== CPP Module 08 - Exercise 01: Span ===\033[0m" << std::endl;
	
	try
	{
		std::cout << "\n\033[1;32m--- Basic Test ---\033[0m" << std::endl;
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		std::cout << "\n\033[1;32m--- Exception Tests ---\033[0m" << std::endl;
		
		// Test FullContainerException
		try
		{
			sp.addNumber(20);
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		
		// Test NoSpanException with empty container
		Span empty(5);
		try
		{
			empty.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		
		// Test NoSpanException with single element
		Span single(5);
		single.addNumber(42);
		try
		{
			single.longestSpan();
		}
		catch (const std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
		
		std::cout << "\n\033[1;32m--- Range Addition Test ---\033[0m" << std::endl;
		
		// Test with vector
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(5);
		vec.push_back(2);
		vec.push_back(8);
		
		Span vecSpan(10);
		vecSpan.addRange(vec.begin(), vec.end());
		std::cout << "After adding vector (size: " << vecSpan.size() << "):" << std::endl;
		std::cout << "Shortest span: " << vecSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << vecSpan.longestSpan() << std::endl;
		
		// Test with list
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(15);
		
		vecSpan.addRange(lst.begin(), lst.end());
		std::cout << "After adding list (size: " << vecSpan.size() << "):" << std::endl;
		std::cout << "Shortest span: " << vecSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << vecSpan.longestSpan() << std::endl;
		
		std::cout << "\n\033[1;32m--- Large Container Test (10,000 elements) ---\033[0m" << std::endl;
		
		Span bigSpan(10000);
		std::srand(static_cast<unsigned int>(std::time(0)));
		
		// Add random numbers
		for (int i = 0; i < 10000; ++i)
		{
			bigSpan.addNumber(std::rand() % 100000);
		}
		
		std::cout << "Container filled with " << bigSpan.size() << " random numbers" << std::endl;
		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
		
		std::cout << "\n\033[1;32m--- Edge Cases Test ---\033[0m" << std::endl;
		
		// Test with identical numbers
		Span identical(5);
		identical.addNumber(42);
		identical.addNumber(42);
		identical.addNumber(42);
		std::cout << "Identical numbers - Shortest span: " << identical.shortestSpan() << std::endl;
		std::cout << "Identical numbers - Longest span: " << identical.longestSpan() << std::endl;
		
		// Test with extreme values
		Span extreme(3);
		extreme.addNumber(INT_MIN);
		extreme.addNumber(0);
		extreme.addNumber(INT_MAX);
		std::cout << "Extreme values - Shortest span: " << extreme.shortestSpan() << std::endl;
		std::cout << "Extreme values - Longest span: " << extreme.longestSpan() << std::endl;
		
		std::cout << "\n\033[1;32m--- Copy Constructor Test ---\033[0m" << std::endl;
		Span original(5);
		original.addNumber(1);
		original.addNumber(100);
		
		Span copy(original);
		std::cout << "Original size: " << original.size() << ", Copy size: " << copy.size() << std::endl;
		std::cout << "Copy longest span: " << copy.longestSpan() << std::endl;
		
		// Modify original
		original.addNumber(50);
		std::cout << "After modifying original - Original size: " << original.size() << ", Copy size: " << copy.size() << std::endl;
		
		std::cout << "\n\033[1;34m=== All tests completed successfully! ===\033[0m" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "\033[1;31mUnexpected exception: " << e.what() << "\033[0m" << std::endl;
		return 1;
	}
	
	return 0;
}
