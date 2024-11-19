/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:13:55 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/19 14:32:46 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	pointer = &str;
	std::string&	ref = str;

	std::cout << "Pointer address: " << pointer << std::endl;
	std::cout << "Reference address: " << &ref << std::endl;

	std::cout << "Pointer value: " << *pointer << std::endl;
	std::cout << "Reference value: " << ref << std::endl;

	// *pointer = "HI THIS IS NEW BRAIN";

	// std::cout << "Pointer value: " << *pointer << std::endl;
	// std::cout << "Reference value: " << ref << std::endl;

	// ref = "HI THIS IS NEW NEW BRAIN";

	// std::cout << "Pointer value: " << *pointer << std::endl;
	// std::cout << "Reference value: " << ref << std::endl;
	return (0);
}