/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:55:00 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:49:04 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

// Default constructor
RPN::RPN()
{
}

// Copy constructor
RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

// Assignment operator
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}

// Destructor
RPN::~RPN()
{
}

// Evaluate RPN expression
double RPN::evaluate(const std::string& expression)
{
	// Clear the stack for fresh evaluation
	while (!_stack.empty())
		_stack.pop();
	
	std::istringstream iss(expression);
	std::string token;
	
	while (iss >> token)
	{
		if (isNumber(token))
		{
			double num = std::atof(token.c_str());
			// Check if number is single digit as required
			if (token.length() == 1 && std::isdigit(token[0]))
			{
				_stack.push(num);
			}
			else
			{
				throw InvalidExpressionException();
			}
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw InsufficientOperandsException();
			
			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();
			
			double result = performOperation(a, b, token);
			_stack.push(result);
		}
		else
		{
			throw InvalidExpressionException();
		}
	}
	
	if (_stack.size() != 1)
		throw InvalidExpressionException();
	
	return _stack.top();
}

// Check if token is an operator
bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

// Check if token is a valid number
bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;
	
	// For this exercise, only single digits 0-9 are valid
	if (token.length() == 1 && std::isdigit(token[0]))
		return true;
	
	return false;
}

// Perform arithmetic operation
double RPN::performOperation(double a, double b, const std::string& op) const
{
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
	{
		if (b == 0)
			throw DivisionByZeroException();
		return a / b;
	}
	else
	{
		throw InvalidExpressionException();
	}
}

// Exception implementations
const char* RPN::InvalidExpressionException::what() const throw()
{
	return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
	return "Error: Division by zero";
}

const char* RPN::InsufficientOperandsException::what() const throw()
{
	return "Error: Insufficient operands";
}
