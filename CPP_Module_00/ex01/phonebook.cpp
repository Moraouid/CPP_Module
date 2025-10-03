#include "phonebook.hpp"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>


std::string formatPrint(std::string str)
{
	if (str.length() > 10)
	{
		return (str.substr(0, 9) + ".");
	}
	else
	{
		return (str);
	}
}

bool	isNumber(std::string str)
{
	char	c;

	for (size_t i = 0; i < str.length(); i++)
	{
		c = str[i];
		if (!std::isdigit(c))
			return (false);
	}
	return (true);
}

void PhoneBook::addContact()
{
	Contact	tmpContacts;

	std::string answer;
	std::cout << "The First Name :\n";
	std::getline(std::cin, answer);
	tmpContacts.setFirstName(answer);
	std::cout << "The Last Name :\n";
	std::getline(std::cin, answer);
	tmpContacts.setLastName(answer);
	std::cout << "nickname :\n";
	std::getline(std::cin, answer);
	tmpContacts.setNickname(answer);
	std::cout << "Phone Number :\n";
	std::getline(std::cin, answer);
	tmpContacts.setPhoneNumber(answer);
	std::cout << "Darkest Secret :\n";
	std::getline(std::cin, answer);
	tmpContacts.setDarkestSecret(answer);
	contacts[index] = tmpContacts;
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}
void PhoneBook::searchContact(void)
{
	int	inputIndex;

	if (count == 0)
	{
		std::cout << "No Contact Yet!\n";
		return ;
	}
	std::cout << "+==========+==========+==========+==========+\n";
	std::cout << "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nickname"
				<< "|\n";
	std::cout << "+==========+==========+==========+==========+\n";
	for (int i = 0; i < count; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << formatPrint(contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << formatPrint(contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << formatPrint(contacts[i].getNickname());
		std::cout << "|\n";
	}
	std::cout << "+==========+==========+==========+==========+\n";
	std::string input;
	std::cout << "Enter index to view details :\n";
	std::getline(std::cin, input);
	if (!isNumber(input))
	{
		std::cout << "Invalid input!\n";
		return ;
	}
	inputIndex = std::stoi(input);
	if (inputIndex < 0 || inputIndex >= count)
	{
		std::cout << "Invalid Index!\n";
		return ;
	}
	std::cout << "First Name: " << contacts[inputIndex].getFirstName() << "\n";
	std::cout << "Last Name: " << contacts[inputIndex].getLastName() << "\n";
	std::cout << "Nickname: " << contacts[inputIndex].getNickname() << "\n";
	std::cout << "Phone Number: " << contacts[inputIndex].getPhoneNumber() << "\n";
	std::cout << "Darkest Secret: " << contacts[inputIndex].getDarkestSecret() << "\n";
}
