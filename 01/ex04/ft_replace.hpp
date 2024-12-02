/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:18:33 by nde-vant          #+#    #+#             */
/*   Updated: 2024/12/02 13:08:32 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REPLACE_HPP
# define FT_REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

int ft_replace(std::ifstream& file, std::ofstream& outfile, std::string s1, std::string s2);

#endif