/*
 * chips.cpp
 *
 *  Created on: Aug 22, 2021
 *      Author: TannerDolby
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

// Game of Chips type i/o game
// Reference: Erin Colvin of the LinkedIn 'Learning C++' course.

// struct to represent 3 data points each instance of `player`
// will have in the player list
struct player
{
	string name;
	int movesToWin;
	int numWins;
};

// function prototypes
bool playAnother(char);
void getUserNames(player[]);
string findPlayerName(player[], bool);
int askMove(bool, int, player[]);
void addWin(player[], bool);
void setMoveCount(player[], bool, int);
int findPlayerMoveCount(player[], bool);

float MAX_TURN = .5;

int main() {
	bool playerOneTurn = true;
	bool gameOver = false;

	string winner = "";
	player Players[2];
	char playAgain;

	int maxChips = 0;
	int chipsToTake = 0;
	int moveCount = 0;
	int startPile = 0;

	// output file vars, use ios::app (ios::append) param to append instead of overwriting if already exists
	ofstream outStream;
	outStream.open("game-history.txt", ios::app);

	// sample of chips-log.txt after two games played
	// Erin won in 7 turns.
	// Tanner won in 6 turns.

	// seed the random number generator
	srand(time(0));

	// prompt players for their usernames
	// and update playerNames within the function
	// as arrays are pass by reference
	getUserNames(Players);


	do {

		// Prompt max chips in the pile (or random by user choice)
		cout << "Enter a maximum number of chips for the pile. Enter -1 for random." << endl;
		cin >> maxChips;

		// Check if user wants random number of chips in pile
		if (maxChips == -1) {
			maxChips = (rand() % 100) + 1;
		}

		startPile = maxChips;

		cout << "This round starts with " << maxChips << " chips in the pile." << endl;
		gameOver = false;
		// reset the move counter
		moveCount = 0;

		while (gameOver == false) {
			chipsToTake = askMove(playerOneTurn, maxChips, Players);
			maxChips = maxChips - chipsToTake;

			cout << "Chips left in the pile: " << maxChips << endl;
			// switch from player one turn to player twos turn
			playerOneTurn = !playerOneTurn;
			// increment global scope var moveCount
			moveCount++;

			if (maxChips == 0) {
				gameOver = true;
				cout << findPlayerName(Players, playerOneTurn) << ", congrats you won!" << endl;
				// set movesToWin data point in struct
				setMoveCount(Players, playerOneTurn, moveCount);
				// log the winners moves to our output stream (output file)
				outStream << findPlayerName(Players, playerOneTurn) << " won in " << findPlayerMoveCount(Players, playerOneTurn);
				outStream << " turns with " << startPile << " chips in the pile to start" << endl;
				// increment number of wins for winning player
				addWin(Players, playerOneTurn);
			}
		}

		cout << "Do you want to play again? (Y/N)" << endl;
		cin >> playAgain;
		playAgain = toupper(playAgain);
	}	while (playAgain == 'Y');

	return 0;
}

string findPlayerName(player Players[], bool playerTurn) {
	if (playerTurn) {
		return Players[0].name;
	} else {
		return Players[1].name;
	}
}

int findPlayerMoveCount(player Players[], bool playerTurn)
{
	if (playerTurn)
	{
		return Players[0].movesToWin;
	}
	else
	{
		return Players[1].movesToWin;
	}
}

int askMove(bool player1Turn, int chipsInPile, player Players[]) {
	int chipsTaken;
	int maxPerTurn = MAX_TURN * chipsInPile;

	do {
		cout << findPlayerName(Players, player1Turn) << ": How many chips would you like?" << endl;
		cout << "You can take up to ";

		if (maxPerTurn == 0) {
			cout << "1" << endl;
		} else {
			cout << maxPerTurn << endl;
		}

		if (findPlayerName(Players, player1Turn) == "AI") {
			if (maxPerTurn == 0) {
				chipsTaken = 1;
			} else {
				chipsTaken = (rand() % maxPerTurn) + 1;
			}
		} else {
			cin >> chipsTaken;
		}
	} while ((chipsTaken > maxPerTurn) && (chipsInPile > 1));

	return chipsTaken;
}

// we know passing arrays are "pass-by-reference"
// so we can pass the playerNames array and anything
// changes inside the function will be changed inside
// main and throughout
void getUserNames(player Players[]) {

	// Prompt player names
	cout << "Enter name for Player One: " << endl;
	cin >> Players[0].name;
	cout << "Enter name for Player Two: (If you wish to play against the computer, enter 'AI')" << endl;
	cin >> Players[1].name;

	// Greet players
	cout << "Player 1: " << Players[0].name << endl;
	cout << "Player 2: " << Players[1].name << endl;
	cout << "Goodluck!" << endl;
	// initiaze number of wins to zero
	Players[0].numWins = 0;
	Players[1].numWins = 0;
}

// function to increment the number of wins
void addWin(player Players[], bool playerOneTurn)
{
	if (playerOneTurn)
	{
		Players[0].numWins++;
	}
	else
	{
		Players[1].numWins++;
	}
}

void setMoveCount(player Players[], bool playerOneTurn, int moveCount)
{
	if (playerOneTurn) {
		Players[0].movesToWin = moveCount;
	} else {
		Players[1].movesToWin = moveCount;
	}
}

// Without using toupper from <cstring>
bool playAnother(char s) {
	bool choice = false;
	if (s == 'y' || s == 'Y') {
		choice = true;
	}
	return choice;
}
