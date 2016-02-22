/*
 * dirkbrink.cpp
 *
 *  Created on: 21 Feb 2016
 *      Author: Dirk
 */

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#define SIZE 4

using namespace std;

struct row{
	int one, two, three, four;
};

void print_grid(int the_grid[SIZE][SIZE]);
bool what_move(string action, int the_grid[SIZE][SIZE]);
bool move_down(int the_grid[SIZE][SIZE]);
bool move_up(int the_grid[SIZE][SIZE]);
bool move_right (int the_grid[SIZE][SIZE]);
bool move_left (int the_grid[SIZE][SIZE]);
void generate_two (int the_grid[SIZE][SIZE]);
bool is_gameover(int the_grid[SIZE][SIZE]);

int main(){
	ifstream base_start;
	string filename;
	row input;
	int grid[SIZE][SIZE];

	cout << "Enter initial file configuration name:" << endl;
	cin >> filename;
	base_start.open(filename.c_str());

	if (!base_start.is_open()){
		cout << "File not found, using default start configuration" << endl;
		for (int i = 0; i < SIZE; i++){
			for (int j = 0; j < SIZE; j++){
				grid[i][j] = 0;
			}
		}
		grid[SIZE-1][SIZE-1] = 2;
	}
	else {
		int row_counter = 0;
		while (base_start >> input.one >> input.two >> input.three >> input.four){
			grid[row_counter][0] = input.one;
			grid[row_counter][1] = input.two;
			grid[row_counter][2] = input.three;
			grid[row_counter][3] = input.four;
			row_counter ++;
		}
	}
	print_grid(grid);

	string move;
	bool moved;
	bool gameover = false;
	while (gameover == false){
		cin >> move;
		moved = what_move(move, grid);
		if (moved){
			generate_two(grid);
			print_grid(grid);
		}
		gameover = is_gameover(grid);
	}
	cout << endl << "Game over" << endl;
	return 0;
}

void print_grid(int the_grid[SIZE][SIZE]){
	for (int row = 0; row < SIZE; row ++){
		for (int col = 0; col < SIZE; col ++){
			cout << setw(8) << left << the_grid[row][col];
		}
		cout << endl;
	}
}

bool what_move(string action, int the_grid[SIZE][SIZE]){
	bool has_moved = false;
	if (action == "s"){
		has_moved = move_down(the_grid);
	}
	else if (action == "w"){
		has_moved = move_up(the_grid);
	}
	else if (action == "d"){
		has_moved = move_right(the_grid);
	}
	else if (action == "a"){
		has_moved = move_left(the_grid);
	}
	return has_moved;
}

void generate_two (int the_grid[SIZE][SIZE]){
	int row_rand, col_rand;
	srand(time(NULL));
	row_rand = rand() % 4;
	col_rand = rand() % 4;

	while (the_grid[row_rand][col_rand] != 0){
		row_rand = rand() % 4;
		col_rand = rand() % 4;
	}
	the_grid[row_rand][col_rand] = 2;
}

bool is_gameover (int the_grid[SIZE][SIZE]){
	bool gameover = true;
	for (int row = 0; row < SIZE && gameover == true; row ++){
		for (int col = 0; col < SIZE - 1 && gameover == true; col ++){
			if (the_grid[row][col] == 0 || the_grid[row][col] == the_grid[row][col +1]){
				gameover = false;
			}
		}
	}
	for (int col = 0; col < SIZE && gameover == true; col ++){
		for (int row = 0; row < SIZE - 1 && gameover == true; row ++){
			if (the_grid[row][col] == 0 || the_grid[row][col] == the_grid[row + 1][col]){
				gameover = false;
			}
		}
	}
	return gameover;
}

bool move_up (int the_grid[SIZE][SIZE]){
	int holder;
	bool terminate;
	bool moved = false;
	for (int col = 0; col < SIZE; col ++){
		holder = 0;
		for (int row = 0; row <= SIZE - 1; row ++){
			terminate = false;
			if (the_grid[row][col] != 0){
				for (int position = row + 1; position < SIZE && terminate == false; position ++){
					if (the_grid[row][col] == the_grid[position][col]){
						the_grid[holder][col] = the_grid[row][col] * 2;
						the_grid[position][col] = 0;
						if (holder != row){
							the_grid[row][col] = 0;
						}
						moved = true;
						terminate = true;
					}
					else if (the_grid[position][col] != 0 || position == SIZE-1){
						the_grid[holder][col] = the_grid[row][col];
						if (holder != row){
							the_grid[row][col] = 0;
							moved = true;
						}
						terminate = true;
					}
				}
				if (row == SIZE - 1 && holder < row){
					the_grid[holder][col] = the_grid[row][col];
					the_grid[row][col] = 0;
					moved = true;
				}
				holder ++;
			}
		}
	}
	return moved;
}

bool move_down (int the_grid[SIZE][SIZE]){
	int holder;
	bool terminate;
	bool moved = false;
	for (int col = 0; col < SIZE; col ++){
		holder = SIZE - 1;
		for (int row = SIZE - 1; row >= 0; row --){
			terminate = false;
			if (the_grid[row][col] != 0){
				for (int position = row - 1; position >= 0 && terminate == false; position --){
					if (the_grid[row][col] == the_grid[position][col]){
						the_grid[holder][col] = the_grid[row][col] * 2;
						the_grid[position][col] = 0;
						if (holder != row){
							the_grid[row][col] = 0;
						}
						moved = true;
						terminate = true;
					}
					else if (the_grid[position][col] != 0 || position == 0){
						the_grid[holder][col] = the_grid[row][col];
						if (holder != row){
							the_grid[row][col] = 0;
							moved = true;
						}
						terminate = true;
					}
				}
				if (row == 0 && holder > row){
					the_grid[holder][col] = the_grid[row][col];
					the_grid[row][col] = 0;
					moved = true;
				}
				holder --;
			}
		}
	}
	return moved;
}

bool move_right (int the_grid[SIZE][SIZE]){
	int holder;
	bool terminate;
	bool moved = false;
	for (int row = 0; row < SIZE; row ++){
		holder = SIZE - 1;
		for (int col = SIZE - 1; col >= 0; col --){
			terminate = false;
			if (the_grid[row][col] != 0){
				for (int position = col - 1; position >= 0 && terminate == false; position --){
					if (the_grid[row][col] == the_grid[row][position]){
						the_grid[row][holder] = the_grid[row][col] * 2;
						the_grid[row][position] = 0;
						if (holder != col){
							the_grid[row][col] = 0;
						}
						moved = true;
						terminate = true;
					}
					else if (the_grid[row][position] != 0 || position == 0){
						the_grid[row][holder] = the_grid[row][col];
						if (holder != col){
							the_grid[row][col] = 0;
							moved = true;
						}
						terminate = true;
					}
				}
				if (col == 0 && holder > col){
					the_grid[row][holder] = the_grid[row][col];
					the_grid[row][col] = 0;
					moved = true;
				}
				holder --;
			}
		}
	}
	return moved;
}

bool move_left (int the_grid[SIZE][SIZE]){
	int holder;
	bool terminate;
	bool moved = false;
	for (int row = 0; row < SIZE; row ++){
		holder = 0;
		for (int col = 0; col <= SIZE - 1; col ++){
			terminate = false;
			if (the_grid[row][col] != 0){
				for (int position = col + 1; position < SIZE && terminate == false; position ++){
					if (the_grid[row][col] == the_grid[row][position]){
						the_grid[row][holder] = the_grid[row][col] * 2;
						the_grid[row][position] = 0;
						if (holder != col){
							the_grid[row][col] = 0;
						}
						moved = true;
						terminate = true;
					}
					else if (the_grid[row][position] != 0 || position == SIZE-1){
						the_grid[row][holder] = the_grid[row][col];
						if (holder != col){
							the_grid[row][col] = 0;
							moved = true;
						}
						terminate = true;
					}
				}
				if (col == SIZE - 1 && holder < col){
					the_grid[row][holder] = the_grid[row][col];
					the_grid[row][col] = 0;
					moved = true;
				}
				holder ++;
			}
		}
	}
	return moved;
}





