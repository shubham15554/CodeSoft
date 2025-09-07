#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int numberToGuess = rand() % 100 + 1;
    int userGuess = 0;

    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess it?" << endl;

    // Keep asking until the guess is correct
    while (userGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << " Congratulations! You guessed the number " << numberToGuess << " correctly!" << endl;
        }
    }

    return 0;
}
