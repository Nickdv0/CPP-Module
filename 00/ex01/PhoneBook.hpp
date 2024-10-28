/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:36:32 by nde-vant          #+#    #+#             */
/*   Updated: 2024/10/28 14:20:28 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
#define MAIN_HPP

#include "Contact.hpp"

bool	check_digit(std::string& number);

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