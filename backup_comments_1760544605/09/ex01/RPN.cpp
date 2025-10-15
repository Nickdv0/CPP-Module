/* ************************************************************************** */











#include "RPN.hpp"
#include <cstdlib>


RPN::RPN()
{
}


RPN::RPN(const RPN& other) : _stack(other._stack)
{
}


RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	return *this;
}


RPN::~RPN()
{
}


double RPN::evaluate(const std::string& expression)
{

	while (!_stack.empty())
		_stack.pop();

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			double num = std::atof(token.c_str());

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


bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}


bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;


	if (token.length() == 1 && std::isdigit(token[0]))
		return true;

	return false;
}


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
