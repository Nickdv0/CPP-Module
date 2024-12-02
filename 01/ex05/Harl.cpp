/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:25:56 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/02 15:12:18 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {
	//std::cout << "Harl created" << std::endl;
}

Harl::~Harl(void) {
	//std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug(void) const {
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. " 
	<< "I really do!" << std::endl;
}

void Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon cost more money. "
	<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" 
	<< std::endl;
}

void Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. " 
	<< "I’ve been coming for years whereas you started working here since last month." 
	<< std::endl;
}

void Harl::error(void) const{
	std::cout << "This is unacceptable! I want to speak to the manager now." 
	<< std::endl;
}

void Harl::complain(const std::string& level) const {
	
	void (Harl::*func[])(void) const = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (size_t i = 0; i < levels->size(); i++)
	{
		if (levels[i] == level)
		{
			(this->*func[i])();
			return;
		}
	}
}