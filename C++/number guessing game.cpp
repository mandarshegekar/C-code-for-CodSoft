#include <iostream>
#include <cstdlib>   // for rand() and srand()
#include <ctime>     // for time()

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator with current time

    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number game!\n\n";
    cout << "I have chosen a number between 1 and 100. Try to guess it.\n\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber)
            cout << "Too low! Try again.\n";
        else if (guess > secretNumber)
            cout << "Too high! Try again.\n";
        else
            cout << "\nCongratulations! You've guessed the number (" << secretNumber << ") correctly in " << attempts << " attempts!\n";
    } while (guess != secretNumber);

    return 0;
}
