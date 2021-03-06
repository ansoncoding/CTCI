#include "pch.h"

using namespace std;

class Minesweeper {

public:
	enum class LEVEL {
		EASY, MEDIUM, HARD
	};


private:
	enum class ACTION {
		REVEAL, MARK, QUIT, RESTART, LEVEL_SELECT
	};
		
	const static int BLK_ON_WHITE = 240;
	const static int BLU_ON_WHITE = 249;
	const static int RED_ON_WHITE = 252;
	const static int GRN_ON_WHITE = 242;
	const static int BRN_ON_WHITE = 244;
	const static int WHT_ON_WHITE = 255;
	const static int PRL_ON_WHITE = 245;
	const static int TL_ON_WHITE = 243;
	const static int GRY_ON_WHITE = 248;
	
	const static int MINE = 9;
	const static int FLAG = 10;
	const static int SAFE = 11;
	const static int REVEALED_MINE = 12;
	const static int FLAGGED_MINE = 13 ;
	

	const int DIALOGUE_XPOSN = 0;
	int DIALOGUE_YPOSN;
	const int GAMEOVER_XPOSN = 0;
	int GAMEOVER_YPOSN;

	const HANDLE m_stdHandle;
	int m_boardW;
	int m_boardH;
	int* m_board = nullptr;
	bool m_gameover;
	int m_remainingMines;
	int m_totalMines;
	ACTION m_choice;
	int m_xposn;
	int m_yposn;

	void setCursorPosn(int x, int y) const {
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x, y };
		SetConsoleCursorPosition(m_stdHandle, pos);
	}

	void setCursor(int col, int row) const {
		int consoleY = 1 + (row) * 2;
		int consoleX = 2 + (col) * 4;
		setCursorPosn(consoleX, consoleY);
	}

	constexpr static pair<char, int> convertToCharacter(int boardNum) {
		switch (boardNum) {
		
		case REVEALED_MINE:
			return { '*', RED_ON_WHITE };
		case MINE:
		case SAFE:
			return { ' ', WHT_ON_WHITE };
		case FLAG:
		case FLAGGED_MINE:
			return { '#', RED_ON_WHITE };
		case 0:
			return { '0', GRY_ON_WHITE };
		case 1:
			return { '1', BLU_ON_WHITE };
		case 2:
			return { '2', GRN_ON_WHITE };
		case 3:
			return { '3', RED_ON_WHITE };
		case 4:
			return { '4', PRL_ON_WHITE };
		case 5:
			return { '5', BRN_ON_WHITE };
		case 6:
			return { '6', TL_ON_WHITE };
		case 7:
			return { '7', BLK_ON_WHITE };
		case 8:
			return { '8', GRY_ON_WHITE };

		default: {
			cerr << "Something went wrong" << endl;
			return { ' ', WHT_ON_WHITE };
		}
		}
	}

	void updateCursor() {
		setCursor(m_xposn, m_yposn);
	}
	
	void updateCellsAndMines(int col, int row, int val) {
		
		SetConsoleTextAttribute(m_stdHandle, RED_ON_WHITE);
		setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
		cout << "You have " << m_remainingMines << " mines left!" << endl;
		setCursor(col, row);
		auto [ch, color] = convertToCharacter(val);
		
		SetConsoleTextAttribute(m_stdHandle, color);
		cout << ch;
	}

	void drawBoard() const {
		
		SetConsoleTextAttribute(m_stdHandle, BLK_ON_WHITE);
		system("CLS");
		cout <<  setfill('-') << setw((m_boardW << 2) + 1) << "-"  << endl;
		for (int y = 0; y < m_boardH; y++) {
			cout << "| ";
			for (int x = 0; x < m_boardW; x++) {
				auto [val, color] = convertToCharacter(getCell(x, y));
				SetConsoleTextAttribute(m_stdHandle, color);
				cout << val ;
				SetConsoleTextAttribute(m_stdHandle, BLK_ON_WHITE);
				cout << " | ";
			}
			cout << endl << setfill('-') << setw((m_boardW << 2) + 1) << "-"  << endl;

		}
		SetConsoleTextAttribute(m_stdHandle, RED_ON_WHITE);
		setCursorPosn(DIALOGUE_XPOSN, DIALOGUE_YPOSN);
		cout << "You have " << m_remainingMines << " mines left!" << endl;
		SetConsoleTextAttribute(m_stdHandle, BLK_ON_WHITE);
		cout << "Arrow keys to move" << endl;
		cout << "Space to reveal" << endl;
		cout << "X to mark / unmark as mine" << endl;
		cout << "Q to quit" << endl;
		cout << "R to restart" << endl;
		cout << "L to play different level" << endl;
		setCursor(m_xposn, m_yposn);
	}

	bool revealSurroundingSqr(int col, int row) {

		bool floodfill = false;
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
						updateCellsAndMines(x, y, n);

						if (n == 0) {
							autoRevealAll(x, y, true);
							floodfill = true;
						}
					}
					else if (cell == MINE) {
						stepOnMine(x, y);
					}
				}
			}
		}
		return floodfill;
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

	void consoleSettings() {
		int minX = 5 * m_boardW;
		int minY = 2 * m_boardH + 10;

		// Get current console settings
		CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
		if (!GetConsoleScreenBufferInfo(m_stdHandle, &screenBufferInfo)) {
			cerr << "Error trying to get console screen buffer info: err " << GetLastError() << endl;
			return;
		}

		// Compare with required settings to play game
		COORD currentBuffSize = screenBufferInfo.dwSize;
		if (currentBuffSize.X < minX || currentBuffSize.Y < minY) {

			COORD buffSize;
			buffSize.X = minX;
			buffSize.Y = minY;
			if (!SetConsoleScreenBufferSize(m_stdHandle, buffSize)) {
				cerr << "Error trying to set console screen buffer info: err " << GetLastError() << endl;
				return;
			}
		}

		int currentW = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left;
		int currentH = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top;
		
		if (currentW < minX || currentH < minY) {
			SMALL_RECT rectSize;
			rectSize.Top = 0;
			rectSize.Bottom = minY-1;
			rectSize.Left = 0;
			rectSize.Right = minX-1;
			if (!SetConsoleWindowInfo(m_stdHandle, true, &rectSize)) {
				cerr << "Error trying to set console screen info: err " << GetLastError() << endl;
				return;
			}
		}
	}

	void resetBoard(int width, int height, int numMines) {
		m_boardW = width;
		m_boardH = height;
		m_gameover = false;
		m_remainingMines = numMines;
		m_totalMines = numMines;
		m_choice = ACTION::REVEAL;
		m_xposn = 0;
		m_yposn = 0;
		DIALOGUE_YPOSN = height * 2 + 2;
		GAMEOVER_YPOSN = height;

		m_board = new int[m_boardW * m_boardH];
		m_remainingMines = m_totalMines;

		// set everything to blank first
		for (int y = 0; y < m_boardH; y++) {
			for (int x = 0; x < m_boardW; x++) {
				setCell(x, y, SAFE);
			}
		}
		generateMines();

		consoleSettings();
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
	
	bool KeyEventProc(KEY_EVENT_RECORD ker)
	{
		bool retval = false;

		switch (ker.wVirtualKeyCode) {

			case VK_LEFT:
			{
				m_xposn = max(m_xposn - 1, 0);
				updateCursor();
				break;
			}
			case VK_UP:
			{
				m_yposn = max(m_yposn - 1, 0);
				updateCursor();
				break;
			}
			case VK_RIGHT:
			{
				m_xposn = min(m_xposn + 1, m_boardW - 1);
				updateCursor();
				break;
			}
			case VK_DOWN:
			{
				m_yposn = min(m_yposn + 1, m_boardH - 1);
				updateCursor();
				break;
			}
			case VK_SPACE:
			{
				m_choice = ACTION::REVEAL;
				retval = true;
				break;
			}
			case 0x58: // X
			{
				m_choice = ACTION::MARK;
				retval = true;
				break;
			}
			case 0x51: //Q
			{
				m_choice = ACTION::QUIT;
				retval = true;
				break;
			}
			case 0x52: //R
			{
				m_choice = ACTION::RESTART;
				retval = true;
				break;
			}
			case 0x4C: //L
			{
				m_choice = ACTION::LEVEL_SELECT;
				retval = true;
				break;
			}
		}
		return retval;
	}

	void getInputKeyboard() {

		DWORD cNumRead;
		INPUT_RECORD irInBuf;
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		bool breakLoop = false;

		while (!breakLoop) {

			if (ReadConsoleInput(hStdin, &irInBuf, 1, &cNumRead) && (irInBuf.EventType == KEY_EVENT) && (!irInBuf.Event.KeyEvent.bKeyDown)) {
				
				breakLoop = KeyEventProc(irInBuf.Event.KeyEvent);
			}
		}
	}

	bool isOnBoard(int col, int row) const {

		return row >= 0 && row < m_boardH && col >= 0 && col < m_boardW;
	}

	constexpr static bool continueFill(int cell) {
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
		
		CONSOLE_CURSOR_INFO ConsoleCursorInfo;
		ConsoleCursorInfo.bVisible = TRUE;
		ConsoleCursorInfo.dwSize = 100;
		SetConsoleCursorInfo(m_stdHandle, &ConsoleCursorInfo);
	}

	void stepOnMine(int col, int row) {
		setCell(col, row, REVEALED_MINE);
		drawBoard();
		setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
		cout << "You stepped on a mine! Game Over! Press R to play again, Q to quit, L to play different level" << endl;

		cout << " _____" << endl;
		cout << "/ ____|" << endl;
		cout << "| |  __  __ _ _ __ ___   ___  _____   _____ _ __" << endl;
		cout << "| | |_ |/ _` | '_ ` _ \\ / _ \\/ _ \\ \\ / /_ \\ '__|" << endl;
		cout << "| |__| | (_| | | | | | | __ / (_) \\ V / __/ |" << endl;
		cout << "\\_____ |\\__,_|_| |_| |_|\\___|\\___ /\\_/\\___|_|" << endl;

		getInputKeyboard();
	}

	void cleanup() {
		if (m_board != nullptr) {
			delete[] m_board;
			m_board = nullptr;
		}
	}

	Minesweeper(): m_stdHandle(GetStdHandle(STD_OUTPUT_HANDLE)) {

		LEVEL level = levelSection();
		auto [w, h, mines] = getGameSettings(level);
		resetBoard(w, h, mines);
		initConsole();
	}
	
	void winScreen() const {
		system("CLS");

		setCursorPosn(GAMEOVER_XPOSN, GAMEOVER_YPOSN);
		cout << "__     ______  _    _  __          ______  _   _ _ " << endl;
		cout << "\\ \\   / / __ \\| |  | | \\ \\        / / __ \\| \\ | | |" << endl;
		cout << " \\ \\_/ / |  | | |  | |  \\ \\  /\\  / / |  | |  \\| | |" << endl;
		cout << "  \\   /| |  | | |  | |   \\ \\/  \\/ /| |  | | . ` | |" << endl;
		cout << "   | | | |__| | |__| |    \\  /\\  / | |__| | |\\  |_|" << endl;
		cout << "   |_|  \\____/ \\____/      \\/  \\/   \\____/|_| \\_(_)" << endl << endl;

		cout << "You found all the mines! Good Job! Q to exit, R to play again, L to play different level" << endl;
	}

	void playInternal() {

		bool updateBoard = true;

		while (!m_gameover) {
			
			if (updateBoard) {
				drawBoard();
				updateBoard = false;
			}
			getInputKeyboard();

			if (m_choice == ACTION::MARK) {
				int cell = getCell(m_xposn, m_yposn);
				if (cell == MINE) {
					setCell(m_xposn, m_yposn, FLAGGED_MINE);
					m_remainingMines--;
					updateCellsAndMines(m_xposn, m_yposn, FLAGGED_MINE);
				}
				else if (cell == FLAGGED_MINE) {
					setCell(m_xposn, m_yposn, MINE);
					m_remainingMines++;
					updateCellsAndMines(m_xposn, m_yposn, MINE);
				}
				else if (cell == FLAG) {
					setCell(m_xposn, m_yposn, SAFE);
					m_remainingMines++;
					updateCellsAndMines(m_xposn, m_yposn, SAFE);
				}
				else {
					setCell(m_xposn, m_yposn, FLAG);
					m_remainingMines--;
					updateCellsAndMines(m_xposn, m_yposn, FLAG);
				}
			}
			else if (m_choice == ACTION::REVEAL) {
				int cell = getCell(m_xposn, m_yposn);
				if (cell == MINE || cell == FLAGGED_MINE) {
					stepOnMine(m_xposn, m_yposn);
				}
				else if (cell >= 1 && cell <= 7) {
					updateBoard = revealSurroundingSqr(m_xposn, m_yposn);
				}
				else {
					if (cell == FLAG || cell == FLAGGED_MINE) {
						m_remainingMines++;
					}
					int numMines = getNumSurroundingMines(m_xposn, m_yposn, false);
					setCell(m_xposn, m_yposn, numMines);
					updateCellsAndMines(m_xposn, m_yposn, numMines);
					if (numMines == 0) {
						autoRevealAll(m_xposn, m_yposn, true);
						updateBoard = true;
					}
				}
			}

			if (m_choice == ACTION::REVEAL || m_choice == ACTION::MARK) {
				if (checkWin()) {

					drawBoard();
					winScreen();
					getInputKeyboard();
				}
			}

			if (m_choice == ACTION::QUIT) {
				system("exit");
				m_gameover = true;
			}

			if (m_choice == ACTION::RESTART) {
				cleanup();
				resetBoard();
				updateBoard = true;
			}

			if (m_choice == ACTION::LEVEL_SELECT) {
				LEVEL level = levelSection();
				auto [w, h, mines] = getGameSettings(level);
				cleanup();
				resetBoard(w, h, mines);
				updateBoard = true;
			}
			
		}
	}

	constexpr static tuple<int, int, int> getGameSettings(LEVEL level) {
		switch (level) {
		case LEVEL::EASY:
			return { 9, 9, 10 };
		case LEVEL::MEDIUM:
			return { 16, 16, 40 };
		case LEVEL::HARD:
			return { 30, 16, 99 };
		}
	}

	static LEVEL levelSection() {

		Minesweeper::LEVEL level = Minesweeper::LEVEL::EASY;
		char i;

		system("CLS");
		cout << "Welcome to minesweeper" << endl;
		cout << "Please choose difficulty:" << endl;
		cout << " 1 - easy" << endl;
		cout << " 2 - medium" << endl;
		cout << " 3 - hard" << endl;
		
		i = getchar();

		char t; // to get rid of newline character from stream
		while ((t = getchar()) != '\n' && i != EOF);

		cout << " You have chosen level " << i << endl;
		switch (i) {
		case '2':
			level = Minesweeper::LEVEL::MEDIUM;
			break;
		case '3':
			level = Minesweeper::LEVEL::HARD;
			break;
		}
		
		return level;
	}
public:

	Minesweeper(const Minesweeper& other) = delete;

	Minesweeper& operator=(const Minesweeper& other) = delete;

	static Minesweeper& getInstance() {
		
		static Minesweeper game;
		return game;
	}

	static void play() {
		
		return getInstance().playInternal();
	}

	~Minesweeper() {
		cleanup();
	}
};

int main() {

	Minesweeper::play();
	
	return 0;
}