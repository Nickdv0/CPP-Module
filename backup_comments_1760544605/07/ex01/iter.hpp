/* ************************************************************************** */











#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void iter(T* array, size_t length, F func)
{
	if (array == NULL)
		return;

	for (size_t i = 0; i < length; i++)
	{
		func(array[i]);
	}
}


template<typename T>
void print(const T& element)
{
	std::cout << element << " ";
}

template<typename T>
void increment(T& element)
{
	element++;
}

template<typename T>
void square(T& element)
{
	element = element * element;
}

template<typename T>
void makeUppercase(T& element)
{
	if (element >= 'a' && element <= 'z')
		element = element - ('a' - 'A');
}

#endif
