#ifndef PIT_H
#define PIT_H
#include "event.h"

class Pit : public Event {
private:
	int test;
public:
	void percept();
	void encounter();

};

#endif