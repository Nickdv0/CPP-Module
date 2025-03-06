/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:50:57 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/06 16:33:23 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &src) {
	std::cout << "FragTrap assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void FragTrap::attack(std::string const &target) {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
		return ;
	std::cout << "FragTrap " << this->_name
		<< " attacks " << target << ", causing "
		<< this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints < 1)
		return ;
	std::cout << "FragTrap " << this->_name
		<< " takes " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
		return ;
	std::cout << "FragTrap " << this->_name
		<< " is repaired for " << amount << " points!" << std::endl;
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
}

void FragTrap::highFivesGuys() {
	if (this->_energyPoints < 1 || this->_hitPoints < 1)
		return ;
	std::cout << "FragTrap " << this->_name
		<< " high fives guys!" << std::endl;
}