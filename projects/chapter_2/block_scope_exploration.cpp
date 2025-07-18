// block_scope_exploration.cpp
#include <iostream>
void showBlockScope()
{
    if (true)
    {
        int x = 5; // x is visible only inside this if block
        std::cout << x << std::endl;
    }
    // x is no longer accessible here
    {
        int x = 10; // This is a new x, visible only inside this block
        std::cout << x << std::endl;
    }
}
int main()
{
    showBlockScope();
    return 0;
}