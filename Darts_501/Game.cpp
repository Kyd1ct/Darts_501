#include "Game.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;



Game::Game() {

}

Game::~Game() {

}

void Game::gameFreq() {
	// Used to calculate the frequency

	int i, j;
	cout << "S - J" << endl;
	// Calculates frequency for Sid
	for (i = 0; i < 7; i++) {

		cout << i << " : 7  -->  " << ((float)arrP1[i] / (float)getNumGames()) * 100.000f << "%" << endl;
	}

	cout << endl;
	// Calculates frequency for Joe	
	for (j = 6; j >= 0; j--) {

		cout << "7 : " << j << "  -->  " << ((float)arrP2[j] / (float)getNumGames()) * 100.000f << "%" << endl;
	}

	
}

// Function to clear the frequency array in case the user would like to test the frequencies again
void Game::clearArray() {
	int i, j;
	for (i = 0; i < 7; i++) {
		arrP1[i] = 0;
	}

	for (j = 0; j < 7; j++) {
		arrP2[j] = 0;
	}
}


// Adds 1 to the array depending on how many sets the player has won after when losing a game
int Game::lostGameSid(int s) {
	arrP1[s] += 1;
	return arrP1[s];
}

int Game::lostGameJoe(int s) {
	arrP2[s] += 1;
	return arrP2[s];
}

// Throwing function for player 1 (Sid in this case)
void Game::player1Throw() {
	// Variable to keep the old score in case of discarding
	int p1RoundScore = p1.oScore();

	// Loop for the throws per turn
	for (int j = 0; j < 3; j++) {

		// If score is over 51 then aim for bullseye
		if (p1.getCurrentScore() > 51) {
			p1.throwBull();
		}

		// If score is 51 then aim for single 1
		else if (p1.getCurrentScore() == 51) {
			p1.throwSingle(1);
		}

		// If score is 50 then aim for bullseye
		else if (p1.getCurrentScore() == 50) {
			p1.throwBull();
		}

		// If score is equal or less than 40 and over 0 (to prevent from throwing after the score is negative) and is dividable by 2, throw double based on score divided by 2
		else if (p1.getCurrentScore() <= 40 && p1.getCurrentScore() > 0 && p1.getCurrentScore() % 2 == 0) {
			p1.throwDouble(p1.getCurrentScore() / 2);
		}

		// If score is dividable by 3 and is over 70, aim treble based on score divided by 3
		else if (p1.getCurrentScore() % 3 == 0 && p1.getCurrentScore() > 70) {
			p1.throwTreble(p1.getCurrentScore() / 3);
		}

		// If score is equal to or over 41 and equal to or under 49 then aim single based on current score minus 40
		else if (p1.getCurrentScore() >= 41 && p1.getCurrentScore() <= 49) {
			p1.throwSingle(p1.getCurrentScore() - 40);
		}

		
		// If score is less than 41 and is not dividable by 2 then throw single based on current score divided by 2 with remainder 1		
		else if (p1.getCurrentScore() < 41) {
			p1.throwSingle(p1.getCurrentScore() % 2 == 1);
		}
		
		// If score is 0
		if (p1.getCurrentScore() == 0) {
			// Throw counter changed to stop the for loop
			j = 10;
			// Increment wonSet variable for the frequencies
			p1.winSet();
			// playerTurn boolean changed to false (flag used to make the players alternate turns)
			playerTurn = false;
			// Reset scores
			p1.resetScore();
			p2.resetScore();
			// set boolean changed to false to stop set loop
			set = false;

			// If wonSet variable is 7
			if (p1.getSet() == 7) {
				// match and playerTurn boolean changed to false (stop match loop and alternate players) 
				match = false;
				playerTurn = false;
				// wonSet is the cell in the array and the function adds 1 to that cell
				lostGameJoe(p2.getSet());
				// Reset wonSet count
				p1.resetSet();
				p2.resetSet();
			}
		}

		// If score is negative or 1
		if (p1.getCurrentScore() < 0 || p1.getCurrentScore() == 1) {
			// Rest player's score to the score from the last turn, stop the loop and change playerTurn to false so they can alternate
			p1.setCurrentScore(p1RoundScore);
			j = 10;
			playerTurn = false;
		}

		// Might be inefficient but I had a bug when the players didn't switch after the loop was stopped before all three throws
		if (j == 0 || j == 1 || j == 2) {
			playerTurn = false;
		}

	}

}


// Comments from above are the same for this function
void Game::player2Throw() {
	int p2RoundScore = p2.oScore();
	for (int k = 0; k < 3; k++) {
		if (p2.getCurrentScore() > 51) {
			p2.throwBull();
		}

		else if (p2.getCurrentScore() == 51) {
			p2.throwSingle(1);
		}

		else if (p2.getCurrentScore() == 50) {
			p2.throwBull();
		}


		else if (p2.getCurrentScore() <= 40 && p2.getCurrentScore() > 0 && p2.getCurrentScore() % 2 == 0) {
			p2.throwDouble(p2.getCurrentScore() / 2);
		}

		else if (p2.getCurrentScore() % 3 == 0 && p2.getCurrentScore() > 70) {
			p2.throwTreble(p2.getCurrentScore() / 3);
		}

		else if (p2.getCurrentScore() >= 41 && p2.getCurrentScore() <= 49) {
			p2.throwSingle(p2.getCurrentScore() - 40);
		}


		else if (p2.getCurrentScore() < 41) {
			p2.throwSingle(p2.getCurrentScore() % 2 == 1);
		}


		if (p2.getCurrentScore() == 0) {
			k = 10;
			p2.winSet();
			playerTurn = true;
			p1.resetScore();
			p2.resetScore();
			set = false;
			if (p2.getSet() == 7) {
				match = false;
				playerTurn = true;
				lostGameSid(p1.getSet());
				p1.resetSet();
				p2.resetSet();
			}
		}

		if (p2.getCurrentScore() < 0 || p2.getCurrentScore() == 1) {
			p2.setCurrentScore(p2RoundScore);
			k = 10;
			playerTurn = true;
		}

		if (k == 0 || k == 1 || k == 2) {
			playerTurn = true;
		}
	}
}


// Set function
void Game::gameSet() {

	// Sets the set boolean to true after each set has finished
	set = true;
	

	// Loop continues while set boolean is true
	while (set) {

		// If playerTurn is true, Sid throws
		if (playerTurn) {

			player1Throw();
		}
		
		// If playerTurn is false and set is still true, Joe throws
		if (!playerTurn) {
			if (set) {

				player2Throw();
			}
		}
			
	}
}


// Function for match loop
void Game::gameMatch() {

	// While game boolea is true, set do set function
	while (game) {

		gameSet();

		// If match booleais false, stop game loop
		if (match == false) {
			game = false;
		}
	}

	// Reset player scores for the new game
	p1.resetScore();
	p2.resetScore();
}


// App function
void Game::gameRun() {

	// Set player names and success rates
	p1.setName("Sid");
	p2.setName("Joe");
	p1.setBullRate(71);
	p2.setBullRate(73);

	// While appRun is true
	while (appRun) {
		// Clear frequencies array
		clearArray();
		// Input number of games
		cout << "Please type in the number of games: ";
		cin >> numGames;

		// For loop for number of games
		for (int i = 1; i <= numGames; i++) {
			
			// Set game and match to true and start game 1
			gameMatch();
			game = true;
			match = true;
		}

		// Show set frequencies
		cout << endl;
		cout << endl;
		cout << "Game frequency: " << endl;
		gameFreq();
	}
}

int Game::getNumGames() {
	return numGames;
}