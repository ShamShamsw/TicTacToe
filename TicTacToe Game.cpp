#include <iostream>
#include <vector>
using namespace std;

        // Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
        // The goal of this function is to display the board
        // "" "" ""
        // "" "" ""
        // "" "" ""
}

// Function to check if there's a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        
        // This example is for x however it could be for o as well
        // They code works both ways
        
        // first check in if statement
        // "x" " " "" "
        // "x" " " " "
        // " " " " " "
        // second check in if statement
        // " " " " " "
        // "x" " " " "
        // "x" " " " "
        // third check in if statement
        // "X" " " " "
        // " " " " " "
        // " " " " " " 

        // So why does this work?
        // To start the goal is to measure if the rows are the same
        // And it also checks that the cell is not empty
        // The first check in the if statement is to see if the top left cell is the same as the middle left cell
        // Next if the middle left cell is the same as the bottom left cell
        // Lastly that the top left cell is not empty
        // You could change the loop so that the code " board[i][0] != ' ' " is first but I found this way to be easier to understand

        // How does the code know who won?
        // This piece of code " board[i][0] " checks to see what character is in the top left cell in the row
        // Its runs through the loop and checks each row using the variable i
        // Since the loop runs 3 times it checks all the rows this is due to condition i < 3
        // If their is a match in the row and the cells are not blank it will return the character in the cell at the top of the row it checked
        // If the character is 'X' then the code will return 'X' as the winner and vice versa for 'O'
        // It is simple to understand and easy to maintain
        // Which is why at the end of the loop the code returns the character in the top left cell if the conditions are met

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
        // This example is for x however it could be for o as well
        // They code works both ways

        // first check in if statement
        // "x" " " "" "
        // " " "x" " "
        // " " " " " "
        // second check in if statement
        // " " " " " "
        // " " "x" " "
        // " " " " "x"
        // third check in if statement
        // "X" " " " "
        // " " " " " "
        // " " " " " " 

        // So why does this work?
        // To start the goal is to measure if the diagonals are the same
        // And it also checks that the cell is not empty
        // The first check in the if statement is to see if the top left cell is the same as the middle cell
        // Next if the middle cell is the same as the bottom right cell
        // Lastly that the top left cell is not empty
        // You could change the loop so that the code " board[0][0] != ' ' " is first but I found this way to be easier to understand

        // How does the code know who won?
        // This piece of code " board[0][0] " checks to see what character is in the top left cell
        // If the character is 'X' then the code will return 'X' as the winner and vice versa for 'O'
        // It is simple to understand and easy to maintain
        // Which is why at the end of the loop the code returns the character in the top left cell if the conditions are met

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
        // If no winner
    return ' ';
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the Tic-Tac-Toe board
    int row, col; // Player's move
    char currentPlayer = 'X'; // Player X starts the game

    cout << "Welcome to Tic-Tac-Toe!" << endl;
        // This could be made into a function that initializes the board and outputs the welcome message
        // to make the main function cleaner.
        // However this is a simple program so it's fine to keep it here, and it's not too long or complex.

        // Main game loop
    for (int turn = 0; turn < 9; ++turn) {
        // Display the board
        cout << "Current board:" << endl;
        displayBoard(board);
        // Prompt the player for their move
        // It only loops if the player enters an invalid move or if the cell is already taken
        // The loop runs until more than 9 turns have passed, so it's impossible to have more than 9 turns
        // This is because the game ends when there are no more empty cells, so it's impossible to have more than 9 turns

        // Get player's move
        cout << "Player " << currentPlayer << ", enter your move (row column): ";
        cin >> row >> col;
        // You could include Player 1 and Player 2 however this would make the code longer and more complex
        // It also isnt required for a game like Tic-Tac-Toe where there are only 2 players
        // So don't include it unless extra code it's necessary
        // As extra code gets complicated and harder to maintain as well take more time to write

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            --turn; // Decrement turn to allow the player to try again
            continue;
        } 
        // This is a good way to handle invalid moves as it allows the player to try again without ending the game
        // It is also easy to understand as it is a simple loop that allows the player to try again

        // Update the board with the player's move
        board[row][col] = currentPlayer;
        // This peice of code is simple and easy but very important as it updates the board with the player's most recent move

        // Check for a winner
        char winner = checkWinner(board);
        if (winner != ' ') {
            cout << "Player " << winner << " wins!" << endl;
            displayBoard(board);
            return 0; // End the game
        }
        // Each game needs a way to measure if a player has won or not
        // Its important to have a easy to understand way to check for this
        // This code uses a function because it is going to be repeated multiple times
        // As such it will require less lines of code and be easier to maintain and understand

        // Switch players for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        // This is a simple way to switch players
    }

        // If no winner after all turns
    cout << "It's a draw!" << endl;
    displayBoard(board);

    return 0;
}
