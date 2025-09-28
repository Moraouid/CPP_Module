#include <algorithm>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

class Contact
{
  private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

  public:
	void setFirstName(const std::string &input)
	{
		firstName = input;
	}
	std::string getFirstName() const
	{
		return (firstName);
	}
	void setLastName(const std::string &input)
	{
		lastName = input;
	}
	std::string getLastName() const
	{
		return (lastName);
	}
	void setNickname(const std::string &input)
	{
		nickname = input;
	}
	std::string getNickname() const
	{
		return (nickname);
	}
	void setPhoneNumber(const std::string &input)
	{
		phoneNumber = input;
	}
	std::string getPhoneNumber() const
	{
		return (phoneNumber);
	}
	void setDarkestSecret(const std::string &input)
	{
		darkestSecret = input;
	}
	std::string getDarkestSecret() const
	{
		return (darkestSecret);
	}
};

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

class PhoneBook
{
  private:
	Contact contacts[8];
	int index = 0;
	int count = 0;

  public:
	void addContact()
	{
		Contact tmpContacts;
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
	void searchContact()
	{
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
		int inputIndex;
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
};

int	main(void)
{
	PhoneBook	phoneBook;

	std::string command;
	while (true)
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
