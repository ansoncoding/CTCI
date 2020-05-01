#include "pch.h"

using namespace std;

class Minesweeper {

	enum ACTION {
		REVEAL, MARK
	};

private:

	const static int SAFE = 0;
	const static int MINE = 9;
	const static int FLAG = 10;
	const static int REVEALED_0 = 11;
	const static int REVEALED_MINE = 12;
	const static int FLAGGED_MINE = 13 ;

	const static int DIALOGUE_XPOSN = 0;
	const static int DIALOGUE_YPOSN = 21;
	const static int GAMEOVER_XPOSN = 0;
	const static int GAMEOVER_YPOSN = 23;

	int m_boardW;
	int m_boardH;
	int* m_board = nullptr;
	bool m_gameover;
	int m_remainingMines;
	const int m_totalMines;
	ACTION m_choice;
	int m_xposn;
	int m_yposn;

	static void setCursorPosn(int x, int y) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x, y };
		SetConsoleCursorPosition(hConsole, pos);
	}

	static void setCursor(int row, int col) {
		int consoleY = 1 + (row) * 2;
		int consoleX = 2 + (col) * 4;
		setCursorPosn(consoleX, consoleY);
	}

	static void setSymbol(int row, int col, char symbol) {
		int consoleY = 1 + (row) * 2;
		int consoleX = 2 + (col) * 4;
		setCursorPosn(consoleX, consoleY);
		cout << symbol;
	}

	static char convertToCharacter(int boardNum) {
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
	void drawBoard() const {
		system("CLS");
		cout << "------------------------------------" << endl;
		for (int y = 0; y < m_boardH; y++) {
			cout << "| ";
			for (int x = 0; x < m_boardW; x++) {
				cout << convertToCharacter(getCell(x, y)) << " | ";
			}
			cout << endl << "------------------------------------" << endl;

		}

		setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
		cout << "You have " << m_remainingMines << " mines left!" << endl;
		cout << "Use the arrow keys to move around the cells, press space to reveal, X to mark/unmark as mine" << endl;
		setCursor(m_yposn, m_xposn);
	}

	int getNumSurroundingMines(int col, int row) {
		int left = max(0, col - 1);
		int right = min(col + 1, m_boardW-1);
		int top = max(0, row - 1);
		int bottom = min(row + 1, m_boardH-1);

		int count = 0;

		for (int y = top; y <= bottom; y++) {
			for (int x = left; x <= right; x++) {
				
				if (y == row && x == col) {
					continue;
				}
				int cell = getCell(x, y);
				if (cell == MINE || cell == FLAGGED_MINE) {

					count++;
				}
			}
		}

		return count;
	}

	int getCell(int col, int row) const {
		return m_board[col + row * m_boardW];
	}

	void setCell(int col, int row, int val) {
		m_board[col + row * m_boardW] = val;
	}

	void resetBoard() {

		// set everything to blank first
		for (int y = 0; y < m_boardH; y++) {
			for (int x = 0; x < m_boardW; x++) {
				setCell(x, y, SAFE);
			}
		}

		// set 10 mines (we can also do this with rand() but for now it's hand-picked
		setCell(0, 0, MINE);
		setCell(2, 1, MINE);
		setCell(3, 1, MINE);
		setCell(3, 3, MINE);
		setCell(6, 3, MINE);
		setCell(6, 4, MINE);
		setCell(2, 5, MINE);
		setCell(6, 7, MINE);
		setCell(7, 7, MINE);
		setCell(1, 8, MINE);
	}

	bool checkWin() {
		int mines = 0;
		int total = (m_boardW * m_boardH);
		for (int y = 0; y < m_boardH; y++) {
			for (int x = 0; x < m_boardW; x++) {
				int cell = getCell(x, y);
				if (cell != SAFE && cell != MINE) {
					total--;
				}
				if (cell == FLAGGED_MINE) {
					mines++;
				}
			}
		}
		return (total == 0 && mines == m_totalMines);
	}

	void getInputKeyboard() {

		while (1) {

			if (GetAsyncKeyState(VK_LEFT) & 1)// 0x8000)
			{
				m_xposn = max(m_xposn - 1, 0);

				drawBoard();
			}
			else if (GetAsyncKeyState(VK_UP) & 1)//0x8000) 
			{
				m_yposn = max(m_yposn - 1, 0);
				drawBoard();
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 1)//0x8000) 
			{
				m_xposn = min(m_xposn + 1, m_boardW-1);
				drawBoard();
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)//0x8000) 
			{
				m_yposn = min(m_yposn + 1, m_boardH-1);
				drawBoard();
			}
			else if (GetAsyncKeyState(VK_SPACE) & 1)//0x8000) 
			{
				m_choice = REVEAL;
				break;
			}
			else if (GetAsyncKeyState('X') & 1)//0x8000) 
			{
				m_choice = MARK;
				break;
			}
		}
	}

	bool isOnBoard(int col, int row) const {

		return row >= 0 && row < m_boardH && col >= 0 && col < m_boardW;
	}

	static bool continueFill(int cell) {
		switch (cell) {
		case SAFE:
			return true;
		default:
			return false;
		}
	}

	// flood fill algorithm
	void autoRevealAll(int col, int row) {

		if (!isOnBoard(col, row)) {
			return;
		}
		int cell = getCell(col, row);
		if (continueFill(cell)) {
			int n = getNumSurroundingMines(col, row);
			if (n == 0) {
				setCell(col, row, REVEALED_0);

				autoRevealAll(col, row + 1); //south
				autoRevealAll(col, row - 1); //north
				autoRevealAll(col + 1, row); //east
				autoRevealAll(col - 1, row); //west
			}
			else {
				setCell(col, row, n);
			}
		}
		return;
	}

public:
	Minesweeper() : m_boardW(9), m_boardH(9), m_gameover(false), m_remainingMines(10), m_choice(REVEAL), m_xposn(0), m_yposn(0), m_totalMines(10) {
		
		m_board = new int[m_boardW*m_boardH];
		
		resetBoard();

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO ConsoleCursorInfo;
		ConsoleCursorInfo.bVisible = TRUE;
		ConsoleCursorInfo.dwSize = 100;
		SetConsoleCursorInfo(hConsole, &ConsoleCursorInfo);
	}

	void play() {

		while (!m_gameover) {

			drawBoard();
			getInputKeyboard();

			if (m_choice == MARK) {
				int cell = getCell(m_xposn, m_yposn);
				if (cell == MINE) {
					setCell(m_xposn, m_yposn, FLAGGED_MINE);
					m_remainingMines--;
				}
				else if (cell == FLAGGED_MINE) {
					setCell(m_xposn, m_yposn, MINE);
					m_remainingMines++;
				}
				else if (cell == FLAG) {
					setCell(m_xposn, m_yposn, SAFE);
					m_remainingMines++;
				}
				else {
					setCell(m_xposn, m_yposn, FLAG);
					m_remainingMines--;
				}
			}
			else if (m_choice == REVEAL) {
				int cell = getCell(m_xposn, m_yposn);
				if (cell == MINE) {
					setCell(m_xposn, m_yposn, REVEALED_MINE);
					drawBoard();
					setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
					cout << "You stepped on a mine! Game Over!" << endl;
					m_gameover = true;
				}
				else {
					if (cell == FLAG || cell == FLAGGED_MINE) {
						m_remainingMines++;
					}
					int numMines = getNumSurroundingMines(m_xposn, m_yposn);
					if (numMines == 0) {
						autoRevealAll(m_xposn, m_yposn);
					}
					else {
						setCell(m_xposn, m_yposn, numMines);
					}
				}
			}
			if (checkWin()) {
				drawBoard();
				setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
				cout << "You found all the mines! Good Job! You won!" << endl;
				m_gameover = true;
			}
		}
	}

	~Minesweeper() {
		if (m_board != nullptr) {
			delete[] m_board;
			m_board = nullptr;
		}
	}
};


int main() {

	Minesweeper game = Minesweeper();
	game.play();
	
	return 0;
}