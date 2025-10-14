/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:19:15 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/14 21:12:16 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::FormCreator defaultFormCreators[3] = {
	{"shrubbery creation", &Intern::createShrubberyForm},
	{"robotomy request", &Intern::createRobotomyForm},
	{"presidential pardon", &Intern::createPresidentialForm}
};

Intern::Intern()
{
	for (int i = 0; i < 3; ++i)
		 _formCreators[i] = defaultFormCreators[i];
}

Intern::Intern(const Intern& other)
{
	(void)other; // Intern has no attributes to copy
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other; // Intern has no attributes to assign
	return *this;
}

Intern::~Intern()
{
}

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

const char* Intern::UnknownFormException::what() const throw()
{
	return "Unknown form name!";
}
