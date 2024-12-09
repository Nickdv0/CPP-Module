/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:13:50 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/09 11:13:10 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int value;
		static const int fractionalBits= 8;
	public:
		Fixed();
		~Fixed();
		void setRawBits(int const raw);
		int getRawBits(void) const;
		Fixed &operator=(const Fixed &src);
		Fixed(const Fixed &src);
};

#endif