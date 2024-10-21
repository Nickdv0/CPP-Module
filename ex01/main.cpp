/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:29:31 by nde-vant          #+#    #+#             */
/*   Updated: 2024/10/21 15:00:01 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool	check_digit(std::string& number)
{
	for (std::size_t i = 0; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
		{
			std::cout << "Invalid input, please input numbers only.\nInput: ";
			std::cin >> number;
			return (false);
		}
	}
	return (true);
}

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
			phoneBook.AddContact();
		}
		else if (std::string("SEARCH").compare(input) == 0)
		{
			std::cout << "Please input contact index\nInput: ";
			std::cin >> input;
			phoneBook.SearchContact(input);
			// phoneBook.printContacts() ; test to see whole phonebook
		}
		else if (std::string("EXIT").compare(input) == 0)
			break ;
		else
			std::cout << "Invalid command. Please try again.\n";
	}
	std::cout << "Exiting program.\n";
	return (0);
}
