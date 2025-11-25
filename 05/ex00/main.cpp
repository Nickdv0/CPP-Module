/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:18:03 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/15 18:13:52 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Testing Bureaucrat Class ===" << std::endl;

	try
	{
		std::cout << "\n1. Creating valid bureaucrats:" << std::endl;
		Bureaucrat bob("Bob", 50);
		Bureaucrat alice("Alice", 1);
		Bureaucrat charlie("Charlie", 150);

		std::cout << bob << std::endl;
		std::cout << alice << std::endl;
		std::cout << charlie << std::endl;

		std::cout << "\n2. Testing grade increment:" << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;

		std::cout << "\n3. Testing grade decrement:" << std::endl;
		bob.decrementGrade();
		std::cout << "After decrement: " << bob << std::endl;

		std::cout << "\n4. Testing edge cases:" << std::endl;


		try
		{
			alice.incrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}


		try
		{
			charlie.decrementGrade();
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\n5. Testing invalid constructor parameters:" << std::endl;


		try
		{
			Bureaucrat invalid1("Invalid1", 0);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}


		try
		{
			Bureaucrat invalid2("Invalid2", 151);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\n6. Testing copy constructor and assignment:" << std::endl;
		Bureaucrat copy(bob);
		std::cout << "Copy: " << copy << std::endl;

		Bureaucrat assigned("Temp", 100);
		assigned = bob;
		std::cout << "Assigned: " << assigned << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
