# include "./phonebook.hpp"
# include "./contact.hpp"

PhoneBook::PhoneBook(void) : numberOfContacts(0) {return;}

PhoneBook::~PhoneBook() {}

int PhoneBook::getIndexOfOldestContact() const {
    int i;
    int oldestIndex = 0;
    
    i = 1;
    while (i < numberOfContacts)
    {
        if (contacts[i].isEmpty())
        {
            return i;
        }
        if (contacts[i].getPhoneNumber() < contacts[oldestIndex].getPhoneNumber())
        {
            oldestIndex = i;
        }
        i++;
    }
    return oldestIndex;
}

void PhoneBook::addContact(const Contact &contact)
{
    if (numberOfContacts < 8) {
        contacts[numberOfContacts] = contact;
        numberOfContacts++;
        std::cout << "Contact added." << std::endl;
    } else {
        replaceOldestContact(contact);
        std::cout << "Phone book is full. Oldest contact replaced." << std::endl;
    }
}

void PhoneBook::replaceOldestContact(const Contact &contact) {
    for (int i = 0; i < 7; i++) {
        contacts[i] = contacts[i + 1];
    }
    contacts[7] = contact;
}

void PhoneBook::searchContacts() const
{
    int i;

    i = 0;
    std::cout << std::setw(10) << "Index" << " |"
              << std::setw(10) << "First name" << " |"
              << std::setw(10) << "Last name" << " |"
              << std::setw(10) << "Nickname" << std::endl;
    while (i < numberOfContacts)
    {
        std::cout << std::setw(10) << i + 1 << " |"
                  << std::setw(10) << truncate(contacts[i].getFirstName(), 10) << " |"
                  << std::setw(10) << truncate(contacts[i].getLastName(), 10) << " |"
                  << std::setw(10) << truncate(contacts[i].getNickname(), 10) << std::endl;
        i++;
    }

    int index;
    std::cout << "Enter the index of the contact you want to view: ";
    std::cin >> index;

    if (std::cin.fail() || index <= 0 || index > numberOfContacts)
    {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');
    }
    else
    {
        std::cout << "First name:   " << contacts[index - 1].getFirstName() << std::endl; 
        std::cout << "Last name:   " << contacts[index - 1].getLastName() << std::endl; 
        std::cout << "Nick name:   " << contacts[index - 1].getNickname() << std::endl; 
        std::cout << "Phone number:   " << contacts[index - 1].getPhoneNumber() << std::endl; 
        std::cout << "Darkest secret:   " << contacts[index - 1].getDarkestSecret() << std::endl;
        // contacts[index - 1].~Contact();
    }
}
