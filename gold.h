#ifndef GOLD_H
#define GOLD_H
#include "event.h"

class Gold : public Event {
public:
	void percept();
	void encounter();
};

#endif