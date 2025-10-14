/* ***********************	~Int	AForm*				makeForm(const std::string& formName, const std::string& target);

	class UnknownFormException : public std::exception);

	AForm*				makeForm(const std::string& formName, const std::string& target);*********************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:19:18 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/14 20:53:39 by nde-vant         ###   ########.fr       */
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

   FormCreator _formCreators[3];

   AForm* createShrubberyForm(const std::string& target);
   AForm* createRobotomyForm(const std::string& target);
   AForm* createPresidentialForm(const std::string& target);
};

#endif
