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


	bool isOperator(const std::string& token) const;
	bool isNumber(const std::string& token) const;
	double performOperation(double a, double b, const std::string& op) const;

public:

	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();


	double evaluate(const std::string& expression);


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
