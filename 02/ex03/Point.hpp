/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:20:50 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/09 17:26:22 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const Point &src);
		Point(const Fixed x, const Fixed y);
		~Point();
		
		Point &operator=(const Point &src);
		
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif