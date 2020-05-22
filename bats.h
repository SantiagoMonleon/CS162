#ifndef BATS_H
#define BATS_H
#include "event.h"

class Bats : public Event {
public:
	void percept();
	void encounter();
};

#endif