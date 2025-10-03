#include "phonebook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string command;
	while (1337)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Bye!\n";
			break ;
		}
		else
			std::cout << "Unknown command!\n";
	}
	return (0);
}
