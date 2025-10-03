#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <string.h>

class PhoneBook
{
    private:
        Contact contacts[8];
        int index;
        int count;
    public:
        void addContact();
        void searchContact();
};

#endif
