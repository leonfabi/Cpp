#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./contact.hpp"

class PhoneBook {
  private:
    Contact contacts[8];
    int numberOfContacts;

    int getIndexOfOldestContact() const;

  public:
    PhoneBook();
    ~PhoneBook();
  std::string truncate(const std::string &str, size_t width) const
  {
    if (str.length() > width)
    {
      return str.substr(0, width - 3) + "...";
    }
    return str;
  }
    void addContact(const Contact &contact);
    void replaceOldestContact(const Contact &contact);
    void searchContacts() const;
};

#endif
