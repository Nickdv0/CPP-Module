/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:19:07 by nde-vant          #+#    #+#             */
/*   Updated: 2025/10/15 18:19:08 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "=== Testing Intern Class ===" << std::endl;

	try
	{
		std::cout << "\n1. Creating bureaucrats and intern:" << std::endl;
		Bureaucrat president("President", 1);
		Bureaucrat manager("Manager", 25);
		Bureaucrat supervisor("Supervisor", 50);
		Intern someRandomIntern;

		std::cout << president << std::endl;
		std::cout << manager << std::endl;
		std::cout << supervisor << std::endl;

		std::cout << "\n2. Testing valid form creation:" << std::endl;

		AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "garden");
		AForm* robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
		AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

		std::cout << *shrubForm << std::endl;
		std::cout << *robotForm << std::endl;
		std::cout << *pardonForm << std::endl;

		std::cout << "\n3. Testing form workflow:" << std::endl;


		supervisor.signForm(*shrubForm);
		supervisor.executeForm(*shrubForm);


		supervisor.signForm(*robotForm);
		manager.executeForm(*robotForm);


		manager.signForm(*pardonForm);
		president.executeForm(*pardonForm);

		std::cout << "\n4. Testing invalid form names:" << std::endl;

		try
		{
			AForm* invalidForm = someRandomIntern.makeForm("invalid form", "target");
			(void)invalidForm;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		try
		{
			AForm* anotherInvalidForm = someRandomIntern.makeForm("wrong name", "target");
			(void)anotherInvalidForm;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\n5. Testing example from subject:" << std::endl;
		{
			Intern someRandomIntern2;
			AForm* rrf;
			rrf = someRandomIntern2.makeForm("robotomy request", "Bender");

			std::cout << *rrf << std::endl;


			manager.signForm(*rrf);
			manager.executeForm(*rrf);

			delete rrf;
		}

		std::cout << "\n6. Testing case sensitivity:" << std::endl;
		try
		{
			AForm* caseForm = someRandomIntern.makeForm("Robotomy Request", "target");
			(void)caseForm;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}


		delete shrubForm;
		delete robotForm;
		delete pardonForm;

	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
