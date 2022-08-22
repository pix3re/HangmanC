#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

char confirAction(std::string pQuestion);

int main()
{
	char pTest = confirAction("Are you ready to play?");

	std::cout << pTest;

	return 0;
}

char confirAction(std::string pQuestion)
{
	char pUserAction;

	do
	{
		std::cout << pQuestion << " (y/n)" << std::endl;
		std::cin >> pUserAction;

		pUserAction = std::tolower(pUserAction);

	} while (pUserAction != 'y' && pUserAction != 'n');

	return pUserAction;
}