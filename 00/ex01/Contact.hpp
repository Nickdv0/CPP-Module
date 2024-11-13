/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:18:22 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/13 16:48:22 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string darkestSecret;
		std::string firstName;
    	std::string lastName;
    	std::string nickName;
    	std::string phoneNumber;
	
	public:
	
	std::string limitString(const std::string& str) const;
	std::string getDarkestSecret(void) const;
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickName(void) const;
	std::string getPhoneNumber(void) const;
	Contact(void);
	Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret);
	~Contact(void);
	
	
};

#endif