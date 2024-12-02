/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:25:22 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/02 17:00:03 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Please enter an argument. [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return (1);
	}

	Harl harl;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	for (; i < 4; i++)
	{
		if (levels[i] == argv[1])
			break;
	}
	
	switch (i)
	{
	case 0:
		harl.complain(0);
	case 1:
		harl.complain(1);
	case 2:
		harl.complain(2);
	case 3:
		harl.complain(3);
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	
	return (0);
}