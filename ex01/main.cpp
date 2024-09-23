/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:29:31 by nde-vant          #+#    #+#             */
/*   Updated: 2024/09/23 17:32:29 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	PhoneBook phoneBook;
	std::string input;

	while (true)
	{
		std::cout << "Enter one of the following commands :\n\t- ADD\n\t- SEARCH\n\t- EXIT\n";
		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (std::string("ADD").compare(input) == 0)
		{
			std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
    		std::cout << "Enter first name: ";
    		std::cin >> firstName;
			std::cout << "Enter last name: ";
			std::cin >> lastName;
			std::cout << "Enter nick name: ";
			std::cin >> nickName;
			std::cout << "Enter phone number: ";
			std::cin >> phoneNumber;
			std::cout << "Enter darkes secret: ";
			std::cin >> darkestSecret;
			phoneBook.AddContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
		}
		else if (std::string("SEARCH").compare(input) == 0)
			phoneBook.printContacts() ;
		else if (std::string("EXIT").compare(input) == 0)
			break ;
		else
			std::cout << "Invalid command. Please try again.\n";
	}
	std::cout << "Exiting program.\n";
	return (0);
}
