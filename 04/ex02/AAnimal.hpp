/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:47:12 by nde-vant          #+#    #+#             */
/*   Updated: 2025/03/10 17:29:53 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
	protected:
		std::string _type;
	
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal &src);
		virtual ~AAnimal();

		AAnimal & operator=(const AAnimal &src);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif