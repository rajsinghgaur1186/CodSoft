// Task-1 => Create a program that generates a random number 1 to 10 and asks the user to guess it. Provide feedback on whether the guess is too high or too low until the user guesses the correct number.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0));
  int randomNumber = rand() % 10 + 1;
  int guess;

  cout << "\nEnter a number same as Random Number between 1 and 10: ";

  while (true) {
    cin >> guess;

    if (guess == randomNumber) {
      cout << "\nCongratulations! You guessed it!" <<endl;
      break;
    } else if (guess < randomNumber) {
      cout << "Too low! Try again: ";
    } else {
      cout << "Too high! Try again: ";
    }
  }

  return 0;
}
