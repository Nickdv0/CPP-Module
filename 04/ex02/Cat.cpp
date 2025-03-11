/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:43:43 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 17:33:28 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : AAnimal(src) {
	*this = src;
	this->_brain = new Brain(*(src._brain));
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(const Cat &src) {
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}

std::string Cat::getIdeas(int index) const {
	return this->_brain->getIdeas()[index];
}

void	Cat::setIdea(int index, std::string idea) {
	this->_brain->setIdea(index, idea);
}