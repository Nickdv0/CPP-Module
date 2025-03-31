/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:16:11 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/31 12:00:02 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
// Fixed a;
// Fixed const b( 10 );
// Fixed const c( 42.42f );
// Fixed const d( b );
// a = Fixed( 1234.4321f );
// std::cout << "a is " << a << std::endl;
// std::cout << "b is " << b << std::endl;
// std::cout << "c is " << c << std::endl;
// std::cout << "d is " << d << std::endl;
// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
// std::cout << "d is " << d.toInt() << " as integer" << std::endl;

std::cout << "----- Testing Constructors -----\n";
Fixed a;		   // Default constructor
Fixed b(42);	   // Int constructor
Fixed c(3.14159f); // Float constructor
Fixed d(b);		   // Copy constructor

std::cout << "\n----- Output Operator Test -----\n";
std::cout << "a (default): " << a << std::endl;		  // Should be 0
std::cout << "b (int 42): " << b << std::endl;		  // Should be 42
std::cout << "c (float 3.14159): " << c << std::endl; // Should be ~3.14159 inaccuracy is expected if low fractional bits
std::cout << "d (copy of b): " << d << std::endl;	  // Should be 42

std::cout << "\n----- toInt() Conversion Test -----\n";
std::cout << "b as int: " << b.toInt() << std::endl; // Should be 42
std::cout << "c as int: " << c.toInt() << std::endl; // Should be 3

std::cout << "\n----- toFloat() Conversion Test -----\n";
std::cout << "b as float: " << b.toFloat() << std::endl; // Should be 42.0
std::cout << "c as float: " << c.toFloat() << std::endl; // Should be ~3.14159 inaccuracy is expected if low fractional bits

std::cout << "\n----- Assignment Operator Test -----\n";
Fixed e;								  // Default constructor
e = c;									  // Assignment operator
std::cout << "e = c: " << e << std::endl; // Should match c

std::cout << "\n----- Precision Test -----\n";
Fixed f(0.125f); // 1/8 (exactly representable with 8 bits)
Fixed g(0.1f);	 // Not exactly representable with 8 bits
std::cout << "f (0.125): " << f << std::endl;
std::cout << "g (0.1): " << g << std::endl;
return 0;
}