/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:47:25 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 17:16:09 by nde-vant         ###   ########.fr       */
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

	const Animal **animalList = new const Animal*[100];
	for (int i = 0; i < 50; i++)
	{
		animalList[i] = new Dog();
	}
	for (int i = 50; i < 100; i++)
	{
		animalList[i] = new Cat();
	}

	const Dog* dogFromList = dynamic_cast<const Dog*>(animalList[0]);
	const Cat* catFromList = dynamic_cast<const Cat*>(animalList[50]);
	
	std::cout << dogFromList->getIdeas(0) << std::endl;
	std::cout << catFromList->getIdeas(0) << std::endl;

	Dog* dog1 = new Dog();
	Cat* cat1 = new Cat();

	std::cout << dog1->getIdeas(0) << std::endl;
	std::cout << cat1->getIdeas(0) << std::endl;
	dog1->setIdea(0, "new idea");
	std::cout << dog1->getIdeas(0) << std::endl;
	std::cout << cat1->getIdeas(0) << std::endl;
	std::cout << dogFromList->getIdeas(0) << std::endl;
	std::cout << catFromList->getIdeas(0) << std::endl;	

	delete meta;
	delete dog;
	delete cat;
	for (int i = 0; i < 100; i++)
	{
		delete animalList[i];
	}
	delete[] animalList;
	delete dog1;
	delete cat1;
	return 0;
}