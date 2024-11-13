/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:32 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/13 14:07:08 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include "Contact.hpp"

bool	check_digit(std::string& number);

class PhoneBook {
	private:
		int		index;
		Contact contacts[8];
		
	public:
	
	PhoneBook(void);
	~PhoneBook(void);
	void	AddContact(void);
	void	AddContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
	void	SearchContact(std::string& index);

	//testing
	void	printContact(size_t index) const;
	void	fillPhonebook(void);
};

#endif