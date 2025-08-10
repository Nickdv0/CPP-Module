#include "Intern.hpp"

// Static array initialization
Intern::FormCreator Intern::_formCreators[3] = {
	{"shrubbery creation", &Intern::createShrubberyForm},
	{"robotomy request", &Intern::createRobotomyForm},
	{"presidential pardon", &Intern::createPresidentialForm}
};

// Default constructor
Intern::Intern()
{
}

// Copy constructor
Intern::Intern(const Intern& other)
{
	(void)other; // Intern has no attributes to copy
}

// Assignment operator
Intern& Intern::operator=(const Intern& other)
{
	(void)other; // Intern has no attributes to assign
	return *this;
}

// Destructor
Intern::~Intern()
{
}

// Form creation
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (int i = 0; i < 3; i++)
	{
		if (formName == _formCreators[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return _formCreators[i].create(target);
		}
	}
	
	std::cout << "Error: Unknown form name \"" << formName << "\"" << std::endl;
	throw UnknownFormException();
}

// Static helper functions
AForm* Intern::createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

// Exception implementation
const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form name!";
}
