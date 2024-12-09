/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:13:50 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/09 14:55:37 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int value;
		static const int fractionalBits= 8;
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();
		void setRawBits(int const raw);
		int getRawBits(void) const;
		Fixed &operator=(const Fixed &src);
		friend std::ostream &operator<<(std::ostream &o, const Fixed &src);
		float toFloat(void) const;
		int toInt(void) const;
		
};

#endif