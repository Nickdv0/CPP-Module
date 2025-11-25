/* ************************************************************************** */











#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:

	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();


	AForm*	makeForm(const std::string& formName, const std::string& target);


	class UnknownFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:

	struct FormCreator
	{
		std::string name;
		AForm* (*create)(const std::string& target);
	};


	static FormCreator _formCreators[3];


	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);
};

#endif
