/* ************************************************************************** */











#include "BitcoinExchange.hpp"
#include <climits>
#include <iomanip>


BitcoinExchange::BitcoinExchange()
{
}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_database = other._database;
	}
	return *this;
}


BitcoinExchange::~BitcoinExchange()
{
}


bool BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{

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


void BitcoinExchange::processInputFile(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw FileOpenException();

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{

		if (firstLine)
		{
			firstLine = false;
			continue;
		}


		size_t pipePos = line.find(" | ");
		if (pipePos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 3));


		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}


		double value;
		if (!isValidValue(valueStr, value))
		{
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			continue;
		}


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


bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;


	for (size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}


	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());


	if (year < 1000 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;


	if (month == 2 && day > 29)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	return true;
}


bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const
{
	if (valueStr.empty())
		return false;

	char* endptr;
	value = std::strtod(valueStr.c_str(), &endptr);


	if (*endptr != '\0')
		return false;


	if (value < 0 || value > 1000)
		return false;

	return true;
}


std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t start = str.find_first_not_of(" \t\n\r");
	if (start == std::string::npos)
		return "";

	size_t end = str.find_last_not_of(" \t\n\r");
	return str.substr(start, end - start + 1);
}


std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = _database.upper_bound(date);

	if (it == _database.begin())
		return "";

	--it;
	return it->first;
}


const char* BitcoinExchange::FileOpenException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidFormatException::what() const throw()
{
	return "Error: invalid file format.";
}
