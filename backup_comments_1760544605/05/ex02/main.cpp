/* ************************************************************************** */











#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "=== Testing AForm and Concrete Forms ===" << std::endl;

	try
	{
		std::cout << "\n1. Creating bureaucrats and forms:" << std::endl;
		Bureaucrat president("President", 1);
		Bureaucrat manager("Manager", 25);
		Bureaucrat supervisor("Supervisor", 50);
		Bureaucrat employee("Employee", 100);
		Bureaucrat intern("Intern", 150);

		ShrubberyCreationForm shrubForm("garden");
		RobotomyRequestForm robotForm("Bender");
		PresidentialPardonForm pardonForm("Ford Prefect");

		std::cout << president << std::endl;
		std::cout << manager << std::endl;
		std::cout << supervisor << std::endl;
		std::cout << employee << std::endl;
		std::cout << intern << std::endl;
		std::cout << shrubForm << std::endl;
		std::cout << robotForm << std::endl;
		std::cout << pardonForm << std::endl;

		std::cout << "\n2. Testing form signing:" << std::endl;


		employee.signForm(shrubForm);


		supervisor.signForm(robotForm);


		manager.signForm(pardonForm);

		std::cout << "\n3. Testing form execution:" << std::endl;


		employee.executeForm(shrubForm);
		supervisor.executeForm(shrubForm);

		supervisor.executeForm(robotForm);
		manager.executeForm(robotForm);

		manager.executeForm(pardonForm);
		president.executeForm(pardonForm);

		std::cout << "\n4. Testing failed signing (grade too low):" << std::endl;
		ShrubberyCreationForm shrubForm2("home");
		RobotomyRequestForm robotForm2("R2D2");
		PresidentialPardonForm pardonForm2("Arthur Dent");

		intern.signForm(shrubForm2);
		intern.signForm(robotForm2);
		intern.signForm(pardonForm2);

		std::cout << "\n5. Testing execution of unsigned form:" << std::endl;
		president.executeForm(robotForm2);

		std::cout << "\n6. Testing multiple robotomy attempts:" << std::endl;
		manager.signForm(robotForm2);
		for (int i = 0; i < 3; i++)
		{
			std::cout << "Attempt " << (i + 1) << ": ";
			manager.executeForm(robotForm2);
		}

	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
