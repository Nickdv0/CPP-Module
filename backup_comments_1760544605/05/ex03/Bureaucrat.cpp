/* ************************************************************************** */











#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE)
{
}


Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade = grade;
}


Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}


Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{

		_grade = other._grade;
	}
	return *this;
}


Bureaucrat::~Bureaucrat()
{
}


const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}


void Bureaucrat::incrementGrade()
{
	if (_grade <= HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= LOWEST_GRADE)
		throw GradeTooLowException();
	_grade++;
}


void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}


void Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
