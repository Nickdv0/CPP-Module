/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	try
	{
		PmergeMe sorter;


		sorter.parseInput(argc, argv);


		sorter.sortAndCompare();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
