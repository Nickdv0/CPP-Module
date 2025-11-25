/* ************************************************************************** */

#include "whatever.hpp"
#include <string>

int main(void)
{
	std::cout << "=== Testing Template Functions ===" << std::endl;


	std::cout << "\n--- Integer Tests ---" << std::endl;
	int a = 2;
	int b = 3;

	std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;


	std::cout << "\n--- String Tests ---" << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;


	std::cout << "\n--- Float Tests ---" << std::endl;
	float f1 = 3.14f;
	float f2 = 2.71f;

	std::cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
	::swap(f1, f2);
	std::cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
	std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
	std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;


	std::cout << "\n--- Equal Values Tests ---" << std::endl;
	int x = 42;
	int y = 42;

	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min(x, y) = " << ::min(x, y) << " (should return second)" << std::endl;
	std::cout << "max(x, y) = " << ::max(x, y) << " (should return second)" << std::endl;


	std::cout << "Address of x: " << &x << std::endl;
	std::cout << "Address of y: " << &y << std::endl;
	std::cout << "Address of min(x, y): " << &::min(x, y) << std::endl;
	std::cout << "Address of max(x, y): " << &::max(x, y) << std::endl;

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}
