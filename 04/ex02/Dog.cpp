/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:41:49 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 17:33:28 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : AAnimal(src) {
	*this = src;
	this->_brain = new Brain(*(src._brain));
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &Dog::operator=(const Dog &src) {
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void	Dog::makeSound() const {
	std::cout << "Bark" << std::endl;
}

std::string Dog::getIdeas(int index) const {
	return this->_brain->getIdeas()[index];
}

void	Dog::setIdea(int index, std::string idea) {
	this->_brain->setIdea(index, idea);
}

