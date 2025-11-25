/* ************************************************************************** */











#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137), _target("default")
{
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


const std::string& ShrubberyCreationForm::getTarget() const
{
	return _target;
}


void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw FileCreationException();

	file << "       /\\      " << std::endl;
	file << "      /  \\     " << std::endl;
	file << "     /    \\    " << std::endl;
	file << "    /______\\   " << std::endl;
	file << "       ||      " << std::endl;
	file << "       ||      " << std::endl;
	file << std::endl;
	file << "     /\\   /\\   " << std::endl;
	file << "    /  \\ /  \\  " << std::endl;
	file << "   /    X    \\ " << std::endl;
	file << "  /____/ \\____\\" << std::endl;
	file << "       ||      " << std::endl;
	file << "       ||      " << std::endl;
	file << std::endl;
	file << "       /\\      " << std::endl;
	file << "      /  \\     " << std::endl;
	file << "     /____\\    " << std::endl;
	file << "    /      \\   " << std::endl;
	file << "   /________\\  " << std::endl;
	file << "       ||      " << std::endl;
	file << "       ||      " << std::endl;

	file.close();
	std::cout << "Shrubbery has been planted at " << _target << std::endl;
}


const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return "Could not create file!";
}
