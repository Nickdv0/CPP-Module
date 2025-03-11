/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:47:25 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 14:23:03 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout <<dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_cat->makeSound();
	wrong_meta->makeSound();

	delete meta;
	delete dog;
	delete cat;
	delete wrong_meta;
	delete wrong_cat;
	return 0;
}