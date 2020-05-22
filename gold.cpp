#include "gold.h"
#include "game.h"

void Gold::percept() {
	cout << "You see a glimmer nearby" << endl;
}

void Gold::encounter() {
	cout << "You picked up the gold!" << endl;
}