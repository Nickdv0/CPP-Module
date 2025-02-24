/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:13:50 by nde-vant          #+#    #+#             */
/*   Updated: 2025/02/24 14:48:14 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int 				_value;
		static const int	_fractionalBits= 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &src);
		
		Fixed &operator=(const Fixed &src);
		
		void setRawBits(int const raw);
		int getRawBits(void) const;
};

#endif