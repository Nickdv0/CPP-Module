/* ************************************************************************** */

#include "iter.hpp"
#include <string>


void printString(const std::string& str)
{
	std::cout << "[" << str << "] ";
}


void doubleValue(int& value)
{
	value *= 2;
}

int main()
{
	std::cout << "=== Testing iter Function Template ===" << std::endl;


	std::cout << "\n1. Integer array with print function:" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original array: ";
	iter(intArray, intSize, print<int>);
	std::cout << std::endl;


	std::cout << "\n2. Integer array with increment function:" << std::endl;
	iter(intArray, intSize, increment<int>);
	std::cout << "After increment: ";
	iter(intArray, intSize, print<int>);
	std::cout << std::endl;


	std::cout << "\n3. Integer array with square function:" << std::endl;
	iter(intArray, intSize, square<int>);
	std::cout << "After squaring: ";
	iter(intArray, intSize, print<int>);
	std::cout << std::endl;


	std::cout << "\n4. Double array:" << std::endl;
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
	size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

	std::cout << "Original: ";
	iter(doubleArray, doubleSize, print<double>);
	std::cout << std::endl;

	iter(doubleArray, doubleSize, increment<double>);
	std::cout << "After increment: ";
	iter(doubleArray, doubleSize, print<double>);
	std::cout << std::endl;


	std::cout << "\n5. Character array with uppercase conversion:" << std::endl;
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Original: ";
	iter(charArray, charSize, print<char>);
	std::cout << std::endl;

	iter(charArray, charSize, makeUppercase<char>);
	std::cout << "After uppercase: ";
	iter(charArray, charSize, print<char>);
	std::cout << std::endl;


	std::cout << "\n6. String array:" << std::endl;
	std::string stringArray[] = {"Hello", "World", "Template", "Test"};
	size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "String array: ";
	iter(stringArray, stringSize, printString);
	std::cout << std::endl;


	std::cout << "\n7. Const array test:" << std::endl;
	const int constArray[] = {10, 20, 30, 40, 50};
	size_t constSize = sizeof(constArray) / sizeof(constArray[0]);

	std::cout << "Const array: ";
	iter(constArray, constSize, print<int>);
	std::cout << std::endl;


	std::cout << "\n8. Custom doubling function:" << std::endl;
	int testArray[] = {1, 2, 3, 4};
	size_t testSize = sizeof(testArray) / sizeof(testArray[0]);

	std::cout << "Before doubling: ";
	iter(testArray, testSize, print<int>);
	std::cout << std::endl;

	iter(testArray, testSize, doubleValue);
	std::cout << "After doubling: ";
	iter(testArray, testSize, print<int>);
	std::cout << std::endl;


	std::cout << "\n9. Edge case tests:" << std::endl;
	int* nullArray = NULL;
	iter(nullArray, 0, print<int>);
	std::cout << "NULL array test completed (should do nothing)" << std::endl;

	int emptyTest[] = {};
	iter(emptyTest, 0, print<int>);
	std::cout << "Zero length test completed (should do nothing)" << std::endl;

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
