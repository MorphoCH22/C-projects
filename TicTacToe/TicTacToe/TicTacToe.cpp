#include <iostream>

char board[3][3] { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printBoard()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "[ " << board[i][j] << " ]";
        }
        std::cout << "\n";
    }
}

char checkForWin() {
    char lastY[3] { board[0][0], board[0][1], board[0][2] };

    // directional checks
    for (int i = 0; i < 3; i++) {
        if (2 * board[i][0] - board[i][1] - board[i][2] == 0 && board[i][0] != ' ') {
            return board[i][0];
        }

        if (board[i][0] != lastY[0]) {
            lastY[0] = ' ';
        }
        if (board[i][1] != lastY[1]) {
            lastY[1] = ' ';
        }
        if (board[i][2] != lastY[2]) {
            lastY[2] = ' ';
        }
    }
    if (lastY[0] != ' ') {
        return lastY[0];
    }
    if (lastY[1] != ' ') {
        return lastY[1];
    }
    if (lastY[2] != ' ') {
        return lastY[2];
    }

    // diagonal checks
    if (2 * board[0][0] - board[1][1] - board[2][2] == board[0][0] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (2 * board[2][0] - board[1][1] - board[0][2] == board[2][0] && board[2][0] != ' ') {
        return board[2][0];
    }

    return 0;
}

int main()
{
    bool active{ true };
    int playerChoice[2]{ 0, 0 };

    printBoard();
    while (active) {
        std::cout << "Player 1's turn, choose x: ";
        std::cin >> playerChoice[1];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Player 1's turn, choose y: ";
        std::cin >> playerChoice[0];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (playerChoice[0] > 0 && playerChoice[0] < 4 && playerChoice[1] > 0 && playerChoice[1] < 4) {
            if (board[playerChoice[0] - 1][playerChoice[1] - 1] == ' ') {
                board[playerChoice[0] - 1][playerChoice[1] - 1] = 'x';
            }
        }

        printBoard();
        if (checkForWin() == 'x') {
            std::cout << "Player 1 wins!";
            return 0;
        }


        std::cout << "Player 2's turn, choose x: ";
        std::cin >> playerChoice[1];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Player 2's turn, choose y: ";
        std::cin >> playerChoice[0];
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (playerChoice[0] > 0 && playerChoice[0] < 4 && playerChoice[1] > 0 && playerChoice[1] < 4) {
            if (board[playerChoice[0] - 1][playerChoice[1] - 1] == ' ') {
                board[playerChoice[0] - 1][playerChoice[1] - 1] = 'o';
            }
        }

        printBoard();
        if (checkForWin() == 'o') {
            std::cout << "Player 2 wins!";
            return 0;
        }
    }
}