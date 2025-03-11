/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:24:56 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 16:26:30 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
	protected:
		std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain & src);
		~Brain();

		Brain &operator=(const Brain & src);

		std::string *getIdeas();
		void setIdea(int index, std::string idea);
};

#endif