/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:29:31 by nde-vant          #+#    #+#             */
/*   Updated: 2024/10/22 14:02:24 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string Contact::limitString(const std::string& str) const 
{
	std::string input = str;
	
	while (input.length() == 0)
	{
		std::cout << "Input is empty, please enter a valid input.\nInput: ";
		std::cin >> input;
	}
	if (input.length() > 10)
		return (input.substr(0, 9).append("."));
	else if (input.length() < 10)
		return (input.append("         ", 0, input.length() - 10));
	return (input.substr(0, 10));
}

void	Contact::setfirstName(const std::string& name)
{
	firstName = name;
}
void	Contact::setlastName(const std::string& name)
{
	lastName = name;
}
void	Contact::setnickName(const std::string& name)
{
	nickName = name;
}
void	Contact::setphoneNumber(const std::string& number)
{	
	std::string	str = number;
	
	if (!check_digit(str))
		setphoneNumber(str);
	phoneNumber = str;
}
void	Contact::setDarkestSecret(const std::string& secret)
{
	darkestSecret = secret;
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
			std::cout << "Invalid input, please input numbers only.\nInput: ";
			std::cin >> number;
			return (false);
		}
	}
	return (true);
}
PhoneBook::PhoneBook(void)
{
	index = 0;
}

void	PhoneBook::AddContact(void)
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
   	std::cout << "Enter first name: ";
   	std::cin >> firstName;
	this->contacts[index].setfirstName(firstName);
	std::cout << "Enter last name: ";
	std::cin >> lastName;
       this->contacts[index].setlastName(lastName);
	std::cout << "Enter nick name: ";
	std::cin >> nickName;
       this->contacts[index].setnickName(nickName);
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
       this->contacts[index].setphoneNumber(phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
       contacts[index].setDarkestSecret(darkestSecret);
	index = (index + 1) % 8;
}

void	PhoneBook::printContacts(void) const {
	for (int i = 0; !this->contacts[i].firstName.empty() && i < 8; i++)
	{
		std::cout << i << ' ' << this->contacts[i].firstName << ' ' << this->contacts[i].lastName
		<< this->contacts[i].nickName << ' ' << this->contacts[i].phoneNumber
		<< ' ' << this->contacts[i].getDarkestSecret() << '\n';
	}
}

void	PhoneBook::SearchContact(std::string& index)
{
	std::string input = index;
	int searchIndex;
	
	if (!check_digit(input))
	{
		SearchContact(input);
		return ;
	}
	searchIndex = atoi(input.c_str()) - 1;
	for (int i = 0; !this->contacts[i].firstName.empty() && i < 8; i++)
	{
		if (searchIndex == i)
		{
		std::cout << this->contacts[i].limitString(this->contacts[i].firstName) << '|'
				<< this->contacts[i].limitString(this->contacts[i].lastName) << '|'
				<< this->contacts[i].limitString(this->contacts[i].nickName) << '|'
				<< this->contacts[i].limitString(this->contacts[i].phoneNumber) << '\n';
		return ;
		}
	}
	std::cout <<  "Non-existant contact or wrong index\n";
	return ;
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
