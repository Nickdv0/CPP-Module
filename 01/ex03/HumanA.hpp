/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:43:56 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/19 17:09:44 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	private:
	std::string name;
	Weapon& weapon;

	public:
	HumanA(void);
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void attack(void);
};

#endif