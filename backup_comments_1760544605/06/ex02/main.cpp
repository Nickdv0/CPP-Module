/* ************************************************************************** */











#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{

	std::srand(std::time(0));

	int choice = std::rand() % 3;

	switch (choice)
	{
		case 0:
			std::cout << "Generated object of type A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated object of type B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated object of type C" << std::endl;
			return new C();
		default:
			return new A();
	}
}

void identify(Base* p)
{

	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{


	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception&) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception&) {}

	std::cout << "Unknown type" << std::endl;
}

int main()
{
	std::cout << "=== Testing Type Identification ===" << std::endl;


	for (int i = 0; i < 6; i++)
	{
		std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;

		Base* obj = generate();

		std::cout << "Identify using pointer: ";
		identify(obj);

		std::cout << "Identify using reference: ";
		identify(*obj);

		delete obj;


		for (int j = 0; j < 1000000; j++) {}
	}

	std::cout << "\n--- Manual Tests ---" << std::endl;


	std::cout << "\nTesting A object:" << std::endl;
	A* a = new A();
	std::cout << "Pointer: ";
	identify(a);
	std::cout << "Reference: ";
	identify(*a);
	delete a;

	std::cout << "\nTesting B object:" << std::endl;
	B* b = new B();
	std::cout << "Pointer: ";
	identify(b);
	std::cout << "Reference: ";
	identify(*b);
	delete b;

	std::cout << "\nTesting C object:" << std::endl;
	C* c = new C();
	std::cout << "Pointer: ";
	identify(c);
	std::cout << "Reference: ";
	identify(*c);
	delete c;

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
