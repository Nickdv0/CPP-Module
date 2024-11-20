/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:44:02 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/20 13:41:10 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
	std::string name;
	Weapon *weapon;

	public:
	HumanB(void);
	HumanB(const std::string name);
	~HumanB(void);

	void attack(void) const;
	void setWeapon(Weapon& weapon);
};

#endif