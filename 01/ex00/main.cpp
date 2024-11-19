/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:37:16 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/19 11:42:06 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	randomChump("randomChump");

	Zombie *zombie = newZombie("newZombie");
	zombie->announce();
	delete zombie;

	Zombie *zombie2 = newZombie("newZombie2");
	zombie2->announce();

	randomChump("randomChump");

	delete zombie2;
	return (0); 
}