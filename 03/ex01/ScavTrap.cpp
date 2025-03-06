/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:41:17 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/06 15:48:40 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src) {
	std::cout << "ScavTrap assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void ScavTrap::attack(std::string const &target) {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
		return ;
	std::cout << "ScavTrap " << this->_name
		<< " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < 1)
		return ;
	std::cout << "ScavTrap " << this->_name
		<< " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
		return ;
	std::cout << "ScavTrap " << this->_name
		<< " is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name
		<< " has entered Gate keeper mode!" << std::endl;
}