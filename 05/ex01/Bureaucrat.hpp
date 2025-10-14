/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:18:12 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/14 20:53:39 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration
class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// Getters
	const std::string&	getName() const;
	int					getGrade() const;

	// Grade manipulation
	void				incrementGrade();
	void				decrementGrade();

	// Form signing
	void				signForm(Form& form);

	// Exception classes
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

		// Constants
	#define HIGHEST_GRADE 1
	#define LOWEST_GRADE 150
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
