/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:28:18 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:40:41 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
private:
	T*				_elements;
	unsigned int	_size;

public:
	// Default constructor - creates empty array
	Array() : _elements(NULL), _size(0) {}

	// Constructor with size - creates array of n elements initialized by default
	Array(unsigned int n) : _elements(NULL), _size(n)
	{
		if (n > 0)
			_elements = new T[n]();
	}

	// Copy constructor
	Array(const Array& other) : _elements(NULL), _size(other._size)
	{
		if (_size > 0)
		{
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = other._elements[i];
		}
	}

	// Assignment operator
	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			// Delete current elements
			delete[] _elements;
			
			// Copy new size and allocate new memory
			_size = other._size;
			_elements = NULL;
			
			if (_size > 0)
			{
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = other._elements[i];
			}
		}
		return *this;
	}

	// Destructor
	~Array()
	{
		delete[] _elements;
	}

	// Subscript operator with bounds checking
	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _elements[index];
	}

	// Const subscript operator with bounds checking
	const T& operator[](unsigned int index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return _elements[index];
	}

	// Size getter
	unsigned int size() const
	{
		return _size;
	}

	// Exception class for out of bounds access
	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Array index out of bounds";
		}
	};
};

#endif
