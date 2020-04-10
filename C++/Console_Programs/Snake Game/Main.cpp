#include "pch.h"

#include <random>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>

#define HEAD '@'
#define BODY 'O'
#define FOOD '*'

using namespace std;

enum DIRECTION { LEFT, RIGHT, UP, DOWN };

class Snake {
	
private:
	int head_col;
	int head_row;
	DIRECTION dir = LEFT;
	int max_length;
	vector<pair<int, int>> body;
	int board_size;

	void setCursorPosn(int x, int y) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x, y };
		SetConsoleCursorPosition(hConsole, pos);
	}
	void setSymbol(int x, int y, char symbol) {
		setCursorPosn(x, y);
		cout << symbol;
	}
public:
	Snake() {
		this->head_col = 0;
		this->head_row = 0;
		this->max_length = 100;
		this->board_size = 10;
	}

	Snake(int row, int col, int board_size) {
		this->head_col = col;
		this->head_row = row;
		this->max_length = board_size << 1;
		this->board_size = board_size;
	}

	bool headTouchBody() {
		
		for (vector<pair<int, int>>::iterator it = body.begin(); it < body.end(); it++) {
			if ((head_col == it->first) && (head_row == it->second)) {
				return true;
			}
		}
		return false;
	}

	bool collide() {

		return (headTouchBody() ||
			(head_col < 0) ||
			(head_col > (board_size - 1)) ||
			(head_row < 0) ||
			(head_row > (board_size - 1)));
	}

	void updateHead() {
		switch (dir) {
		case UP:
			head_row = head_row - 1;
			break;
		case DOWN:
			head_row = head_row + 1;
			break;
		case LEFT:
			head_col = head_col - 1;
			break;
		case RIGHT:
			head_col = head_col + 1;
			break;
		}
	}

	// according to the direction the snake is heading now we ideally want the body to grow
	// in the opposite direction. E.g. Snake is going left, the body should extend to the right
	// TODO:
	// If there's a wall it should try to find an available spot
	// or -- if the only space left around the tail area is the snake's body it should be game over
	pair<int, int> getNextBodyPosn(int prev_x, int prev_y) {
		int next_x = prev_x;
		int next_y = prev_y;
		switch (dir) {
			case UP:
				next_y += 1;
				break;
			case DOWN:
				next_y -= 1;
				break;
			case LEFT:
				next_x += 1;
				break;
			case RIGHT:
				next_x -= 1;
				break;
		}
		return make_pair(next_x, next_y);
	}

	void grow() {
		
		pair<int, int> next;

		if (body.size()) {
			pair<int, int> last = body.back();
			next = getNextBodyPosn(last.first, last.second);
		}
		else {
			next = getNextBodyPosn(head_col, head_row);
		}
		body.push_back(next);
	}

	void moveBody() {
		if (body.size()) {
			body.pop_back();
			vector<pair<int, int>>::iterator it = body.begin();
			body.insert(it, make_pair(head_col, head_row));
		}
	}

	bool move(DIRECTION direction) {

		dir = direction;
		moveBody();
		updateHead();
		if (collide()) {
			return false;
		}
		return true;
	}

	bool eat(int food_x, int food_y) {
		return (head_row == food_y && head_col == food_x);
	}

	// (zero_x, zero_y) is the top-left corner of the board
	void draw(int zero_x, int zero_y) {
		int head_posnx = zero_x + head_col;
		int head_posny = zero_y + head_row;
		setSymbol(head_posnx, head_posny, HEAD);

		int body_posnx;
		int body_posny;
		for (vector<pair<int, int>>::iterator it = body.begin(); it < body.end(); it++) {
			body_posnx = zero_x + it->first; 
			body_posny = zero_y + it->second;
			setSymbol(body_posnx, body_posny, BODY);
		}
		
	}
};


class Game {

	enum ACTION {QUIT, RESTART, PLAY, GAMEOVER};
	

private:
	
	Snake snake;
	int board_size;
	ACTION action = PLAY;
	int DIALOGUE_X;
	int DIALOGUE_Y;

	void setCursorPosn(int x, int y) {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos = { x, y };
		SetConsoleCursorPosition(hConsole, pos);
	}
	pair<int, int> food;

public:

	Game(int size) {
		this->board_size = size;
		snake = Snake(0, 0, size);
		this->DIALOGUE_X = board_size + 3;
		this->DIALOGUE_Y = board_size + 3;
		//head will start at 0, 0 we don't want the food to fall in the same spot
		int food_x = max(1, rand() % board_size);
		int food_y = max(1, rand() % board_size); 
		food = make_pair(food_x, food_y);
	}

	void reset() {
		snake = Snake(0, 0, board_size);
		int food_x = max(1, rand() % board_size);
		int food_y = max(1, rand() % board_size);
		food = make_pair(food_x, food_y);
		action = PLAY;
		drawBoard();
	}

	void generateFood() {
		int food_x = rand() % board_size;
		int food_y = rand() % board_size;
		food = make_pair(food_x, food_y);
	}

	void waitUserAction() {

		while (action == GAMEOVER) {

			if (GetAsyncKeyState('R') & 1) {
				action = RESTART;
				break;
			}
			else if (GetAsyncKeyState('Q')) {
				action = QUIT;
				break;
			}
		}
	}

	void displayMessage() {
		switch (action) {
			case GAMEOVER: {
				setCursorPosn(DIALOGUE_X, DIALOGUE_Y);
				cout << "Game over, press R to restart, Q to quit " << endl;
				break;
			}
		}
	}

	void play() {

		bool moved = false;
		
		while (action != GAMEOVER) {

			if (GetAsyncKeyState(VK_LEFT) & 1) {
				if (snake.move(LEFT)) {
					moved = true;
				}
				else {
					action = GAMEOVER;
				}
			}
			else if (GetAsyncKeyState(VK_UP) & 1) {
				if (snake.move(UP)) {
					moved = true;
				}
				else {
					action = GAMEOVER;
				}
			}
			else if (GetAsyncKeyState(VK_RIGHT) & 1) {
				if (snake.move(RIGHT)) {
					moved = true;
				}
				else {
					action = GAMEOVER;
				}
			}
			else if (GetAsyncKeyState(VK_DOWN) & 1)	{
				if (snake.move(DOWN)) {
					moved = true;
				}
				else {
					action = GAMEOVER;
				}
			}
			else if (GetAsyncKeyState('Q') & 1) {
				action = QUIT;
				break;
			}
			else if (GetAsyncKeyState('R') & 1)	{
				action = RESTART;
				break;
			}

			if (moved) {
				if (snake.eat(food.first, food.second)) {
					snake.grow();
					generateFood();
				}
				drawBoard();
				moved = false;
			}
		}
		drawBoard();
		displayMessage();
		waitUserAction();
		switch (action) {
		case RESTART:
			reset();
			play();
			break;
		case QUIT:
			return;
		}
	}


	void drawBoard() {
		system("CLS");
		setCursorPosn(0, 0);
		cout << setfill('-') << setw(board_size+2) << "" << endl;
		for (int i = 0; i < board_size; i++) {
			
			cout << "|" << setfill(' ') << setw(board_size+1) << "|" << endl;
		}
		cout << setfill('-') << setw(board_size+2) << "" << endl;

		// draw food
		int food_posnx = food.first + 1;
		int food_posny = food.second + 1;
		setCursorPosn(food_posnx, food_posny);
		cout << FOOD;

		snake.draw(1, 1); // 1, 1, to account for the border which is occupying the 0,0, so left top corner start at 1, 1

		// this is for VS's debug mode (has a blurb at the end)
		setCursorPosn(DIALOGUE_X, DIALOGUE_Y);
	}
};


int main() {

	Game g = Game(10);
	g.drawBoard();
	g.play();
	return 0;
}