/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:16:11 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/31 11:50:56 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;

// Fixed a; // Default constructor
// std::cout << "a created\n";
// std::cout << "a: " << a.getRawBits() << std::endl; // Should be 0

// a.setRawBits(42);											 // Change value of a
// std::cout << "a after set: " << a.getRawBits() << std::endl; // Should be 42

// Fixed b(a);														 // Copy constructor
// std::cout << "b copied from a: " << b.getRawBits() << std::endl; // Should be 42

// a.setRawBits(100);											  // Change a again
// std::cout << "a changed to: " << a.getRawBits() << std::endl; // Should be 100
// std::cout << "b unchanged: " << b.getRawBits() << std::endl;  // Should still be 42

// Fixed c;											   // Default constructor again
// c = a;												   // Copy assignment
// std::cout << "c = a: " << c.getRawBits() << std::endl; // Should be 100
return 0;
}