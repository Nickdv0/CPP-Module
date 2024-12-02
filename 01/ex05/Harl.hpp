/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:25:36 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/02 15:01:11 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	private:
		void debug(void) const;
		void info(void) const;
		void warning(void) const;
		void error(void) const;
	public:
		Harl(void);
		~Harl(void);
		void complain(const std::string& level) const;
};

#endif