//Task-3 => Build a simple console-based Tic-Tac-Toe game that allows two players to play against each other.

// Game Board: Create a 3x3 grid as the game board.
// Players: Assign "X" and "O" to two players.
// Display Board: Show the current state of the board.
// Player Input: Prompt the current player to enter their move.
// Update Board: Update the game board with the player's move
// Check for Win: Check if the current player has won.
// Check for Draw: Determine if the game is a draw.
// Switch Players: Alternate turns between "X" and "O" players.
// Display Result: Show the result of the game (win, draw, or ongoing).
// Play Again: Ask if the players want to play another game in simple cpp code

#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
  cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "---+---+---" << endl;
  cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "---+---+---" << endl;
  cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void switchPlayer() {
  currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool checkWin() {
  // Check rows and columns
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && (board[i][0] == 'X' || board[i][0] == 'O'))
      return true;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == 'X' || board[0][i] == 'O'))
      return true;
  }

  // Check diagonals
  if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && (board[0][0] == 'X' || board[0][0] == 'O')) ||
      (board[0][2] == board[1][1] && board[1][1] == board[2][0] && (board[0][2] == 'X' || board[0][2] == 'O')))
    return true;

  return false;
}

bool checkDraw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] != 'X' && board[i][j] != 'O')
        return false;
    }
  }
  return true;
}

void playGame() {
  int move;
  int row, col;

  while (true) {
    displayBoard();
    cout << "\nPlayer " << currentPlayer << "'s turn. Enter your move (1-9): ";
    cin >> move;

    row = (move - 1) / 3;
    col = (move - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
      cout << "Invalid move. Try again." << endl;
      continue;
    }

    board[row][col] = currentPlayer;

    if (checkWin()) {
      displayBoard();
      cout << "\nPlayer " << currentPlayer << " wins!" << endl;
      break;
    }

    if (checkDraw()) {
      displayBoard();
      cout << "It's a draw!" << endl;
      break;
    }

    switchPlayer();
  }
}

int main() {
  char playAgain;
  do {
    playGame();
    cout << "\nDo you want to play again? (y/n): ";
    cin >> playAgain;

    char num = '1';
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        board[i][j] = num++;
      }
    }
  } while (playAgain == 'y' || playAgain == 'Y');

  return 0;
}
