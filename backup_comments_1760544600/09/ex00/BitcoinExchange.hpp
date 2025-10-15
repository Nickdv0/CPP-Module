/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:50:00 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:49:04 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;
	
	// Private methods
	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& valueStr, double& value) const;
	std::string trim(const std::string& str) const;
	std::string findClosestDate(const std::string& date) const;
	
public:
	// Orthodox Canonical Form
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();
	
	// Public methods
	bool loadDatabase(const std::string& filename);
	void processInputFile(const std::string& filename) const;
	
	// Exception classes
	class FileOpenException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class InvalidFormatException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
