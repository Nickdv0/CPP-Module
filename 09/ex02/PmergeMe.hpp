/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:00:00 by nde-vant          #+#    #+#             */
/*   Updated: 2025/11/25 21:13:43 by nde-vant         ###   ########.fr       */
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
	
	void fordJohnsonSortVector(std::vector<int>& arr);
	int binarySearchVector(const std::vector<int>& arr, int value) const;
	
	void fordJohnsonSortDeque(std::deque<int>& arr);
	int binarySearchDeque(const std::deque<int>& arr, int value) const;
	
	bool isValidNumber(const std::string& str) const;
	void displaySequence(const std::vector<int>& seq, const std::string& label) const;
	double getTimeDifference(clock_t start, clock_t end) const;
	
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();
	
	void parseInput(int argc, char* argv[]);
	void sortAndCompare();
	
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
