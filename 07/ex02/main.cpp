/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:29:15 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:29:16 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main()
{
	std::cout << "=== Testing Array Class Template ===" << std::endl;

	try
	{
		// Test 1: Default constructor
		std::cout << "\n1. Default constructor test:" << std::endl;
		Array<int> emptyArray;
		std::cout << "Empty array size: " << emptyArray.size() << std::endl;

		// Test 2: Constructor with size
		std::cout << "\n2. Constructor with size test:" << std::endl;
		Array<int> intArray(5);
		std::cout << "Int array size: " << intArray.size() << std::endl;
		
		// Test default initialization (should be 0 for int)
		std::cout << "Default values: ";
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;

		// Test 3: Assignment and access
		std::cout << "\n3. Assignment and access test:" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = (i + 1) * 10;
		
		std::cout << "After assignment: ";
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;

		// Test 4: Copy constructor
		std::cout << "\n4. Copy constructor test:" << std::endl;
		Array<int> copyArray(intArray);
		std::cout << "Copy array size: " << copyArray.size() << std::endl;
		std::cout << "Copy array values: ";
		for (unsigned int i = 0; i < copyArray.size(); i++)
			std::cout << copyArray[i] << " ";
		std::cout << std::endl;

		// Test 5: Independence of copy
		std::cout << "\n5. Independence test:" << std::endl;
		copyArray[0] = 999;
		std::cout << "Original array[0]: " << intArray[0] << std::endl;
		std::cout << "Copy array[0]: " << copyArray[0] << std::endl;
		std::cout << "Arrays are independent: " << (intArray[0] != copyArray[0] ? "YES" : "NO") << std::endl;

		// Test 6: Assignment operator
		std::cout << "\n6. Assignment operator test:" << std::endl;
		Array<int> assignedArray;
		assignedArray = intArray;
		std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
		std::cout << "Assigned array values: ";
		for (unsigned int i = 0; i < assignedArray.size(); i++)
			std::cout << assignedArray[i] << " ";
		std::cout << std::endl;

		// Test 7: Independence after assignment
		assignedArray[1] = 888;
		std::cout << "Original array[1]: " << intArray[1] << std::endl;
		std::cout << "Assigned array[1]: " << assignedArray[1] << std::endl;

		// Test 8: Different types
		std::cout << "\n8. Different types test:" << std::endl;
		Array<std::string> stringArray(3);
		stringArray[0] = "Hello";
		stringArray[1] = "World";
		stringArray[2] = "Template";
		
		std::cout << "String array: ";
		for (unsigned int i = 0; i < stringArray.size(); i++)
			std::cout << stringArray[i] << " ";
		std::cout << std::endl;

		Array<double> doubleArray(4);
		for (unsigned int i = 0; i < doubleArray.size(); i++)
			doubleArray[i] = (i + 1) * 3.14;
		
		std::cout << "Double array: ";
		for (unsigned int i = 0; i < doubleArray.size(); i++)
			std::cout << doubleArray[i] << " ";
		std::cout << std::endl;

		// Test 9: Const access
		std::cout << "\n9. Const access test:" << std::endl;
		const Array<int>& constRef = intArray;
		std::cout << "Const access to element 2: " << constRef[2] << std::endl;

		// Test 10: Out of bounds exception
		std::cout << "\n10. Exception test:" << std::endl;
		std::cout << "Trying to access index 10 in array of size " << intArray.size() << std::endl;
		
		try
		{
			int value = intArray[10];
			std::cout << "ERROR: Should have thrown exception, got value: " << value << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Test 11: Out of bounds on empty array
		std::cout << "\n11. Exception on empty array:" << std::endl;
		try
		{
			int value = emptyArray[0];
			std::cout << "ERROR: Should have thrown exception, got value: " << value << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		// Test 12: Large array
		std::cout << "\n12. Large array test:" << std::endl;
		Array<int> largeArray(1000);
		std::cout << "Large array size: " << largeArray.size() << std::endl;
		largeArray[999] = 42;
		std::cout << "Last element: " << largeArray[999] << std::endl;

		// Test 13: Self-assignment
		std::cout << "\n13. Self-assignment test:" << std::endl;
		Array<int> selfTest(3);
		selfTest[0] = 1;
		selfTest[1] = 2;
		selfTest[2] = 3;
		selfTest = selfTest;  // Self-assignment
		std::cout << "After self-assignment: ";
		for (unsigned int i = 0; i < selfTest.size(); i++)
			std::cout << selfTest[i] << " ";
		std::cout << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
