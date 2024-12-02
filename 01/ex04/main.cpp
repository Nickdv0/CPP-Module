/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:11:16 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/02 13:08:37 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of arguments. Please enter 3 arguments" << std::endl;
		return (1);
	}
	if (argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cerr << "Error: Invalid arguments. Please enter 3 non-empty arguments" << std::endl;
		return (2);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1 == s2)
	{
		std::cerr << "Error: s1 and s2 are the same" << std::endl;
		return (5);
	}

	std::ifstream file(filename.c_str());
	
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file" << std::endl;
		return (3);
	}

	std::ofstream outfile;
	
	outfile.open(filename + ".replace");
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create output file" << std::endl;
		return (4);
	}

	ft_replace(file, outfile, s1, s2);
	
	outfile.close();
	file.close();
	return (0);
}