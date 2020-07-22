#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player
{
	public:
		// Constructor and destructor
		Player();
		~Player();
		// Throwing functions
		int throwBull();
		int throwTreble(int d);
		int throwDouble(int d);
		int throwSingle(int d);
		int checkScore();
		int resetScore();
		int oScore();
		int nScore();
		int winSet();
		int resetSet();
		// Getters
		int getSet();
		string getName();
		int getBullRate();
		int getCurrentScore();
		// Setters
		void setCurrentScore(int p);
		void setName(string n);
		void setBullRate(int b);


	private:
		// Variables for name, success rate, hit, won sets, score
		string name;
		int bullRate;
		int hit = 0;
		int wonSet = 0;
		int startScore = 501;
		int currentScore = 501;
		int newScore = 0;
		int oldScore = 0;
		// Array to simulate darts board
		int bd[2][21] = { {0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5},
						  {0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1} };
};

