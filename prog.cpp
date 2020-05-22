#include "prog.h"

/* Function: play_again()
   Description: asks the user if they want to play again. Error handles the interger they input and returns it. 
   Paramters: none
 */
int play_again() {
	string userInput;
	int input;
	do {
		cout << "Would you like to play again:" << endl << "   [1] Play again with same board." << endl;
		cout << "   [2] Play again with different board." << endl << "   [3] Exit game." << endl << "Selection: ";
		cin >> userInput;
		if (userInput != "1" && userInput != "2" && userInput != "3") {
			cout << "[ERROR] --> Enter either [1], [2], or [3]." << endl;
		}
	}while (userInput != "1" && userInput != "2" && userInput != "3");
	input = atoi(userInput.c_str());
	return input;
}
