/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:18:22 by nde-vant          #+#    #+#             */
/*   Updated: 2024/10/28 14:21:21 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

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
	std::string getDarkestSecret(void) const;
};

#endif