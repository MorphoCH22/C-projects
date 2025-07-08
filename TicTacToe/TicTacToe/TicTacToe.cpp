#include <iostream>

char board[3][3] { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
int moveCount = 0;

void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "[ " << board[i][j] << " ]";
        }
        std::cout << "\n";
    }
}

int getUserInput() {
    while (true) {
        int choice{};
        std::cin >> choice;

        if (!std::cin || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, try again: ";
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return choice;
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

    // incase of a draw
    if (moveCount == 9) {
        return 'd';
    }

    return 0;
}

int main() {
    bool active{ true };

    char currentPlayer = 'x';
    int playerChoice[2]{ 0, 0 };

    while (active) {
        printBoard();

        std::cout << "Player " << currentPlayer << "'s turn, choose x coordinate: ";
        playerChoice[1] = getUserInput();

        std::cout << "Player " << currentPlayer << "'s turn, choose y coordinate: ";
        playerChoice[0] = getUserInput();

        if (board[playerChoice[0] - 1][playerChoice[1] - 1] == ' ') {
            board[playerChoice[0] - 1][playerChoice[1] - 1] = currentPlayer;
            moveCount++;
        }
        else {
            std::cout << "Occupied space, try again!\n";
            continue;
        }

        if (checkForWin() != 0) {
            printBoard();
            switch (currentPlayer) {
            case 'x':
                std::cout << "Player 1 wins!";
                break;
            case 'o':
                std::cout << "Player 2 wins!";
                break;
            case 'd':
                std::cout << "Draw!";
                break;
            default:
                std::cout << "ERROR encountered during win check";
                break;
            }
            return 0;
        }

        switch (currentPlayer) {
        case 'x': 
            currentPlayer = 'o';
            break;
        case 'o':
            currentPlayer = 'x';
            break;
        default:
            currentPlayer = 'x';
            break;
        }
    }
}