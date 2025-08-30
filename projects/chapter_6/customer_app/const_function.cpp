// customer_app/const_function.cpp
// This file demonstrates the use of const member functions in C++.
// It shows how to define a class with const member functions and how they can be used.
#include <iostream>
#include <string>

class Book
{
  private:
    std::string title;
    int pages;

  public:
    Book(const std::string &bookTitle, int totalPages) : title(bookTitle), pages(totalPages)
    {
    }

    // const member function – safe read-only access
    std::string getTitle() const
    {
        return title; // allowed: reading is fine
    }

    // non-const member function – allows modification
    void setPages(int newPageCount)
    {
        pages = newPageCount; // allowed: writing is fine
    }
};

int main()
{
    const Book myBook("C++ Basics", 200);

    std::cout << myBook.getTitle() << "\n"; // OK: const function
    // myBook.setPages(250); // ERROR: cannot call non-const function on const object
}
