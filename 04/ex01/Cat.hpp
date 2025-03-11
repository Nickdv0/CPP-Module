/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:42:49 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 17:08:58 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const Cat &src);
		~Cat();

		Cat & operator=(const Cat &src);

		void makeSound() const;
		std::string getIdeas(int index) const;
		void setIdea(int index, std::string idea);
};

#endif