#include <iostream>

char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printBoard()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "[ " << board[i][j] << " ]";
        }
        std::cout << "\n";
    }
}

int main()
{
    bool active = true;
    int playerChoice[2] = { 0, 0 };

    while (active) {
        printBoard();
        std::cout << "Player 1's turn, choose x\n";
        std::cin >> playerChoice[0];
        std::cout << std::endl;

        std::cout << "Player 1's turn, choose y\n";
        std::cin >> playerChoice[1];
        std::cout << std::endl;

        if (playerChoice[0] > 0 && playerChoice[0] < 4 && playerChoice[1] > 0 && playerChoice[1] < 4) {
            if (board[playerChoice[0] - 1][playerChoice[1] - 1] == ' ') {
                board[playerChoice[0] - 1][playerChoice[1] - 1] = 'x';
            }
        }

        printBoard();
        std::cout << "Player 2's turn, choose x\n";
        std::cin >> playerChoice[0];
        std::cout << std::endl;

        std::cout << "Player 2's turn, choose y\n";
        std::cin >> playerChoice[1];
        std::cout << std::endl;

        if (playerChoice[0] > 0 && playerChoice[0] < 4 && playerChoice[1] > 0 && playerChoice[1] < 4) {
            if (board[playerChoice[0] - 1][playerChoice[1] - 1] == ' ') {
                board[playerChoice[0] - 1][playerChoice[1] - 1] = 'o';
            }
        }
    }
}