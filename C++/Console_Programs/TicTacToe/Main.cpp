#include "pch.h"

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>

#define ERROR_DISPLAY_X 0
#define ERROR_DISPLAY_Y 7
#define DIALOGUE_XPOSN 0
#define DIALOGUE_YPOSN 8

using namespace std;

void setCursorPosn(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);
}

enum STAGES {
    BEGIN, PLAYER_X, PLAYER_O
};


void printWin(int sum) {
    if (sum == 3) {
        setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
        cout << "Player O won!" << endl;
        
    }
    if (sum == 0) {
        setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
        cout << "Player X won!" << endl;
        
    }
}

// 0 is player X
// 1 is player O
// 9 means blank cell in board
boolean checkWin(int board[3][3], int moves) {
    
    // check rows;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += board[i][j];
        }
        if (sum == 0 || sum == 3) {
            printWin(sum);
            return true;
        }
    }

    // check cols;
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum += board[j][i];
        }
        if (sum == 0 || sum == 3) {
            printWin(sum);
            return true;
        }
    }

    // check diagonals (there's only 2)
    int sum = board[0][0] + board[1][1] + board[2][2];
    
    if (sum == 0 || sum == 3) {
        printWin(sum);
        return true;
    }

    // check diagonals (there's only 2)
    sum = board[0][2] + board[1][1] + board[2][0];

    if (sum == 0 || sum == 3) {
        printWin(sum);
        return true;
    }
    
    if (moves == 0) {
        setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
        cout << "It's a draw!" << endl;
        return true;
    }
    return false;
}

void setSymbol(int row, int col, char symbol) {
    int consoleY = 1 + (row - 1) * 2;
    int consoleX = 1 + (col - 1) * 4;
    setCursorPosn(consoleX, consoleY);
    cout << symbol;
}

char convertToCharacter(int number) {
    switch (number) {
    case 9:
        return ' ';
    case 1:
        return 'O';
    case 0:
        return 'X';
    }
}

void resetBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = 9;
        }
    }
}

void printBoard(int board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void drawBoard(int board[3][3]) {

    system("CLS");
    cout << "-------------" << endl;
    cout << "| " << convertToCharacter(board[0][0]);
    cout << " | " << convertToCharacter(board[0][1]);
    cout << " | " << convertToCharacter(board[0][2]);
    cout << " | " << endl;
    cout << "-------------" << endl;
    cout << "| " << convertToCharacter(board[1][0]);
    cout << " | " << convertToCharacter(board[1][1]);
    cout << " | " << convertToCharacter(board[1][2]);
    cout << " | " << endl;
    cout << "-------------" << endl;
    cout << "| " << convertToCharacter(board[2][0]);
    cout << " | " << convertToCharacter(board[2][1]);
    cout << " | " << convertToCharacter(board[2][2]);
    cout << " | " << endl;
    cout << "-------------" << endl;
}

bool checkBoardInput(int board[3][3], int x, int y, string & errormsg) {

    if (x > 3 || x <= 0 || y > 3 || y <= 0) {
        
        errormsg = "Row or column number is incorrect";
        return false;
    }
    if (board[x-1][y-1] != 9) {
        //printBoard(board);
        errormsg = "Spot is taken, please try another cell";
        return false;
    }
    return true;
}

void getInput(int board[3][3], int & newX, int & newY, STAGES s) {

    string player = (s == PLAYER_O) ? "O" : "X";
    string errmsg = "";
    do {
        drawBoard(board);
        setCursorPosn(ERROR_DISPLAY_X, ERROR_DISPLAY_Y);
        cout << errmsg << endl;
        setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);

        cout << "Enter row # 1, 2, or 3 to put " << player << endl;
        cin >> newX;
        cout << "Enter col # 1, 2, or 3 to put " << player << endl;
        cin >> newY;
    } while (!checkBoardInput(board, newX, newY, errmsg));
}

int main() {
    STAGES stages = BEGIN;
    bool gameover = false;
    char replay = 'N';
    int newX, newY;
    int moves = 9;
    int board[3][3] =
        { { 9, 9, 9 },
        { 9, 9, 9 },
        { 9, 9, 9 } };

    while (!gameover) {

        switch (stages) {
        case BEGIN:
            replay = 'N';
            moves = 9;
            resetBoard(board);
            drawBoard(board);
            getInput(board, newX, newY, PLAYER_X);
            stages = PLAYER_X;
            break;

        case PLAYER_X:
            board[newX - 1][newY - 1] = 0;
            drawBoard(board);
            moves--;
            gameover = (checkWin(board, moves));
            if (!gameover) {
                getInput(board, newX, newY, PLAYER_O);
                stages = PLAYER_O;
            }
            else {
                cout << "Game over, press R to play again, or any other key to exit" << endl;
                cin >> replay;
                if (replay == 'R') {
                    stages = BEGIN;
                    gameover = false;
                }
            }
            break;

        case PLAYER_O:
            board[newX - 1][newY - 1] = 1;
            drawBoard(board);
            moves--;
            gameover = (checkWin(board, moves));
            if (!gameover) {
                getInput(board, newX, newY, PLAYER_X);
                stages = PLAYER_X;
            }
            else {
                cout << "Game over, press R to play again, or any other key to exit" << endl;
                cin >> replay;
                if (replay == 'R') {
                    stages = BEGIN;
                    gameover = false;
                }
            }
            break;
        }
    }
    
    return 0;
}