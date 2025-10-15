/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:18:42 by nde-vant          #+#    #+#             */
/*   Updated: 2025/08/10 07:18:43 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("default")
{
}

// Parametric constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), _target(other._target)
{
}

// Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// Getter
const std::string& PresidentialPardonForm::getTarget() const
{
	return _target;
}

// Implementation of pure virtual function
void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
