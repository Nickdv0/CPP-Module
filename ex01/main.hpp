/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:32 by nde-vant          #+#    #+#             */
/*   Updated: 2024/10/21 15:23:16 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include "main.hpp"

bool	check_digit(std::string& number);

class Contact {
	private:
		std::string darkestSecret;

	public:
		std::string firstName;
    	std::string lastName;
    	std::string nickName;
    	std::string phoneNumber;
	
	std::string limitString(const std::string& str) const 
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
    void setfirstName(const std::string& name) { firstName = name; }
    void setlastName(const std::string& name) { lastName = name; }
    void setnickName(const std::string& name) { nickName = name; }
	void setphoneNumber(const std::string& number)
	{	
		std::string	str = number;
		
		if (!check_digit(str))
			setphoneNumber(str);
		phoneNumber = str;
	}
    void setDarkestSecret(const std::string& secret) { darkestSecret = secret; }

    std::string getDarkestSecret(void) const
	{
        return darkestSecret;
    }
};


class PhoneBook {
	private:
		int		index;

	public:
		Contact contacts[8];
	
	PhoneBook() : index(0) {}
	
	void	AddContact(void)
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

	void	printContacts(void) const {
		for (int i = 0; !this->contacts[i].firstName.empty() && i < 8; i++)
		{
			std::cout << i << ' ' << this->contacts[i].firstName << ' ' << this->contacts[i].lastName
			<< this->contacts[i].nickName << ' ' << this->contacts[i].phoneNumber
			<< ' ' << this->contacts[i].getDarkestSecret() << '\n';
		}
	}

	void	SearchContact(std::string& index)
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
};

#endif