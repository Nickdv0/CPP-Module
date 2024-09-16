/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:29:31 by nde-vant          #+#    #+#             */
/*   Updated: 2024/09/16 16:50:06 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	std::string input;
	while (true)
	{
		std::cout << "Enter one of the following commands :\n\tADD\n\tSEARCH\n\tEXIT\n";
		std::cin >> input;
		if (std::string("ADD").compare(input))
			continue ;
		else if (std::string("SEARCH").compare(input))
			continue ;
		else if (std::string("EXIT").compare(input))
			break ;
		else
			std::cout << "Invalid command. Please try again.\n";
	}
	std::cout << "Exiting program.\n";
	return (0);
}
