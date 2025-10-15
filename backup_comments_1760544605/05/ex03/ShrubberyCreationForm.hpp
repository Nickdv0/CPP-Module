/* ************************************************************************** */











#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;

public:

	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();


	const std::string&	getTarget() const;


	virtual void		executeAction() const;


	class FileCreationException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
