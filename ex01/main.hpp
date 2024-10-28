/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:32 by nde-vant          #+#    #+#             */
/*   Updated: 2024/10/22 14:15:39 by nde-vant         ###   ########.fr       */
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
	
	std::string limitString(const std::string& str) const;
    void setfirstName(const std::string& name);
	void setlastName(const std::string& name);
	void setnickName(const std::string& name);
	void setphoneNumber(const std::string& number);
	void setDarkestSecret(const std::string& secret);
	std::string Contact::getDarkestSecret(void) const;
};


class PhoneBook {
	private:
		int		index;

	public:
		Contact contacts[8];
	
	PhoneBook(void);
	~PhoneBook(void);
	void	AddContact(void);
	void	printContacts(void) const;
	void	SearchContact(std::string& index);
};

#endif