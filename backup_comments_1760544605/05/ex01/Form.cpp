/* ************************************************************************** */











#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _name("Default Form"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
}


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}


Form::Form(const Form& other)
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}


Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{

		_signed = other._signed;
	}
	return *this;
}


Form::~Form()
{
}


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


void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}


const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}


std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << ", grade required to sign: " << form.getGradeToSign()
	   << ", grade required to execute: " << form.getGradeToExecute() << ".";
	return os;
}
