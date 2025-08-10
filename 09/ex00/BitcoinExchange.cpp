/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:50:00 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:49:04 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <climits>
#include <iomanip>

// Default constructor
BitcoinExchange::BitcoinExchange()
{
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}

// Assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
}

// Load database from CSV file
bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line))
	{
		// Skip header line
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		
		std::string date = trim(line.substr(0, commaPos));
		std::string priceStr = trim(line.substr(commaPos + 1));
		
		if (isValidDate(date))
		{
			double price = std::atof(priceStr.c_str());
			_database[date] = price;
		}
	}
	
	file.close();
	return true;
}

// Process input file and calculate bitcoin values
void BitcoinExchange::processInputFile(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw FileOpenException();
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line))
	{
		// Skip header line
		if (firstLine)
		{
			firstLine = false;
			continue;
		}
		
		// Find pipe separator
		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 3));
		
		// Validate date
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		
		// Validate value
		double value;
		if (!isValidValue(valueStr, value))
		{
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		// Find closest date and calculate result
		std::string closestDate = findClosestDate(date);
		if (!closestDate.empty())
		{
			std::map<std::string, double>::const_iterator it = _database.find(closestDate);
			if (it != _database.end())
			{
				double result = value * it->second;
				std::cout << date << " => " << value << " = " << result << std::endl;
			}
		}
		else
		{
			std::cout << "Error: no valid date found in database." << std::endl;
		}
	}
	
	file.close();
}

// Validate date format YYYY-MM-DD
bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;
	
	if (date[4] != '-' || date[7] != '-')
		return false;
	
	// Check if all other characters are digits
	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	
	// Extract year, month, day
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	// Basic range checks
	if (year < 1000 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	
	// Days in month check (simplified)
	if (month == 2 && day > 29)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	
	return true;
}

// Validate value (positive float/int between 0 and 1000)
bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
	if (valueStr.empty())
		return false;
	
	char* endptr;
	value = std::strtod(valueStr.c_str(), &endptr);
	
	// Check if conversion was successful
	if (*endptr != '\0')
		return false;
	
	// Check range
	if (value < 0 || value > 1000)
		return false;
	
	return true;
}

// Trim whitespace from string
std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos)
		return "";
	
	size_t end = str.find_last_not_of(" \t\n\r");
	return str.substr(start, end - start + 1);
}

// Find closest date in database (lower or equal)
std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _database.upper_bound(date);
	
	if (it == _database.begin())
		return ""; // No date in database is <= target date
	
	--it; // Get the largest date that is <= target date
	return it->first;
}

// Exception implementations
const char* BitcoinExchange::FileOpenException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidFormatException::what() const throw()
{
	return "Error: invalid file format.";
}
