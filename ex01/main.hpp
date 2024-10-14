/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:32 by nde-vant          #+#    #+#             */
/*   Updated: 2024/10/14 15:54:22 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

class Contact {
	private:
		std::string darkestSecret;
		std::string limitString(const std::string& str) const {
			std::string input = str;
			
			while (input.length() == 0)
			{
				std::cout << "Input is empty, please enter a valid input.\nInput: ";
				std::cin >> input;
			}
			if (input.length() > 10)
				return input.substr(0, 9).append(".");
			return input.substr(0, 10);
		}

	public:
		std::string firstName;
    	std::string lastName;
    	std::string nickName;
    	std::string phoneNumber;

    void setfirstName(const std::string& name) { firstName = limitString(name); }
    void setlastName(const std::string& name) { lastName = limitString(name); }
    void setnickName(const std::string& name) { nickName = limitString(name); }
	void setphoneNumber(const std::string& number)
	{	
		std::string	str = number;
		for (std::size_t i = 0; i < str.length(); i++)
		{
			if (!isdigit(number[i]))
			{
				std::cout << "Invalid input, please input numbers only.\n";
				std::cout << "Enter phone number: ";
				std::cin >> str;
				setphoneNumber(str);
				return;
			}
		}
		phoneNumber = limitString(str);
	}
    void setDarkestSecret(const std::string& secret) { darkestSecret = limitString(secret); }

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

	void	SearchContact(const int& index) const
	{
			if (this->contacts[index].firstName.empty())
			{
				
			}
	}
};

#endif