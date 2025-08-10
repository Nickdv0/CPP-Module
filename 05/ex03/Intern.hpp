/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:19:18 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:19:19 by nde-vant         ###   ########.fr       */
/*                                                                            */
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
	// Orthodox Canonical Form
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	// Form creation
	AForm*	makeForm(const std::string& formName, const std::string& target);

	// Exception class
	class UnknownFormException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

private:
	// Helper structure for form creation
	struct FormCreator
	{
		std::string name;
		AForm* (*create)(const std::string& target);
	};

	// Static array of form creators
	static FormCreator _formCreators[3];

	// Static helper functions
	static AForm* createShrubberyForm(const std::string& target);
	static AForm* createRobotomyForm(const std::string& target);
	static AForm* createPresidentialForm(const std::string& target);
};

#endif
