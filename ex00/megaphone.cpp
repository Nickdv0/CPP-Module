/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:45:59 by nde-vant          #+#    #+#             */
/*   Updated: 2024/09/12 14:25:54 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	toUpper(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] >= 'a' && string[i] <= 'z')
		{
			string[i] -= 32;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else if (argc > 1)
	{
		while (argv[++i])
		{
			toUpper(argv[i]);
			std::cout << argv[i];
		}
		std::cout << '\n';
	}
	return (0);
}