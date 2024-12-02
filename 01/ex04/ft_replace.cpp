/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:18:20 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/02 13:08:49 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_replace.hpp"

int ft_replace(std::ifstream& file, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;
	
	while (file.good())
	{
		size_t pos = 0;
		std::getline(file, line);
		while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
		outfile << line << std::endl;
	}
	return (0);
}