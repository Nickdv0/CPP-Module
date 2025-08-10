/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:18:15 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:18:16 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
}

// Parametric constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& other) 
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

// Assignment operator
Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		// Note: _name, _gradeToSign, and _gradeToExecute are const, so we can only copy _signed
		_signed = other._signed;
	}
	return *this;
}

// Destructor
Form::~Form()
{
}

// Getters
const std::string& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

// Form signing
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

// Exception implementations
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") 
	   << ", grade required to sign: " << form.getGradeToSign() 
	   << ", grade required to execute: " << form.getGradeToExecute() << ".";
	return os;
}
