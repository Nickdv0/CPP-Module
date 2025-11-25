/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:35:13 by nde-vant          #+#    #+#             */
/*   Updated: 2025/11/25 20:37:20 by nde-vant         ###   ########.fr       */
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
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void			addNumber(int number);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template<typename Iterator>
	void addRange(Iterator begin, Iterator end);

	unsigned int	size() const;
	unsigned int	maxSize() const;

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

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	typename std::iterator_traits<Iterator>::difference_type distance = std::distance(begin, end);
	
	if (_numbers.size() + static_cast<unsigned int>(distance) > _maxSize)
		throw FullContainerException();
	
	_numbers.insert(_numbers.end(), begin, end);
}

#endif
