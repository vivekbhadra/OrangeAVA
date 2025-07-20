// Write a C++ number guessing game between 1 and 100
// number_guess_ai.cpp
// This program allows the user to guess a randomly generated number between 1 and 100.
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    int numberToGuess = rand() % 100 + 1;      // Random number between 1 and 100
    int userGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!"
              << "\n";
    std::cout << "I have selected a number between 1 and 100."
              << "\n";

    while (userGuess != numberToGuess)
    {
        std::cout << "Please enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < numberToGuess)
        {
            std::cout << "Too low! Try again."
                      << "\n";
        }
        else if (userGuess > numberToGuess)
        {
            std::cout << "Too high! Try again."
                      << "\n";
        }
        else
        {
            std::cout << "Congratulations! You've guessed the number " << numberToGuess << " in " << attempts
                      << " attempts!"
                      << "\n";
        }
    }

    return 0;
}
