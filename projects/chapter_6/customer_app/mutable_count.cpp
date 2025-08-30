// customer_app/mutable_count.cpp
// This file demonstrates the use of mutable members in a class.
// It shows how mutable members can be modified even in const member functions.
#include <iostream>
#include <string>

class WebPage
{
  private:
    std::string content;
    mutable int viewCount; // can change even in const functions

  public:
    WebPage(const std::string &c) : content(c), viewCount(0)
    {
    }

    // const function but modifies a mutable member
    void display() const
    {
        ++viewCount; // allowed because viewCount is mutable
        std::cout << content << "\n";
    }

    int getViewCount() const
    {
        return viewCount;
    }
};

int main()
{
    const WebPage page("Welcome to the homepage!");

    page.display();
    page.display();

    std::cout << "Views: " << page.getViewCount() << "\n"; // Outputs: Views: 2
}
