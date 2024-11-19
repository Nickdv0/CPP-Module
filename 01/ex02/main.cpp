/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:13:55 by nde-vant          #+#    #+#             */
/*   Updated: 2024/11/19 14:33:36 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int		main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Pointer address: " << stringPTR << std::endl;
	std::cout << "Reference address: " << &stringREF << std::endl;

	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl;

	// *pointer = "HI THIS IS NEW BRAIN";

	// std::cout << "Pointer value: " << *pointer << std::endl;
	// std::cout << "Reference value: " << ref << std::endl;

	// ref = "HI THIS IS NEW NEW BRAIN";

	// std::cout << "Pointer value: " << *pointer << std::endl;
	// std::cout << "Reference value: " << ref << std::endl;
	return (0);
}