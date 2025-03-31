/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:16:11 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/31 12:10:10 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	// Fixed a;
	// Fixed const b(Fixed(5.05f) * Fixed(2));
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "===== CONSTRUCTORS =====\n";
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	std::cout << "\n===== COMPARISON OPERATORS =====\n";
	std::cout << "b == d ? " << (b == d) << std::endl; // Should be 1 (true)
	std::cout << "b != c ? " << (b != c) << std::endl; // Should be 1 (true)
	std::cout << "b > c ? " << (b > c) << std::endl;   // Should be 0 (false)
	std::cout << "b < c ? " << (b < c) << std::endl;   // Should be 1 (true)
	std::cout << "b >= d ? " << (b >= d) << std::endl; // Should be 1 (true)
	std::cout << "c <= b ? " << (c <= b) << std::endl; // Should be 0 (false)

	std::cout << "\n===== ARITHMETIC OPERATORS =====\n";
	Fixed e = b + c; // 10 + 42.42
	Fixed f = c - b; // 42.42 - 10
	Fixed g = b * c; // 10 * 42.42
	Fixed h = c / b; // 42.42 / 10

	std::cout << "b + c = " << e << std::endl; // ~52.42
	std::cout << "c - b = " << f << std::endl; // ~32.42
	std::cout << "b * c = " << g << std::endl; // ~424.2
	std::cout << "c / b = " << h << std::endl; // ~4.242

	std::cout << "\n===== INCREMENT/DECREMENT =====\n";
	Fixed i(5.05f);

	std::cout << "i = " << i << std::endl;	   // 5.05
	std::cout << "++i = " << ++i << std::endl; // ~5.05 + 0.00390625
	std::cout << "i = " << i << std::endl;	   // Same as above
	std::cout << "i++ = " << i++ << std::endl; // Same as above
	std::cout << "i = " << i << std::endl;	   // ~5.05 + 0.0078125
	std::cout << "--i = " << --i << std::endl; // Back to previous value
	std::cout << "i = " << i << std::endl;	   // Same as above
	std::cout << "i-- = " << i-- << std::endl; // Same as above
	std::cout << "i = " << i << std::endl;	   // Back to ~5.05

	std::cout << "\n===== STATIC MIN/MAX =====\n";
	Fixed j(100);
	Fixed k(200);

	std::cout << "min(j, k) = " << Fixed::min(j, k) << std::endl; // 100
	std::cout << "max(j, k) = " << Fixed::max(j, k) << std::endl; // 200

	const Fixed m(300);
	const Fixed n(400);

	std::cout << "min(m, n) = " << Fixed::min(m, n) << std::endl; // 300
	std::cout << "max(m, n) = " << Fixed::max(m, n) << std::endl; // 400

	std::cout << "\n===== COMPLEX EXPRESSION =====\n";
	Fixed complex = Fixed(5.05f) * Fixed(2) + Fixed(3); // From subject test
	std::cout << "5.05 * 2 + 3 = " << complex << std::endl;
	return 0;
}