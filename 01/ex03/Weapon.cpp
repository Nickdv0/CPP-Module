/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:44:12 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/20 17:02:22 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("fist") {
	return;
}

Weapon::Weapon(const std::string type) : type(type) {
	return;
}

Weapon::~Weapon(void) {
	return;
}

const std::string& Weapon::getType(void) const {
	return (this->type);
}

void Weapon::setType(const std::string type) {
	this->type = type;
}
