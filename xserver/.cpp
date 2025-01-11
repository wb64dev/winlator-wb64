```
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    int numberToGuess = rand() % 100 + 1;
    int guess;

    std::cout << "Guess a number between 1 and 100: ";

    while (true) {
        std::cin >> guess;

        if (guess < numberToGuess)
            std::cout << "Too low! Try again.";
        else if (guess > numberToGuess)
            std::cout << "Too high! Try again.";
        else {
            std::cout << "Congratulations! You won!";
            break;
        }
    }

    return 0;
}
``
