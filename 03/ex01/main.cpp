/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:56:11 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/06 15:49:43 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	ScavTrap scavtrap("Scavtrap");
	
	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	scavtrap.attack("target");
	scavtrap.takeDamage(5);
	scavtrap.beRepaired(3);
	scavtrap.guardGate();

	return 0;
}