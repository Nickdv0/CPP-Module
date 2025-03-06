/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:56:11 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/06 16:16:04 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	FragTrap fragtrap("Fragtrap");
	ScavTrap scavtrap("Scavtrap");
	DiamondTrap diamondtrap("Diamondtrap");

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	
	fragtrap.attack("target");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(3);
	fragtrap.highFivesGuys();

	scavtrap.attack("target");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();

	diamondtrap.attack("target");
	diamondtrap.takeDamage(5);
	diamondtrap.beRepaired(3);
	diamondtrap.whoAmI();

	return 0;
}