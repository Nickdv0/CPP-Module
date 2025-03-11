/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:47:48 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 17:09:05 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog &src);
		~Dog();

		Dog & operator=(const Dog &src);

		void makeSound() const;	
		std::string getIdeas(int index)const;
		void setIdea(int index, std::string idea);
};

#endif