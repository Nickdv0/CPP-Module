/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 07:18:19 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/14 20:53:39 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

// Forward declaration
class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	// Orthodox Canonical Form
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	// Getters
	const std::string&	getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Form signing
	void				beSigned(const Bureaucrat& bureaucrat);

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
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
