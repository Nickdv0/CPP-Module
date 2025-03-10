/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:56:11 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/06 15:18:32 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2 = claptrap;

	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	claptrap2.attack("target");
	claptrap2.takeDamage(5);
	claptrap2.beRepaired(3);

	return 0;
}