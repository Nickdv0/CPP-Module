/* ************************************************************************** */











#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Testing Form and Bureaucrat Classes ===" << std::endl;

	try
	{
		std::cout << "\n1. Creating bureaucrats and forms:" << std::endl;
		Bureaucrat alice("Alice", 5);
		Bureaucrat bob("Bob", 50);
		Bureaucrat charlie("Charlie", 100);

		Form form1("Tax Return", 25, 10);
		Form form2("Parking Permit", 75, 50);
		Form form3("Top Secret", 1, 1);

		std::cout << alice << std::endl;
		std::cout << bob << std::endl;
		std::cout << charlie << std::endl;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;

		std::cout << "\n2. Testing successful form signing:" << std::endl;
		alice.signForm(form1);
		bob.signForm(form2);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		std::cout << "\n3. Testing failed form signing (grade too low):" << std::endl;
		charlie.signForm(form1);
		charlie.signForm(form2);
		bob.signForm(form3);

		std::cout << "\n4. Testing invalid form creation:" << std::endl;


		try
		{
			Form invalidForm1("Invalid1", 0, 50);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}


		try
		{
			Form invalidForm2("Invalid2", 50, 151);
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\n5. Testing copy constructor and assignment:" << std::endl;
		Form copy(form1);
		std::cout << "Copy: " << copy << std::endl;

		Form assigned("Temp", 100, 100);
		assigned = form2;
		std::cout << "Assigned: " << assigned << std::endl;

		std::cout << "\n6. Testing signing already signed form:" << std::endl;
		alice.signForm(form1);

	}
	catch (std::exception& e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
