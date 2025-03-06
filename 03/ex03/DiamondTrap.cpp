/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:57:47 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/06 16:15:18 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name) {
	std::cout << "DiamondTrap name constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &src) {
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	return *this;
}

void DiamondTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < 1)
		return ;
	std::cout << "DiamondTrap " << this->_name
		<< " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}

void DiamondTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
		return ;
	std::cout << "DiamondTrap " << this->_name
		<< " is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << this->_name
		<< " and ClapTrap name is " << ClapTrap::_name << std::endl;
}