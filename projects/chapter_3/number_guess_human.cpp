// number_guess_human.cpp
// A simple number guessing game written step-by-step
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()
#include <iostream>

int main()
{
    std::srand(static_cast<unsigned>(std::time(0))); // Seed RNG
    int secret = std::rand() % 100 + 1;              // Secret number (1–100)
    int guess;

    std::cout << "Guess the number (1–100): ";

    while (true)
    {
        std::cin >> guess;

        if (guess < secret)
        {
            std::cout << "Too low! Try again: ";
        }
        else if (guess > secret)
        {
            std::cout << "Too high! Try again: ";
        }
        else
        {
            std::cout << "Correct! You guessed it.\n";
            break;
        }
    }

    return 0;
}
