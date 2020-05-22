#include "game.h"


/* Function: Game()
   Description: Initializes the boolean values
   Paramters: none
 */
Game::Game() {
	has_gold = false;
	wumpus_killed = false;
	has_died = false;
	arrows_fired = 0;
}


/* Function: start()
   Description: Initializes values from command line, initializes the board, and runs the game
   Paramters: size of the cave and debug mode
 */
void Game::start(int size, char ddebug) {
	cave_size = size;
	debug = ddebug;
	init_board();
	print_cave();
	check_percept();
	run_game();

}

/* Function: begin()
   Description: Begins the game from the previous point, runs if they want to play the same board
   Paramters: none
 */
void Game::begin() {
	set_init_position();
	print_cave();
	check_percept();
	run_game();
}

/* Function: run_game()
   Description: runs each turn until the user wins or loses
   Paramters: none
 */
void Game::run_game() {
	bool is_init_position;
	bool has_won;
	do {
		is_init_position = false;
		has_won = false;
		player_move();
		//cout << "X: " << x << endl;
		//cout << "Y: " << y << endl;
		if (x == init_x && y == init_y) {
			is_init_position = true;
		}
		if (is_init_position == true && has_gold == true) {
			has_won = true;
			cout << "You won the game!" << endl;
		}
	} while (has_won == false && has_died == false);
}

/* Function: init_board()
   Description: makes the vector, puts in each event, and sets the inital player position
   Paramters: none
 */
void Game::init_board() {
	cave.resize(cave_size, vector<Room>(cave_size));
	make_wumpus();
	make_gold();
	make_bats();
	make_pits();
	set_init_position();
}

/* Function: print_cave()
   Description: prints the cave based on whether they are in debug or not
   Paramters: none
 */
void Game::print_cave() {
	if (debug == 't' || debug == 'T') {
		print_cave_no_debug();
	}
	else if (debug == 'f' || debug == 'F'){
		print_cave_debug();
	}
}

/* Function: print_cave_no_debug()
   Description: prints the cave with debug moe off, shows all events
   Paramters: none
 */
void Game::print_cave_no_debug() {
	cout << "---------------------------------------------------------------------------------------" << endl; \
		for (int j = 0; j < cave_size; j++) {
			for (int i = 0; i < cave_size; i++) {
				cout << "+---";
			}
			cout << "+" << endl;
			for (int i = 0; i < cave_size; i++) {
				if (j == y && i == x) {
					cout << "| * ";
				}
				else if (cave[j][i].get_event_type() == 1) {
					cout << "| W ";
				}
				else if (cave[j][i].get_event_type() == 2) {
					cout << "| G ";
				}
				else if (cave[j][i].get_event_type() == 3) {
					cout << "| B ";
				}
				else if (cave[j][i].get_event_type() == 4) {
					cout << "| P ";
				}
				else {
					cout << "|   ";
				}
			}
			cout << "|" << endl;
		}
	for (int i = 0; i < cave_size; i++) {
		cout << "+---";
	}
	cout << "+" << endl;
}

/* Function: print_cave_debug()
   Description: only prints player position
   Paramters: none
 */
void Game::print_cave_debug() {
	cout << "---------------------------------------------------------------------------------------" << endl; \
		for (int j = 0; j < cave_size; j++) {
			for (int i = 0; i < cave_size; i++) {
				cout << "+---";
			}
			cout << "+" << endl;
			for (int i = 0; i < cave_size; i++) {
				if (j == y && i == x) {
					cout << "| * ";
				}
				else {
					cout << "|   ";
				}
			}
			cout << "|" << endl;
		}
	for (int i = 0; i < cave_size; i++) {
		cout << "+---";
	}
	cout << "+" << endl;
}

/* Function: get_rand_position()
   Description: gets a random x and y position until the space is no occupied
   Paramters: the address of the x and y variable to change
 */
void Game::get_rand_position(int& pos_x, int& pos_y) {
	do {
		pos_x = rand() % cave_size;
		pos_y = rand() % cave_size;
	} while (cave[pos_x][pos_y].get_event_type() != 0);

}

/* Function: set_init_position()
   Description: sets the initial player position
   Paramters: none
 */
void Game::set_init_position() {
	do {
		x = rand() % cave_size;
		y = rand() % cave_size;
	} while (cave[x][y].get_event_type() != 0);
	init_x = x;
	init_y = y;
}

/* Function: make_wumpus()
   Description: sets x and y position for a wumpus
   Paramters: none
 */
void Game::make_wumpus() {
	int x, y;
	get_rand_position(x, y);
	cave[x][y].set_wumpus();
}

/* Function:
   Description:
   Paramters:
 */
void Game::make_gold() {
	int x, y;
	get_rand_position(x, y);
	cave[x][y].set_gold();
}

/* Function:
   Description:
   Paramters:
 */
void Game::make_bats() {
	int x, y;
	for (int i = 0; i < 2; i++) {
		get_rand_position(x, y);
		cave[x][y].set_bats();
	}
}

/* Function:
   Description:
   Paramters:
 */
void Game::make_pits() {
	int x, y;
	for (int i = 0; i < 2; i++) {
		get_rand_position(x, y);
		cave[x][y].set_pits();
	}
}

/* Function: player_move()
   Description: lets the player move or shoot an arrow. Checks to make sure they are not moving out of the cave. After
				moving checks percepts and encounters.
   Paramters: none
 */
void Game::player_move() {
	string move;
	do {
		getline(cin, move);
	} while (move != "a" && move != "s" && move != "d" && move != "w" && move != " a" && move != " s" && move != " d" && move != " w");
	if (move == "a" && x != 0) {
		x--;
	}
	else if (move == "s" && y != cave_size - 1) {
		y++;
	}
	else if (move == "d" && x != cave_size - 1) {
		x++;
	}
	else if (move == "w" && y != 0) {
		y--;
	}
	else if (move == " a" || move == " s" || move == " d" || move == " w") {
		if (arrows_fired <= 3) {
			fire_arrow(move);
		}
	}
	print_cave();
	check_percept();
	check_encounter();
}

/* Function: fire_arrow()
   Description: fires an arrow in a direction. Goes 3 spaces unless it hits a wumpus or the edge of a cave. Does not detect 
				for some reason
   Paramters: direction of the arrow
 */
void Game::fire_arrow(string move) {
	if (move == " a") {
		for (int i = 1; i <= 3; i++) {
			cout << "x: " << x - i << "  y: " << y << endl;
			if (x - i >= 0) {
				if (cave[x - i][y].get_event_type() == 1) {
					cout << "hit wumpus" << endl;
					wumpus_killed = true;
					cave[x - i][y].set_event_type(0);
					break;
				}
			}
			else {
				break;
			}
		}
	}
	if (move == " d") {
		for (int i = 1; i <= 3; i++) {
			cout << "x: " << x + i << "  y: " << y << endl;
			if (x + i <= cave_size - 1) {
				if (cave[x + i][y].get_event_type() == 1) {
					cout << "hit wumpus" << endl;
					wumpus_killed = true;
					cave[x + i][y].set_event_type(0);
					break;
				}
			}
			else {
				break;
			}
		}
	}
	if (move == " w") {
		for (int i = 1; i <= 3; i++) {
			cout << "x: " << x << "  y: " << y - i << endl;
			if (y - i >= 0) {
				if (cave[x][y - i].get_event_type() == 1) {
					cout << "hit wumpus" << endl;
					wumpus_killed = true;
					cave[x][y - i].set_event_type(0);
					break;
				}
			}
			else {
				break;
			}
		}
	}
	if (move == " s") {
		for (int i = 1; i <= 3; i++) {
			cout << "x: " << x << "  y: " << y + i << endl;
			if (y + i <= cave_size - 1) {
				if (cave[x][y + i].get_event_type() == 1) {
					cout << "hit wumpus" << endl;
					wumpus_killed = true;
					cave[x][y + i].set_event_type(0);
					break;
				}
			}
			else {
				break;
			}
		}
	}
}

/* Function: check_percept()
   Description: checks each direction from the player unless out of the cave for a percept, and outputs the percept
				using polymorphism
   Paramters: none
 */
void Game::check_percept() {
	if (y - 1 >= 0) {
		if (cave[y - 1][x].get_event_type() != 0) {
			cave[y - 1][x].Rpercept();
		}
	}
	if (y + 1 <= cave_size - 1) {
		if (cave[y + 1][x].get_event_type() != 0) {
			cave[y + 1][x].Rpercept();
		}
	}
	if (x - 1 >= 0) {
		if (cave[y][x - 1].get_event_type() != 0) {
			cave[y][x - 1].Rpercept();
		}
	}
	if (x + 1 <= cave_size - 1) {
		if (cave[y][x + 1].get_event_type() != 0) {
			cave[y][x + 1].Rpercept();
		}
	}
}

/* Function: check_encounter()
   Description: checks the player position for an event. Does different actions depending on the event
   Paramters: none
 */
void Game::check_encounter() {
	if (cave[y][x].get_event_type() != 0) {
		cave[y][x].Rencounter();
		if (cave[y][x].get_event_type() == 1) {
			has_died = true;
		}
		else if (cave[y][x].get_event_type() == 2) {
			has_gold = true;
			cave[y][x].set_event_type(0);
		}
		else if (cave[y][x].get_event_type() == 3) {
			cave[y][x].set_event_type(0);
			x = rand() % cave_size;
			y = rand() % cave_size;
			print_cave();
			check_percept();
			check_encounter();
		}
		else if (cave[y][x].get_event_type() == 4) {
			has_died = true;
		}
	}
}
