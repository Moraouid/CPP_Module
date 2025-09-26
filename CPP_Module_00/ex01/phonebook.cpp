#include <cstring>
#include <iostream>

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

class PhoneBook
{
    private:
        Contact contacts[8];
        int index = 0;
    public:
        void addContact()
        {
            Contact tmpContacts;
            std::string answer;
            std::cout << "The First Name :\n";
            std::cin >> answer;
            tmpContacts.setFirstName(answer);
            std::cout << "The Last Name :\n";
            std::cin >> answer;
            tmpContacts.setLastName(answer);
            std::cout << "nickname :\n";
            std::cin >> answer;
            tmpContacts.setNickname(answer);
            std::cout << "Phone Namber :\n";
            std::cin >> answer;
            tmpContacts.setPhoneNumber(answer);
            std::cout << "Darkest Secret :\n";
            std::getline(std::cin, answer);
            contacts[index] = tmpContacts;
            index = (index + 1) % 8;
        }
};

int	main(void)
{
	return (0);
}
