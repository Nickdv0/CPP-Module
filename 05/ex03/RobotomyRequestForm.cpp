/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:23:42 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/15 18:23:44 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("default")
{
}


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", 72, 45), _target(target)
{
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
}


const std::string& RobotomyRequestForm::getTarget() const
{
	return _target;
}


void RobotomyRequestForm::executeAction() const
{

	std::cout << "* DRILLING NOISES * BZZZZT * WHIRRRR * CLANK *" << std::endl;


	std::srand(std::time(0));


	if (std::rand() % 2)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "The robotomy of " << _target << " failed!" << std::endl;
	}
}
