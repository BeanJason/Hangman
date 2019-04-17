// Homework05_Hangman.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "string"

using namespace std;


int main()
{
	string word;
	string blank;
	int wordGuessesLeft = 5;
	int letterGuessesLeft = 5;
	string wordG;
	string letterG;
	int wordLength;
	bool game = true;
	bool validInput = false;
	bool guessWAgain = true;
	bool guessLAgain = true;
	int turn = 1;



	cout << "Insert a word for player two to guess: ";
	cin >> word;
	wordLength = word.length();



	for (int i = wordLength; i > 0; i--) {
		blank += "-";
	}



	while (!validInput) {



		while (guessLAgain) {

			cout << blank;
			cout << endl;
			cout << "You have " << letterGuessesLeft << " guesses left guess a letter: ";
			cin >> letterG;

			if (letterG.length() > 1) {
				cout << "You did not guess a letter!   Try again: ";
				cin >> letterG;
			}
			if (letterG.length() == 1) {
				letterGuessesLeft = letterGuessesLeft - 1;

				for (int i = wordLength - 1; i >= 0; i--) {

					if (word.at(i) == letterG.at(0)) {
						cout << "you guessed the letter at position " << i << "correct" << endl;
						blank.at(i) = letterG.at(0);

					}
				}
				cout << blank << endl;
				guessLAgain = false;
				guessWAgain = true;
			}



			while (guessWAgain) {

				cout << "you have " << wordGuessesLeft << " guesses left try guessing a word" << endl;
				cin >> wordG;

				if (wordG == word) {
					cout << "you win you guessed the word in " << turn << " guesses" << endl;
					validInput = true;
					guessLAgain = false;
					guessWAgain = false;
				}
				else if (wordG != word) {
					wordGuessesLeft = wordGuessesLeft - 1;
					turn = turn + 1;
					guessLAgain = true;
					guessWAgain = false;

					if (wordGuessesLeft <= 0) {
						cout << "you ran out of guesses you lose :(";
						guessLAgain = false;
						guessWAgain = false;
						validInput = true;
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}


