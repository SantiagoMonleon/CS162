#include "room.h"

/* Function: Room()
   Description: initializes event type for each room and sets the event pointer to null
   Paramters: none
 */
Room::Room() {
	event_type = 0;
	e = NULL;
}

/* Function: ~Room()
   Description: deletes the event pointer
   Paramters: none
 */
Room::~Room() {
	delete e;
}

/* Function: Rpercept()
   Description: calls the percept function for the event for polymorphism
   Paramters:
 */
void Room::Rpercept() {
	e->percept();
}

/* Function: Rencounter()
   Description: calls the encounter function for the event for polymorphism
   Paramters:
 */
void Room::Rencounter() {
	e->encounter();
}

/* Function: set_event_type()
   Description: sets the event type for a room to a specific event. If that event is 0 then returns the pointer to NULL
   Paramters: event type to change to
 */
void Room::set_event_type(int ev) {
	event_type = ev;
	if (ev == 0) {
		e = NULL;
	}
}

/* Function: get_event_type
   Description: returns the event type for a room
   Paramters: none
 */
int Room::get_event_type() {
	return event_type;
}

/* Function: set_Wumpus()
   Description: makes a new wumpus pointer and sets it to the event pointer, then changes the event type
   Paramters:
 */
void Room::set_wumpus() {
	e = new Wumpus;
	event_type = 1;
}

/* Function:
   Description:
   Paramters:
 */
void Room::set_gold() {
	e = new Gold;
	event_type = 2;
}

/* Function:
   Description:
   Paramters:
 */
void Room::set_bats() {
	e = new Bats;
	event_type = 3;
}

/* Function:
   Description:
   Paramters:
 */
void Room::set_pits() {
	e = new Pit;
	event_type = 4;
}

