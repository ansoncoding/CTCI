#include "pch.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <Windows.h>

#define SAFE 0
#define MINE 9
#define FLAG 10
#define REVEALED_0 11
#define REVEALED_MINE 12
#define FLAGGED_MINE 13

#define DIALOGUE_XPOSN 0
#define DIALOGUE_YPOSN 21
#define GAMEOVER_XPOSN 0
#define GAMEOVER_YPOSN 23

using namespace std;

enum DIRECTION {
	UP, DOWN, LEFT, RIGHT
};

enum ACTION {
	REVEAL, MARK
};


void setCursorPosn(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hConsole, pos);
}

void setCursor(int row, int col) {
	int consoleY = 1 + (row) * 2;
	int consoleX = 2 + (col) * 4;
	setCursorPosn(consoleX, consoleY);
}

void setSymbol(int row, int col, char symbol) {
	int consoleY = 1 + (row) * 2;
	int consoleX = 2 + (col) * 4;
	setCursorPosn(consoleX, consoleY);
	cout << symbol;
}

char convertToCharacter(int boardNum) {
	switch (boardNum) {
		case REVEALED_0:
			return '0';
		case REVEALED_MINE:
			return '*';
		case MINE:
		case SAFE:
			return ' ';
		case FLAG:
		case FLAGGED_MINE:
			return '#';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';

		default: {
			cerr << "Something went wrong" << endl;
			return ' ';
		}
	}

}
void drawBoard(int board[9][9], int row, int col, int remainingMines) {
	system("CLS");
	cout << "------------------------------------" << endl;
	for (int i = 0; i < 9; i++) {
		cout << "| ";
		for (int j = 0; j < 9; j++) {
			cout <<  convertToCharacter(board[i][j]) << " | ";
		}
		cout << endl << "------------------------------------" << endl;
	
	}
	
	setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
	cout << "You have " << remainingMines << " mines left!" << endl;
	cout << "Use the arrow keys to move around the cells, press space to reveal, X to mark/unmark as mine" << endl;
	setCursor(row, col);
}

int getNumSurroundingMines(int board[9][9], int row, int col) {
	int left = max(0, col - 1);
	int right = min(col + 1, 8);
	int top = max(0, row - 1);
	int bottom = min(row + 1, 8);

	int count = 0;

	for (int i = top; i <= bottom; i++) {
		for (int j = left; j <= right; j++) {
			//cout << "Board " << board[i][j] << endl;
			if (i == row && j == col) {
				continue;
			}
			if (board[i][j] == MINE || board[i][j] == FLAGGED_MINE) {
				
				count++;
			}
		}
	}

	return count;
}

void resetBoard(int board[9][9]) {

	// set everything to blank first
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = SAFE;
		}
	}

	// set 10 mines (we can also do this with rand() but for now it's hand-picked
	board[0][0] = MINE;
	board[1][2] = MINE;
	board[1][3] = MINE;
	board[3][3] = MINE;
	board[3][6] = MINE;
	board[4][5] = MINE;
	board[6][2] = MINE;
	board[7][6] = MINE;
	board[7][7] = MINE;
	board[8][1] = MINE;
}

bool checkWin(int board[9][9]) {
	int mines = 0;
	int total = 81;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int cell = board[i][j];
			if (cell != SAFE && cell != MINE) {
				total--;
			}
			if (cell == FLAGGED_MINE) {
				mines++;
			}
		}
	}
	return (total == 0 && mines == 10);
}

void getInputKeyboard(int board[9][9], int & newX, int & newY, ACTION &action, int remainingMines) {
	int row = newX;
	int col = newY;

	while (1) {		

		if (GetAsyncKeyState(VK_LEFT) & 1)// 0x8000)
		{
			col = max(col - 1, 0);

			drawBoard(board, row, col, remainingMines);
		}
		else if (GetAsyncKeyState(VK_UP) & 1)//0x8000) 
		{
			row = max(row - 1, 0);
			drawBoard(board, row, col, remainingMines);
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 1)//0x8000) 
		{
			col = min(col + 1, 8);
			drawBoard(board, row, col, remainingMines);
		}
		else if (GetAsyncKeyState(VK_DOWN) & 1)//0x8000) 
		{
			row = min(row + 1, 8);
			drawBoard(board, row, col, remainingMines);
		}
		else if (GetAsyncKeyState(VK_SPACE) & 1)//0x8000) 
		{
			newX = row;
			newY = col;
			action = REVEAL;
			break;
		}
		else if (GetAsyncKeyState('X') & 1)//0x8000) 
		{
			newX = row;
			newY = col;
			action = MARK;
			break;
		}
	}
}

void incrementDir(DIRECTION dir, int& row, int& col) {
	switch (dir) {
	case LEFT:
		col = max(0, col - 1);
		break;
	case RIGHT:
		col = min(8, col + 1);
		break;
	case UP:
		row = max(0, row - 1);
		break;
	case DOWN:
		row = min(8, row + 1);
		break;
	}
}

int revealTillNonzero(int board[9][9], int row, int col, DIRECTION dir) {
	int mineCount = -1;
	int newR = row;
	int newC = col;
	int rowBoundary;
	int colBoundary;

	switch (dir) {
	case LEFT:
		newC = max(0, col - 1);
		colBoundary = 0;
		rowBoundary = -1;
		break;
	case RIGHT:
		newC = min(8, col + 1);
		colBoundary = 8;
		rowBoundary = -1;
		break;
	case UP:
		newR = max(0, row - 1);
		rowBoundary = 0;
		colBoundary = -1;
		break;
	case DOWN:
		newR = min(8, row + 1);
		rowBoundary = 8;
		colBoundary = -1;
		break;
	}
	
	while (newR != rowBoundary && newC != colBoundary) {
		if (board[newR][newC] == MINE) {
			break;
		}
		else {
			mineCount = getNumSurroundingMines(board, newR, newC);
			if (mineCount == 0) {
				board[newR][newC] = REVEALED_0;
			}
			else {
				board[newR][newC] = mineCount;
				break;
			}
		}
		incrementDir(dir, newR, newC);
	}
	if (dir == LEFT || dir == RIGHT) {
		return newC;
	}
	if (dir == UP || dir == DOWN) {
		return newR;
	}
}
// The user revealed a zero at passed row and col, reveal all surrounding zeros
// and one other non-mine cell bordering on the zeros
void autoReveal(int board[9][9], int row, int col) {

	// left side
	revealTillNonzero(board, row, col, LEFT);
	revealTillNonzero(board, row, col, RIGHT);
	int upBound = revealTillNonzero(board, row, col, UP);
	int bottomBound = revealTillNonzero(board, row, col, DOWN);
	
	//Top left quadrant
	for (int i = row-1; i >= upBound; i--) {
		revealTillNonzero(board, i, col, LEFT);
	}
	
	// Bottom left quadrant
	for (int i = row+1; i <= bottomBound; i++) {
		revealTillNonzero(board, i, col, LEFT);
	}

	// Top right quadrant
	for (int i = row - 1; i >= upBound; i--) {
		revealTillNonzero(board, i, col, RIGHT);
	}

	// Bottom right quadrant
	for (int i = row + 1; i <= bottomBound; i++) {
		revealTillNonzero(board, i, col, RIGHT);
	}
}

int main() {

	int board[9][9];
	resetBoard(board);
	bool gameover = false;
	int newX = 0;
	int newY = 0;
	ACTION choice = REVEAL;
	int remainingMines = 10;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.bVisible = TRUE;
	ConsoleCursorInfo.dwSize = 100;
	SetConsoleCursorInfo(hConsole, &ConsoleCursorInfo);
	
	
	while (!gameover) {

		drawBoard(board, newX, newY, remainingMines);

		getInputKeyboard(board, newX, newY, choice, remainingMines);

		if (choice == MARK) {
			if (board[newX][newY] == MINE) {
				board[newX][newY] = FLAGGED_MINE;
				remainingMines--;
			}
			else if (board[newX][newY] == FLAGGED_MINE) {
				board[newX][newY] = MINE;
				remainingMines++;
			}
			else if (board[newX][newY] == FLAG) {
				board[newX][newY] = SAFE;
				remainingMines++;
			}
			else {
				board[newX][newY] = FLAG;
				remainingMines--;
			}
		}
		else if (choice == REVEAL) {

			if (board[newX][newY] == MINE) {
				board[newX][newY] = REVEALED_MINE;
				drawBoard(board, newX, newY, remainingMines);
				setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
				cout << "You stepped on a mine! Game Over!" << endl;
				gameover = true;
			}
			else {
				if (board[newX][newY] == FLAG || board[newX][newY] == FLAGGED_MINE) {
					remainingMines++;
				}
				int numMines = getNumSurroundingMines(board, newX, newY);
				if (numMines == 0) {
					board[newX][newY] = REVEALED_0;
					autoReveal(board, newX, newY);
				}
				else {
					board[newX][newY] = numMines;
				}
				

			}
		}
		if (checkWin(board)) {
			drawBoard(board, newX, newY, remainingMines);
			setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
			cout << "You found all the mines! Good Job! You won!" << endl;
			gameover = true;
		}
	}

	return 0;
}