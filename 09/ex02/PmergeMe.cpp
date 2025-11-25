/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:00:00 by nde-vant          #+#    #+#             */
/*   Updated: 2025/11/25 21:13:28 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <climits>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData)
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parseInput(int argc, char* argv[])
{
	if (argc < 2)
		throw InvalidArgumentException();
	
	_vectorData.clear();
	_dequeData.clear();
	
	for (int i = 1; i < argc; ++i)
	{
		if (!isValidNumber(argv[i]))
			throw InvalidArgumentException();
		
		long num = std::atol(argv[i]);
		if (num < 0 || num > INT_MAX)
			throw NegativeNumberException();
		
		_vectorData.push_back(static_cast<int>(num));
		_dequeData.push_back(static_cast<int>(num));
	}
}

void PmergeMe::sortAndCompare()
{
	displaySequence(_vectorData, "Before:");
	
	std::vector<int> vectorCopy = _vectorData;
	clock_t vectorStart = clock();
	fordJohnsonSortVector(vectorCopy);
	clock_t vectorEnd = clock();
	double vectorTime = getTimeDifference(vectorStart, vectorEnd);
	
	std::deque<int> dequeCopy = _dequeData;
	clock_t dequeStart = clock();
	fordJohnsonSortDeque(dequeCopy);
	clock_t dequeEnd = clock();
	double dequeTime = getTimeDifference(dequeStart, dequeEnd);
	
	std::vector<int> sortedVector(vectorCopy.begin(), vectorCopy.end());
	displaySequence(sortedVector, "After:");
	
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorData.size() 
			  << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
			  << " elements with std::deque : " << dequeTime << " us" << std::endl;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> singles;
	bool hasOdd = (arr.size() % 2 == 1);
	
	for (size_t i = 0; i < arr.size() - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] <= arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	
	if (hasOdd)
		singles.push_back(arr[arr.size() - 1]);
	
	if (pairs.size() > 1)
	{
		std::vector<int> largerElements;
		for (size_t i = 0; i < pairs.size(); ++i)
			largerElements.push_back(pairs[i].second);
		
		fordJohnsonSortVector(largerElements);
		
		std::vector<std::pair<int, int> > sortedPairs;
		for (size_t i = 0; i < largerElements.size(); ++i)
		{
			for (size_t j = 0; j < pairs.size(); ++j)
			{
				if (pairs[j].second == largerElements[i])
				{
					sortedPairs.push_back(pairs[j]);
					break;
				}
			}
		}
		pairs = sortedPairs;
	}
	
	std::vector<int> mainChain;
	std::vector<int> pendingElements;
	
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].second);
		pendingElements.push_back(pairs[i].first);
	}
	
	if (!pendingElements.empty())
	{
		mainChain.insert(mainChain.begin(), pendingElements[0]);
		pendingElements.erase(pendingElements.begin());
	}
	
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);
	
	while (jacobsthal.back() < static_cast<int>(pendingElements.size()))
	{
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	
	std::vector<bool> inserted(pendingElements.size(), false);
	
	for (size_t i = 2; i < jacobsthal.size() && !pendingElements.empty(); ++i)
	{
		int end = std::min(jacobsthal[i], static_cast<int>(pendingElements.size()));
		int start = jacobsthal[i - 1];
		
		for (int j = end - 1; j >= start && j >= 0; --j)
		{
			if (!inserted[j])
			{
				int pos = binarySearchVector(mainChain, pendingElements[j]);
				mainChain.insert(mainChain.begin() + pos, pendingElements[j]);
				inserted[j] = true;
			}
		}
	}
	
	for (size_t i = 0; i < pendingElements.size(); ++i)
	{
		if (!inserted[i])
		{
			int pos = binarySearchVector(mainChain, pendingElements[i]);
			mainChain.insert(mainChain.begin() + pos, pendingElements[i]);
		}
	}
	
	for (size_t i = 0; i < singles.size(); ++i)
	{
		int pos = binarySearchVector(mainChain, singles[i]);
		mainChain.insert(mainChain.begin() + pos, singles[i]);
	}
	
	arr = mainChain;
}

int PmergeMe::binarySearchVector(const std::vector<int>& arr, int value) const
{
	int left = 0;
	int right = arr.size();
	
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	
	return left;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return;
	
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> singles;
	bool hasOdd = (arr.size() % 2 == 1);
	
	for (size_t i = 0; i < arr.size() - (hasOdd ? 1 : 0); i += 2)
	{
		if (arr[i] <= arr[i + 1])
			pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
		else
			pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
	}
	
	if (hasOdd)
		singles.push_back(arr[arr.size() - 1]);
	
	if (pairs.size() > 1)
	{
		std::deque<int> largerElements;
		for (size_t i = 0; i < pairs.size(); ++i)
			largerElements.push_back(pairs[i].second);
		
		fordJohnsonSortDeque(largerElements);
		
		std::vector<std::pair<int, int> > sortedPairs;
		for (size_t i = 0; i < largerElements.size(); ++i)
		{
			for (size_t j = 0; j < pairs.size(); ++j)
			{
				if (pairs[j].second == largerElements[i])
				{
					sortedPairs.push_back(pairs[j]);
					break;
				}
			}
		}
		pairs = sortedPairs;
	}
	
	std::deque<int> mainChain;
	std::vector<int> pendingElements;
	
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		mainChain.push_back(pairs[i].second);
		pendingElements.push_back(pairs[i].first);
	}
	
	if (!pendingElements.empty())
	{
		mainChain.push_front(pendingElements[0]);
		pendingElements.erase(pendingElements.begin());
	}
	
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);
	
	while (jacobsthal.back() < static_cast<int>(pendingElements.size()))
	{
		int next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	
	std::vector<bool> inserted(pendingElements.size(), false);
	
	for (size_t i = 2; i < jacobsthal.size() && !pendingElements.empty(); ++i)
	{
		int end = std::min(jacobsthal[i], static_cast<int>(pendingElements.size()));
		int start = jacobsthal[i - 1];
		
		for (int j = end - 1; j >= start && j >= 0; --j)
		{
			if (!inserted[j])
			{
				int pos = binarySearchDeque(mainChain, pendingElements[j]);
				mainChain.insert(mainChain.begin() + pos, pendingElements[j]);
				inserted[j] = true;
			}
		}
	}
	
	for (size_t i = 0; i < pendingElements.size(); ++i)
	{
		if (!inserted[i])
		{
			int pos = binarySearchDeque(mainChain, pendingElements[i]);
			mainChain.insert(mainChain.begin() + pos, pendingElements[i]);
		}
	}
	
	for (size_t i = 0; i < singles.size(); ++i)
	{
		int pos = binarySearchDeque(mainChain, singles[i]);
		mainChain.insert(mainChain.begin() + pos, singles[i]);
	}
	
	arr = mainChain;
}

int PmergeMe::binarySearchDeque(const std::deque<int>& arr, int value) const
{
	int left = 0;
	int right = arr.size();
	
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	
	return left;
}

bool PmergeMe::isValidNumber(const std::string& str) const
{
	if (str.empty())
		return false;
	
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	
	return true;
}

void PmergeMe::displaySequence(const std::vector<int>& seq, const std::string& label) const
{
	std::cout << label;
	
	for (size_t i = 0; i < seq.size() && i < 5; ++i)
	{
		std::cout << " " << seq[i];
	}
	
	if (seq.size() > 5)
	{
		std::cout << " [...]";
	}
	
	std::cout << std::endl;
}

double PmergeMe::getTimeDifference(clock_t start, clock_t end) const
{
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000.0;
}

// Exception implementations
const char* PmergeMe::InvalidArgumentException::what() const throw()
{
	return "Error";
}

const char* PmergeMe::NegativeNumberException::what() const throw()
{
	return "Error";
}
