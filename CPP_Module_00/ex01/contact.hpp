
#ifndef CONTACT_HPP
#define CONTACT_HPP

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
    void setFirstName(const std::string &input);
    std::string getFirstName() const;

    void setLastName(const std::string &input);
    std::string getLastName() const;

    void setNickname(const std::string &input);
    std::string getNickname() const;

    void setPhoneNumber(const std::string &input);
    std::string getPhoneNumber() const;

    void setDarkestSecret(const std::string &input);
    std::string getDarkestSecret() const;
};

#endif
