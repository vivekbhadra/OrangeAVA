// access_control_fallthrough.cpp
// Demonstrates intentional fall-through using [[fallthrough]]
// to model cumulative user permissions

#include <iostream>

int main()
{
    int role;
    std::cout << "Select role (1 = Viewer, 2 = Editor, 3 = Admin): ";
    std::cin >> role;

    std::cout << "Permissions granted:\n";

    switch (role)
    {
    case 3:
        std::cout << "- Access Admin Tools\n";
        [[fallthrough]];  // Intentional fall-through to include Editor and Viewer permissions
    case 2:
        std::cout << "- Edit Content\n";
        [[fallthrough]];  // Intentional fall-through to include Viewer permissions
    case 1:
        std::cout << "- View Content\n";
        break;
    default:
        std::cout << "Invalid role selected.\n";
    }

    return 0;
}

