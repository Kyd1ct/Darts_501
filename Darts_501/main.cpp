#include <iostream>
#include <string>
// Include game header
#include "Game.h"
using namespace std;


// Main game loop
int main() {

	// Game object
	Game g1;
	//Sets time to 0 to get different scores based on time
	srand(time(0));

	// Function that runs the game
	g1.gameRun();
}