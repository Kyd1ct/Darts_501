#include "Player.h"

Player::Player() {

}

Player::~Player() {

}


// Throw bullseye function
int Player::throwBull()
{
	int r = rand() % 100;

	if (r < (bullRate - 20))
		hit = 50;
	else if (r < 85)
		hit = 25;
	else
		hit = 1 + rand() % 20;

	Player::checkScore();
	return currentScore;
}

// Throw treble function
int Player::throwTreble(int d) {
	int r = rand() % 100;

	if (r < bullRate)
		hit = 3 * d;
	else if (r < 90)
		hit = d;
	else if (r < 93)
		hit = 3 * bd[0][d];
	else if (r < 96)
		hit = 3 * bd[1][d];
	else if (r < 98)
		hit = bd[0][d];
	else
		hit = bd[1][d];

	Player::checkScore();
	return currentScore;
}

// Throw double function
int Player::throwDouble(int d) {
	int r = rand() % 100;

	if (r < 80)
		hit = 2 * d;
	else if (r < 85)
		hit = 0;
	else if (r < 90)
		hit = d;
	else if (r < 93)
		hit = 2 * bd[0][d];
	else if (r < 96)
		hit = 2 * bd[1][d];
	else if (r < 98)
		hit = bd[0][d];
	else
		hit = bd[1][d];

	Player::checkScore();
	return currentScore;
}

// Throw single function
int Player::throwSingle(int d) {
	int r = rand() % 100;

	if (d == 25) {		// outer  80%
		if (r < 80)
			hit = 25;
		else if (r < 90)
			hit = 50;
		else
			hit = 1 + rand() % 20;
	}
	else			// 1 to 20 single
		if (r < 88)
			hit = d;
		else if (r < 92)
			hit = bd[0][d];
		else if (r < 96)
			hit = bd[1][d];
		else if (r < 98)
			hit = 3 * d;
		else
			hit = 2 * d;

	Player::checkScore();
	return currentScore;
}


// Function changing current score to new score
int Player::checkScore() {

	currentScore = Player::nScore();

	return currentScore;
}	


// Function resetting score to the starting score
int Player::resetScore() {
	currentScore = startScore;
	return currentScore;
}

// Function following the old score from previous turn
int Player::oScore() {
	oldScore = currentScore;
	return oldScore;
}

// Function following new score
int Player::nScore() {
	newScore = currentScore - hit;
	return newScore;
}

// Function incrementing wonSet variable
int Player::winSet() {
	wonSet++;
	return wonSet;
}

// Function resetting the won sets
int Player::resetSet() {
	wonSet = 0;
	return wonSet;
}

// Getters
int Player::getSet() {
	return wonSet;
}


string Player::getName() {
	return name;
}

int Player::getBullRate() {
	return bullRate;
}

int Player::getCurrentScore() {
	return currentScore;
}

// Setters
void Player::setCurrentScore(int p) {
	currentScore = p;
}

void Player::setName(string n) {
	name = n;
}

void Player::setBullRate(int b) {
	bullRate = b;
}
