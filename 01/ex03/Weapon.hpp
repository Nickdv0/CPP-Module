/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:44:15 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/19 17:39:09 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	private:
	std::string type;

	public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	const std::string& getType(void) const;
	void setType(std::string type);

};

#endif
