#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;

public:
	// Orthodox Canonical Form
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();

	// Getter
	const std::string&	getTarget() const;

	// Implementation of pure virtual function
	virtual void		executeAction() const;

	// Exception class
	class FileCreationException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
