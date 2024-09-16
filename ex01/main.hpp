/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:32 by nde-vant          #+#    #+#             */
/*   Updated: 2024/09/16 17:01:31 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>

class PhoneBook {
	public:
		int		index = 0;
		Contact contacts[8];
	
	void	AddContact(std::string FirstName, std::string LastName, std::string	NickName, std::string PhoneNumber, std::string DarkestSecret)
	{
		
	}

	void	SearchContact(std::string KeyWord)
	{
		
	}
};

class Contact {
	private:
		std::string DarkestSecret[11];
	public:
		std::string FirstName[11];
		std::string LastName[11];
		std::string	NickName[11];
		std::string	PhoneNumber[11];
};

#endif