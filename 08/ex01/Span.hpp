/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:35:13 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:40:41 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	// Orthodox Canonical Form
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// Member functions
	void			addNumber(int number);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	// Range addition
	template<typename Iterator>
	void addRange(Iterator begin, Iterator end);

	// Getters
	unsigned int	size() const;
	unsigned int	maxSize() const;

	// Exception classes
	class FullContainerException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

// Template implementation
template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	// Calculate distance
	typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
	
	// Check if we have enough space
	if (_numbers.size() + static_cast<unsigned int>(distance) > _maxSize)
		throw FullContainerException();
	
	// Add elements
	_numbers.insert(_numbers.end(), begin, end);
}

#endif
