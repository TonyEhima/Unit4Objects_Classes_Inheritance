#include <iostream>
#include <cstdlib>
#include <ctime>

class NumberGuessingGame {
private:
    int secretNumber;
protected:
    int maxAttempts;

public:
    NumberGuessingGame(int range, int maxAttempts) {
        this->maxAttempts = maxAttempts;
        srand(time(0));  // Seed for random number generation
        secretNumber = rand() % range + 1;  // Random number between 1 and range
    }

    virtual void playGame() {
        int guess;
        int attempts = 0;
        bool guessedCorrectly = false;

        std::cout << "Welcome to the Number Guessing Game!" << std::endl;
        std::cout << "I have selected a number within the range provided." << std::endl;
        std::cout << "You have " << maxAttempts << " attempts to guess the correct number." << std::endl;

        while (attempts < maxAttempts && !guessedCorrectly) {
            std::cout << "Enter your guess: ";
            std::cin >> guess;
            attempts++;

            if (guess < secretNumber) {
                std::cout << "Too low!" << std::endl;
            } else if (guess > secretNumber) {
                std::cout << "Too high!" << std::endl;
            } else {
                std::cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << std::endl;
                guessedCorrectly = true;
            }
        }

        if (!guessedCorrectly) {
            std::cout << "Sorry, you've used all your attempts. The correct number was " << secretNumber << "." << std::endl;
        }
    }
};

class AdvancedNumberGuessingGame : public NumberGuessingGame {
public:
    AdvancedNumberGuessingGame(int range, int maxAttempts) : NumberGuessingGame(range, maxAttempts) {
        // Inherits constructor of the base class
    }

    void playGame() override {
        std::cout << "Welcome to the Advanced Number Guessing Game!" << std::endl;
        NumberGuessingGame::playGame(); // Using the base class playGame method
    }
};

int main() {
    AdvancedNumberGuessingGame game(200, 5);  // Create an advanced game object with increased range and fewer attempts
    game.playGame();  // Start the game
    return 0;
}
