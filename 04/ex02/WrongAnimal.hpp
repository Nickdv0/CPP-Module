/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:16:48 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/11 13:25:52 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAnimal_HPP
# define WRONGAnimal_HPP

# include <iostream>

class WrongAnimal {
	protected:
		std::string _type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		virtual ~WrongAnimal();

		WrongAnimal & operator=(const WrongAnimal &src);

		std::string getType() const;
		void makeSound() const;
};

#endif