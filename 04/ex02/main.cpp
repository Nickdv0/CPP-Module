/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:47:25 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/11 13:27:30 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal *dog = new Dog();
	const AAnimal *cat = new Cat();
	std::cout <<dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();

	const AAnimal **AAnimalList = new const AAnimal*[100];
	for (int i = 0; i < 50; i++)
	{
		AAnimalList[i] = new Dog();
	}
	for (int i = 50; i < 100; i++)
	{
		AAnimalList[i] = new Cat();
	}

	const Dog* dogFromList = dynamic_cast<const Dog*>(AAnimalList[0]);
	const Cat* catFromList = dynamic_cast<const Cat*>(AAnimalList[50]);
	
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

	delete dog;
	delete cat;
	for (int i = 0; i < 100; i++)
	{
		delete AAnimalList[i];
	}
	delete[] AAnimalList;
	delete dog1;
	delete cat1;
	return 0;
}