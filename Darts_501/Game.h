#pragma once
// Include player header
#include "Player.h"

class Game:
	public Player
{

	public:
		// Constructor and destructor
		Game();
		~Game();
		// Frequency related functions
		void gameFreq();
		void clearArray();
		int lostGameSid(int s);
		int lostGameJoe(int s);
		// Game functions
		void gameSet();
		void gameMatch();
		void gameRun();
		void player1Throw();
		void player2Throw();
		// Getter
		int getNumGames();

	private:
		// Booleans for loops
		bool set = true;
		bool playerTurn = true;
		bool match = true;
		bool game = true;
		bool appRun = true;
		// Variables to follow total games and integer arrays for the frequencies
		int numGames;
		int arrP1[7] = { 0, 0, 0, 0, 0, 0, 0 };
		int arrP2[7] = { 0, 0, 0, 0, 0, 0, 0 };
		// Player objects
		Player p1;
		Player p2;
};

