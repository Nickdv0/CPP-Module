/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:49:02 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/19 11:36:46 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	
	public:
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	
	void announce(void);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif