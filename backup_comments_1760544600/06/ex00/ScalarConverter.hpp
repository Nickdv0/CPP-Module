/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:17:46 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:22:27 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
public:
	// Static conversion method
	static void convert(const std::string& literal);

private:
	// Private constructor to prevent instantiation
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	// Helper methods for type detection
	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
	static bool isPseudoLiteral(const std::string& literal);

	// Helper methods for conversion
	static void convertFromChar(char c);
	static void convertFromInt(int i);
	static void convertFromFloat(float f);
	static void convertFromDouble(double d);
	static void handlePseudoLiteral(const std::string& literal);

	// Helper methods for display
	static void printChar(char c);
	static void printInt(int i);
	static void printFloat(float f);
	static void printDouble(double d);
	
	// Helper methods for validation
	static bool isValidNumber(const std::string& literal);
	static bool isDisplayable(char c);
};

#endif
