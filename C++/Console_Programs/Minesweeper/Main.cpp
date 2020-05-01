#include "pch.h"

using namespace std;

class Minesweeper {

public:
	enum class LEVEL {
		EASY, MEDIUM, HARD
	};


private:
	enum class ACTION {
		REVEAL, MARK, QUIT, RESTART
	};

	const static int MINE = 9;
	const static int FLAG = 10;
	const static int SAFE = 11;
	const static int REVEALED_MINE = 12;
	const static int FLAGGED_MINE = 13 ;
	

	const int DIALOGUE_XPOSN = 0;
	const int DIALOGUE_YPOSN;
	const int GAMEOVER_XPOSN = 0;
	const int GAMEOVER_YPOSN;

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

	static void setCursor(int col, int row) {
		int consoleY = 1 + (row) * 2;
		int consoleX = 2 + (col) * 4;
		setCursorPosn(consoleX, consoleY);
	}

	static char convertToCharacter(int boardNum) {
		switch (boardNum) {
		
		case REVEALED_MINE:
			return '*';
		case MINE:
		case SAFE:
			return ' ';
		case FLAG:
		case FLAGGED_MINE:
			return '#';
		case 0:
			return '0';
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
	void updateCursor() {
		setCursor(m_xposn, m_yposn);
	}

	void drawBoard() const {
		system("CLS");
		cout <<  setfill('-') << setw((m_boardW << 2) + 1) << "-"  << endl;
		for (int y = 0; y < m_boardH; y++) {
			cout << "| ";
			for (int x = 0; x < m_boardW; x++) {
				cout << convertToCharacter(getCell(x, y)) << " | ";
			}
			cout << endl << setfill('-') << setw((m_boardW << 2) + 1) << "-"  << endl;

		}

		setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
		cout << "You have " << m_remainingMines << " mines left!" << endl;
		cout << "Arrow keys to move" << endl;
		cout << "Space to reveal" << endl;
		cout << "X to mark / unmark as mine" << endl;
		cout << "Q to quit" << endl;
		cout << "R to restart" << endl;
		setCursor(m_xposn, m_yposn);
	}

	void revealSurroundingSqr(int col, int row) {

		int identifiedMines = getNumSurroundingMines(m_xposn, m_yposn, true);

		if (identifiedMines == getCell(col, row)) {
			int left = max(0, col - 1);
			int right = min(col + 1, m_boardW - 1);
			int top = max(0, row - 1);
			int bottom = min(row + 1, m_boardH - 1);

			int count = 0;

			for (int y = top; y <= bottom; y++) {
				for (int x = left; x <= right; x++) {
					if (y == row && x == col) {
						continue;
					}
					int cell = getCell(x, y);
					if (cell == SAFE) {
						int n = getNumSurroundingMines(x, y, false);
						
						setCell(x, y, n);
						
						if (n == 0) {
							autoRevealAll(x, y, true);
						}
					}
					else if (cell == MINE) {
						stepOnMine(x, y);
					}
				}
			}
		}
	}

	int getNumSurroundingMines(int col, int row, bool flaggedOnly) const {
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
				if (flaggedOnly) {
					if (cell == FLAGGED_MINE || cell == FLAG) {
						count++;
					}
				}
				else {
					if (cell == MINE || cell == FLAGGED_MINE) {

						count++;
					}
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

	void generateMines() {
		srand(time(nullptr));
		int count = 0;
		int totalCells = m_boardH * m_boardW;
		while (count < m_totalMines) {
			int cell = rand() % totalCells;
			if (m_board[cell] != MINE) {
				m_board[cell] = MINE;
				count++;
			}
		}
	}

	void resetBoard() {

		m_board = new int[m_boardW * m_boardH];
		m_remainingMines = m_totalMines;

		// set everything to blank first
		for (int y = 0; y < m_boardH; y++) {
			for (int x = 0; x < m_boardW; x++) {
				setCell(x, y, SAFE);
			}
		}
		generateMines();
	}

	bool checkWin() const {
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

				updateCursor();
			}
			else if (GetAsyncKeyState(VK_UP) & 1)//0x8000) 
			{
				m_yposn = max(m_yposn - 1, 0);
				updateCursor();
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 1)//0x8000) 
			{
				m_xposn = min(m_xposn + 1, m_boardW-1);
				updateCursor();
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)//0x8000) 
			{
				m_yposn = min(m_yposn + 1, m_boardH-1);
				updateCursor();
			}
			else if (GetAsyncKeyState(VK_SPACE) & 1)//0x8000) 
			{
				m_choice = ACTION::REVEAL;
				break;
			}
			else if (GetAsyncKeyState('X') & 1)//0x8000) 
			{
				m_choice = ACTION::MARK;
				break;
			}
			else if (GetAsyncKeyState('Q') & 1)//0x8000) 
			{
				m_choice = ACTION::QUIT;
				break;
			}
			else if (GetAsyncKeyState('R') & 1)//0x8000) 
			{
				m_choice = ACTION::RESTART;
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
	void autoRevealAll(int col, int row, bool skipCheck) {

		if (!isOnBoard(col, row)) {
			return;
		}

		int cell = getCell(col, row);
		if (skipCheck || continueFill(cell)) {
			int n = getNumSurroundingMines(col, row, false);
			
			setCell(col, row, n);
			
			if (n == 0) {
				autoRevealAll(col, row + 1, false); //south
				autoRevealAll(col, row - 1, false); //north
				autoRevealAll(col + 1, row, false); //east
				autoRevealAll(col - 1, row, false); //west
			}
		}
		return;
	}

	void initConsole() {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO ConsoleCursorInfo;
		ConsoleCursorInfo.bVisible = TRUE;
		ConsoleCursorInfo.dwSize = 100;
		SetConsoleCursorInfo(hConsole, &ConsoleCursorInfo);
	}

	void waitForUserAction() {
		while (1) {
			if (GetAsyncKeyState('R') & 1)
			{
				m_choice = ACTION::RESTART;
				break;
			}
			else if (GetAsyncKeyState('Q') & 1)
			{
				m_choice = ACTION::QUIT;
				m_gameover = true;
				break;
			}
		}
	}

	void stepOnMine(int col, int row) {
		setCell(col, row, REVEALED_MINE);
		drawBoard();
		setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
		cout << "You stepped on a mine! Game Over! Press R to play again, Q to quit" << endl;

		cout << " _____" << endl;
		cout << "/ ____|" << endl;
		cout << "| |  __  __ _ _ __ ___   ___  _____   _____ _ __" << endl;
		cout << "| | |_ |/ _` | '_ ` _ \\ / _ \\/ _ \\ \\ / /_ \\ '__|" << endl;
		cout << "| |__| | (_| | | | | | | __ / (_) \\ V / __/ |" << endl;
		cout << "\\_____ |\\__,_|_| |_| |_|\\___|\\___ /\\_/\\___|_|" << endl;

		waitForUserAction();
	}

	void cleanup() {
		if (m_board != nullptr) {
			delete[] m_board;
			m_board = nullptr;
		}
	}

	Minesweeper(int width, int height, int numMines)
		: m_boardW(width), 
		m_boardH(height), 
		m_gameover(false), 
		m_remainingMines(numMines), 
		m_totalMines(numMines), 
		m_choice(ACTION::REVEAL), 
		m_xposn(0), m_yposn(0), 
	DIALOGUE_YPOSN(height * 2 + 3), 
	GAMEOVER_YPOSN(height) {

		resetBoard();
		initConsole();
	}

	void playInternal() {

		while (!m_gameover) {

			drawBoard();
			getInputKeyboard();

			if (m_choice == ACTION::MARK) {
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
			else if (m_choice == ACTION::REVEAL) {
				int cell = getCell(m_xposn, m_yposn);
				if (cell == MINE || cell == FLAGGED_MINE) {
					stepOnMine(m_xposn, m_yposn);
				}
				else if (cell >= 1 && cell <= 7) {
					revealSurroundingSqr(m_xposn, m_yposn);
				}
				else {
					if (cell == FLAG || cell == FLAGGED_MINE) {
						m_remainingMines++;
					}
					int numMines = getNumSurroundingMines(m_xposn, m_yposn, false);
					setCell(m_xposn, m_yposn, numMines);
					if (numMines == 0) {
						autoRevealAll(m_xposn, m_yposn, true);
					}
				}
			}

			if (m_choice == ACTION::QUIT) {
				m_gameover = true;
			}
			if (m_choice == ACTION::RESTART) {
				cleanup();
				resetBoard();
				drawBoard();
			}
			if (!m_gameover && checkWin()) {
				drawBoard();
				setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
				cout << "You found all the mines! Good Job! You won! Q to exit, R to play again" << endl;
				waitForUserAction();
			}
		}
	}

	static tuple<int, int, int> getGameSettings(LEVEL level) {
		switch (level) {
		case LEVEL::EASY:
			return { 9, 9, 10 };
		case LEVEL::MEDIUM:
			return { 16, 16, 40 };
		case LEVEL::HARD:
			return { 16, 30, 99 };
		}
	}
public:
	

	Minesweeper(const Minesweeper& other) = delete;
	Minesweeper& operator=(const Minesweeper& other) = delete;

	static Minesweeper& getInstance(LEVEL level) {
		auto [w, h, mines] = getGameSettings(level);
		static Minesweeper game(w, h, mines);
		return game;
	}

	static void play(LEVEL level) {
		return getInstance(level).playInternal();
	}

	~Minesweeper() {
		cleanup();
	}
};


int main() {

	cout << "Welcome to minesweeper" << endl;
	cout << "Please choose difficulty:" << endl;
	cout << " 1 - easy" << endl;
	cout << " 2 - medium" << endl;
	cout << " 3 - hard" << endl;
	Minesweeper::LEVEL level  = Minesweeper::LEVEL::EASY;
	int i;
	cin >> i;
	
	cout << " You have chosen level " << i << endl;
	switch (i) {
	case 2 :
		level = Minesweeper::LEVEL::MEDIUM;
		break;
	case 3:
		level = Minesweeper::LEVEL::HARD;
		break;
	}
	Minesweeper::play(level);
	
	return 0;
}