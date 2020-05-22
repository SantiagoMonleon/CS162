#ifndef ROOM_H
#define ROOM_H
#include "prog.h"
#include "event.h"
#include "wumpus.h"
#include "gold.h"
#include "bats.h"
#include "pit.h"

class Room {
private:
	Event* e;
	int event_type;
public:
	Room();
	~Room();

	void set_event_type(int);
	int get_event_type();

	void set_wumpus();
	void set_gold();
	void set_bats();
	void set_pits();

	void Rpercept();
	void Rencounter();
};

#endif
