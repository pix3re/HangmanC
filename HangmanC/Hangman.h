#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

class Hangman
{
public:
	Hangman() = default;
	~Hangman() = default;

	void run();

private:
	bool confirAction(const std::string& pQuestion) const;
	void displayProlog() const;
	void initGameVariables();
	void displayMaskedWord() const;
	int setAllowedGuesses() const;
	void revealCorrectLetters(const char pLetter);
	void playerGuess();
	void checkGameState();
	void playAgain();
	void playerState(bool pWon);
	void displayEndProgram() const;
	void inline clearScreen() const;

	const std::vector<std::string> gWordDict = { "hangman", "orange", "battleship", "congratulation", "imagination", "advertisement" };
	std::vector<char> gLettersGuessed;
	std::string gWordToGuess;
	std::string gMaskedWord;
	bool vRunGameLogic = false;
	bool vRunProgram = false;
	int gGuessesMade = 0;
	int gGuessesAllowed = 0;

};

