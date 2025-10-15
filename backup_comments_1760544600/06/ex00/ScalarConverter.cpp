/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:17:43 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:22:27 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Private constructor (cannot be called)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
	if (literal.empty())
	{
		std::cout << "Error: Empty literal" << std::endl;
		return;
	}

	// Check for pseudo-literals first
	if (isPseudoLiteral(literal))
	{
		handlePseudoLiteral(literal);
		return;
	}

	// Detect type and convert
	if (isChar(literal))
	{
		char c = literal[1]; // Get character between quotes
		convertFromChar(c);
	}
	else if (isInt(literal))
	{
		long temp = std::atol(literal.c_str());
		if (temp > INT_MAX || temp < INT_MIN)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		int i = static_cast<int>(temp);
		convertFromInt(i);
	}
	else if (isFloat(literal))
	{
		float f = static_cast<float>(std::atof(literal.c_str()));
		convertFromFloat(f);
	}
	else if (isDouble(literal))
	{
		double d = std::atof(literal.c_str());
		convertFromDouble(d);
	}
	else
	{
		std::cout << "Error: Invalid literal format" << std::endl;
	}
}

bool ScalarConverter::isChar(const std::string& literal)
{
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' && 
			std::isprint(literal[1]));
}

bool ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	
	if (start >= literal.length())
		return false;
	
	for (size_t i = start; i < literal.length(); i++)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
		return false;
	
	std::string withoutF = literal.substr(0, literal.length() - 1);
	return isValidNumber(withoutF) && withoutF.find('.') != std::string::npos;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	return isValidNumber(literal) && literal.find('.') != std::string::npos;
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	return (literal == "nan" || literal == "nanf" || 
			literal == "+inf" || literal == "+inff" ||
			literal == "-inf" || literal == "-inff");
}

bool ScalarConverter::isValidNumber(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;
	
	if (start >= literal.length())
		return false;
	
	bool hasDot = false;
	for (size_t i = start; i < literal.length(); i++)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
		{
			return false;
		}
	}
	return true;
}

void ScalarConverter::convertFromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int i)
{
	// char conversion
	if (i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(static_cast<char>(i)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	
	// int conversion
	std::cout << "int: " << i << std::endl;
	
	// float conversion
	std::cout << "float: " << static_cast<float>(i);
	if (i == static_cast<int>(static_cast<float>(i)))
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
	
	// double conversion
	std::cout << "double: " << static_cast<double>(i);
	if (i == static_cast<int>(static_cast<double>(i)))
		std::cout << ".0" << std::endl;
	else
		std::cout << std::endl;
}

void ScalarConverter::convertFromFloat(float f)
{
	// char conversion
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127 || f != static_cast<int>(f))
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(static_cast<char>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	
	// int conversion
	if (std::isnan(f) || std::isinf(f) || f > INT_MAX || f < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	
	// float conversion
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	
	// double conversion
	if (std::isnan(f))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(f))
		std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << "double: " << static_cast<double>(f);
		if (f == static_cast<int>(f))
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
}

void ScalarConverter::convertFromDouble(double d)
{
	// char conversion
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127 || d != static_cast<int>(d))
		std::cout << "char: impossible" << std::endl;
	else if (!isDisplayable(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	
	// int conversion
	if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	
	// float conversion
	if (std::isnan(d))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(d))
		std::cout << "float: " << (d > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		float f = static_cast<float>(d);
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
	
	// double conversion
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << "double: " << d;
		if (d == static_cast<int>(d))
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
}

void ScalarConverter::handlePseudoLiteral(const std::string& literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	
	if (literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "nan")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "+inf")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (literal == "-inf")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

bool ScalarConverter::isDisplayable(char c)
{
	return (c >= 32 && c <= 126);
}
