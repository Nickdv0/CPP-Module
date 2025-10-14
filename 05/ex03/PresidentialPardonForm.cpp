/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:19:24 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/14 21:10:54 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
	: AForm(other), _target(other._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
