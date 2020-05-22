#ifndef EVENT_H
#define EVENT_H

#include "prog.h"

class Event {
private:
public:
	virtual void percept() = 0;
	virtual void encounter() = 0;
};

#endif