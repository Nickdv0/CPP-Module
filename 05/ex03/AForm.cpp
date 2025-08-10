#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Default Form"), _signed(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
}

// Parametric constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other) 
	: _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

// Assignment operator
AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		// Note: _name, _gradeToSign, and _gradeToExecute are const, so we can only copy _signed
		_signed = other._signed;
	}
	return *this;
}

// Destructor
AForm::~AForm()
{
}

// Getters
const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

// Form signing
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

// Form execution
void AForm::execute(const Bureaucrat& executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!";
}

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") 
	   << ", grade required to sign: " << form.getGradeToSign() 
	   << ", grade required to execute: " << form.getGradeToExecute() << ".";
	return os;
}
