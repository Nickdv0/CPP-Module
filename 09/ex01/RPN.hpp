/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:55:00 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:49:04 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

class RPN
{
private:
	std::stack<double> _stack;
	
	// Private methods
	bool isOperator(const std::string& token) const;
	bool isNumber(const std::string& token) const;
	double performOperation(double a, double b, const std::string& op) const;
	
public:
	// Orthodox Canonical Form
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
	
	// Public methods
	double evaluate(const std::string& expression);
	
	// Exception classes
	class InvalidExpressionException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class DivisionByZeroException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class InsufficientOperandsException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
