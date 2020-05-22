#include "event.h"

class Wumpus : public Event {
private:
	int test;
public:
	void percept();
	void encounter();
};