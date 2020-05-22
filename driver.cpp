/* Program: kill the wumpus game
   Author: Santiago Monleon
   Date: 5/29/2019
   Description: Kill the wumpus game. User plays as a player in a cave, whose goal is to find the goal and return to their
				original position. There are several different events in the game: bats, pits, a wumpus, and gold. Encountering
				these events do different things to the player. Moving next to one of the events gives a percept to the player that
				indicate they have moved next to it. The player can fire an arrow to try to kill the wumpus. The user passes in the size
				of the cave, and whether they want to play on debug mode as command line arguments. 
   Inputs: The player movement each turn, firing an arrow, and whether they want to play again. 
   Outputs: The cave and the percepts. 
*/


#include "prog.h"
#include "game.h"

/* Function: main()
   Description: error handles the command line argument for the number of arguments and size of the cave. Then starts the game.
			After the game ends asks if they want to play again and restarts the game based on whether they want to keep
			the same board or not
   Paramters: command line arguments
 */
int main(int argc, char* argv[]) {
	srand(time(NULL));
	if (argc != 3) {
		cout << "You did not enter the correct number of parameters." << endl;
		exit(0);
	}
	if (*argv[1] < 3) {
		cout << "Enter a cave size greater than or equal to 4." << endl;
		exit(0);
	}
	int size = atoi(argv[1]);
	char debug = *argv[2];
	Game g;
	g.start(size, debug);
	int play_ag;
	do {
		play_ag = play_again();
		if (play_ag == 1) {
			g.begin();
		}
		else if (play_ag == 2) {
			Game g;
			g.start(size, debug);
		}
	} while (play_ag != 3);

}
