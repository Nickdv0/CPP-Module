/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:32 by nde-vant          #+#    #+#             */
/*   Updated: 2024/09/23 17:55:27 by nde-vant         ###   ########.fr       */
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
		std::string DarkestSecret;
		std::string limitString(const std::string& str) const {
			if (str.length() > 10)
				return str.substr(0, 9).append(".");
			return str.substr(0, 10);
		}

	public:
		std::string firstName;
    	std::string lastName;
    	std::string nickName;
    	std::string phoneNumber;

    void setfirstName(const std::string& name) { firstName = limitString(name); }
    void setlastName(const std::string& name) { lastName = limitString(name); }
    void setnickName(const std::string& name) { nickName = limitString(name); }
    void setphoneNumber(const std::string& number) { phoneNumber = limitString(number); }
    void setDarkestSecret(const std::string& secret) { DarkestSecret = limitString(secret); }

    std::string getDarkestSecret(void) const
	{
        return DarkestSecret;
    }
};


class PhoneBook {
	private:
		int		index;

	public:
		Contact contacts[8];
	
	PhoneBook() : index(0) {}
	
	void	AddContact(const std::string& firstName, const std::string& lastName, const std::string& nickName, const std::string& phoneNumber, const std::string& DarkestSecret)
	{
		this->contacts[index].firstName = firstName;
        this->contacts[index].lastName = lastName;
        this->contacts[index].nickName = nickName;
        this->contacts[index].phoneNumber = phoneNumber;
        contacts[index].setDarkestSecret(DarkestSecret);
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