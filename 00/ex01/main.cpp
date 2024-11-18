/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:29:31 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/18 14:19:35 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

int containOnlySpace(std::string str)
{
	for (std::size_t i = 0; i < 9 && str[i] != '\0'; i++)
	{
		if (std::isspace(str[i]) == 0)
			return (0);
	}
	return (1);
}

int ft_strcmp(std::string s1, std::string s2)
{
	if (s1.length() != s2.length())
		return (1);
	for (std::size_t i = 0; i < s1.length(); i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}

Contact::Contact(void)
{
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

Contact::Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::~Contact(void)
{
	return ;
}

std::string Contact::limitString(const std::string& str) const 
{
	std::string input = str;
	
	if (input[9] == ' ')
	{
		input = input.substr(0, 9);
	}
	if (input.length() > 10)
	{
		return (input.substr(0, 9).append("."));
	}
	else if (input.length() < 10)
	{
		return (input.append("         ", 0, input.length() - 10).substr(0, 10));
	}
	return (input.substr(0, 10));
}

std::string Contact::getFirstName(void) const
{
	return firstName;
}

std::string Contact::getLastName(void) const
{
	return lastName;
}

std::string Contact::getNickName(void) const
{
	return nickName;
}

std::string Contact::getPhoneNumber(void) const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return darkestSecret;
}

bool	check_digit(std::string& number)
{
	for (std::size_t i = 0; i < number.length(); i++)
	{
		if (!isdigit(number[i]))
		{
			std::cout << "Invalid input, please input numbers only.\nInput: " << std::endl;
			std::getline(std::cin, number);
			return (false);
		}
	}
	return (true);
}
PhoneBook::PhoneBook(void)
{
	index = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::AddContact(void)
{
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

	do
	{
		std::cout << "Please enter the following information:\nFirst Name: " << std::endl;
		std::getline(std::cin, firstName);
	} while (containOnlySpace(firstName));
	do 
	{
		std::cout << "Last Name: " << std::endl;
		std::getline(std::cin, lastName);
	} while (containOnlySpace(lastName));
	do
	{
		std::cout << "Nick Name: " << std::endl;
		std::getline(std::cin, nickName);
	} while (containOnlySpace(nickName));
	std::cout << "Phone Number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	check_digit(phoneNumber);
	do
	{
		std::cout << "Darkest Secret: " << std::endl;
		std::getline(std::cin, darkestSecret);
	} while (containOnlySpace(darkestSecret));
	contacts[index] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	index = (index + 1) % 8;
}

void	PhoneBook::AddContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
	contacts[index] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	index = (index + 1) % 8;
}

void	PhoneBook::fillPhonebook(void) 
{
	AddContact("John", "Doe", "JD", "0987654321", "I am a student at 42.");
	AddContact("Jane", "Duck", "JD", "1234567890", "I am a student at 42.");
	AddContact("Jack", "Richard", "JD", "2345678901", "I am a student at 42.");
	AddContact("Jill", "Drow", "JD", "3456789012", "I am a student at 42.");
	AddContact("Jenny", "Drack", "JD", "4567890123", "I am a student at 42.");
	AddContact("Jeremy", "Dewey", "JD", "5678901234", "I am a student at 42.");
	AddContact("Jesse", "Dew", "JD", "6789012345", "I am a student at 42.");
	AddContact("Jared", "Dali", "JD", "7890123456", "I am a student at 42.");
	//overwriting first contact
	AddContact("Jasper lakdfjla", "Dre akjfhkas", "JD", "890123456709", "I am a student at 42.");
}

void	PhoneBook::printContact(size_t index) const 
{
	std::cout << contacts[index].limitString(contacts[index].getFirstName()) << '|'
			<< contacts[index].limitString(contacts[index].getLastName()) << '|'
			<< contacts[index].limitString(contacts[index].getNickName()) << '|'
			<< contacts[index].limitString(contacts[index].getPhoneNumber()) << std::endl;
}

void	PhoneBook::SearchContact(std::string& index)
{
	int indexInt = std::atoi(index.c_str());
	if (indexInt < 1 || indexInt > 8)
	{
		std::cout << "Invalid index. Please try again." << std::endl;
		return ;
	}
	for (int i = 0; i < 8; i++)
	{
		if (i == indexInt - 1 && contacts[i].getFirstName().length() > 0)
		{
			printContact(i);
			return ;
		}
	}
	std::cout << "Selected index is empty." << std::endl;
}

int	main(void)
{
	PhoneBook phoneBook;
	std::string input;

	// phoneBook.fillPhonebook();
	while (true)
	{
		std::cout << "Enter one of the following commands :\n\t- ADD\n\t- SEARCH\n\t- EXIT" << std::endl;
		std::getline(std::cin, input);
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (ft_strcmp(input, "ADD") == 0)
		{
			phoneBook.AddContact();
		}
		else if (ft_strcmp(input, "SEARCH") == 0)
		{
			std::cout << "Please input contact index\nInput: " << std::endl;
			std::getline(std::cin, input);
			check_digit(input);
			phoneBook.SearchContact(input);
		}
		else if (ft_strcmp(input, "EXIT") == 0)
			break ;
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	std::cout << "Exiting program." << std::endl;
	return (0);
}
