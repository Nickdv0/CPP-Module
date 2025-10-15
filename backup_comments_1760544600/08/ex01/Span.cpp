/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:35:09 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:40:41 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <climits>

// Default constructor
Span::Span() : _maxSize(0)
{
}

// Parametric constructor
Span::Span(unsigned int N) : _maxSize(N)
{
	_numbers.reserve(N);
}

// Copy constructor
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

// Assignment operator
Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

// Destructor
Span::~Span()
{
}

// Add single number
void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw FullContainerException();
	_numbers.push_back(number);
}

// Find shortest span
unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	// Sort a copy to find adjacent differences
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}

	return minSpan;
}

// Find longest span
unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return *maxIt - *minIt;
}

// Getters
unsigned int Span::size() const
{
	return _numbers.size();
}

unsigned int Span::maxSize() const
{
	return _maxSize;
}

// Exception implementations
const char* Span::FullContainerException::what() const throw()
{
	return "Container is full, cannot add more elements";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Cannot calculate span with less than 2 elements";
}
