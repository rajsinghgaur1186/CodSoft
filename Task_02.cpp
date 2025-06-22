// Task-2 => Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and division. Allow the user to input two numbers and choose an operation to perform.

#include <iostream>
using namespace std;

int main() {
  double num1, num2;
  char operation;

  cout << "\nEnter the first number: ";
  cin >> num1;

  cout << "Enter the operation (+, -, *, /): ";
  cin >> operation;

  cout << "Enter the second number: ";
  cin >> num2;

  switch (operation) {
    case '+':
      cout << "\nResult: " << num1 + num2 << endl;
      break;
    case '-':
      cout << "\nResult: " << num1 - num2 <<endl;
      break;
    case '*':
      cout << "\nResult: " << num1 * num2 << endl;
      break;
    case '/':
      if (num2 != 0)
        cout << "\nResult: " << num1 / num2 << endl;
      else
        cout << "Error: Division by zero!" <<endl;
      break;
    default:
      cout << "Error: Invalid operation!" << endl;
  }

  return 0;
}
