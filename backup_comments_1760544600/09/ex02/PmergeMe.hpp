/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:00:00 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:49:04 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class PmergeMe
{
private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;
	
	// Ford-Johnson algorithm implementation for vector
	void fordJohnsonSortVector(std::vector<int>& arr);
	int binarySearchVector(const std::vector<int>& arr, int value) const;
	
	// Ford-Johnson algorithm implementation for deque
	void fordJohnsonSortDeque(std::deque<int>& arr);
	int binarySearchDeque(const std::deque<int>& arr, int value) const;
	
	// Utility functions
	bool isValidNumber(const std::string& str) const;
	void displaySequence(const std::vector<int>& seq, const std::string& label) const;
	double getTimeDifference(clock_t start, clock_t end) const;
	
public:
	// Orthodox Canonical Form
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	
	// Public methods
	void parseInput(int argc, char* argv[]);
	void sortAndCompare();
	
	// Exception classes
	class InvalidArgumentException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class NegativeNumberException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
