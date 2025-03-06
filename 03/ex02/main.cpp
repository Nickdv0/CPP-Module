/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:56:11 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/06 15:55:40 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	FragTrap fragtrap("Fragtrap");

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	
	fragtrap.attack("target");
	fragtrap.takeDamage(5);
	fragtrap.beRepaired(3);
	fragtrap.highFivesGuys();

	return 0;
}