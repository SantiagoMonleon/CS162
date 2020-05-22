#ifndef GAME_H
#define GAME_H
#include "prog.h"
#include "room.h"

class Game {
private:
	char debug;
	int cave_size;
	bool has_gold;
	bool wumpus_killed;
	bool has_died;
	bool same_board;
	int arrows_fired;

	int x, y, init_x, init_y;

	vector<vector<Room>> cave;

public:
	Game();
	void start(int, char);
	void begin();
	void init_board();
	void make_board();
	void print_cave();
	void print_cave_debug();
	void print_cave_no_debug();

	void run_game();

	void set_position(int, int);

	void set_init_position();

	void get_rand_position(int&, int&);

	void make_wumpus();
	void make_gold();
	void make_bats();
	void make_pits();

	void player_move();
	void fire_arrow(string);

	void check_percept();
	void check_encounter();
};

#endif