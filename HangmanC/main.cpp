#include "Hangman.h"

int main()
{
	Hangman game;
	game.run();

	game.~Hangman();

	return 0;
}