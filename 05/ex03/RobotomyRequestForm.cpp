/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:19:30 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/14 21:10:54 by nde-vant         ###   ########.fr       */
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
	// Make drilling noises
	std::cout << "* DRILLING NOISES * BZZZZT * WHIRRRR * CLANK *" << std::endl;
	
	// Use current time as seed for randomness
	std::srand(std::time(0));
	
	// 50% chance of success
	if (std::rand() % 2)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "The robotomy of " << _target << " failed!" << std::endl;
	}
}
