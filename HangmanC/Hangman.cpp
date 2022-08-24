#include "Hangman.h"

void Hangman::run()
{
	displayProlog();
	vRunProgram = confirAction("Are you ready to play?");

	while (vRunProgram)
	{
		initGameVariables();

		while (vRunGameLogic)
		{
			clearScreen();
			displayMaskedWord();
			playerGuess();
			checkGameState();
		}

		playAgain();
	}

	displayEndProgram();
}


void Hangman::playAgain()
{
	bool pPlayAgain = confirAction("Do you want to play again?");

	if (!pPlayAgain)
		vRunProgram = false;
}

void Hangman::checkGameState()
{
	if (gMaskedWord == gWordToGuess)
	{
		playerState(true);
	}
	else if (gGuessesMade >= gGuessesAllowed)
	{
		playerState(false);
	}
}

void Hangman::playerGuess()
{
	char guess;
	bool valid = false;

	std::cout << "Guess letter:" << std::endl;
	do
	{
		std::cin >> guess;
		if (std::count(gLettersGuessed.begin(), gLettersGuessed.end(), guess))
		{
			std::cout << "You already guessed this letter. Try again." << std::endl;
		}
		else
		{
			gLettersGuessed.push_back(guess);
			revealCorrectLetters(guess);
			valid = true;
			gGuessesMade++;
		}

	} while (!valid);
}

void Hangman::revealCorrectLetters(const char pLetter)
{
	for (size_t i = 0; i < gMaskedWord.size(); i++)
	{
		if (gWordToGuess[i] == pLetter)
		{
			gMaskedWord[i] = pLetter;
		}
	}
}

void Hangman::displayMaskedWord() const
{
	std::cout << gMaskedWord << std::endl;
	std::cout << "You have left " << (gGuessesAllowed - gGuessesMade) << " guesses, be vise about them!" << std::endl;
	std::cout << "Already gueesed: ";
	for (char letter : gLettersGuessed)
	{
		std::cout << letter << " ";
	}
	std::cout << std::endl;
}

void Hangman::initGameVariables()
{
	std::srand(std::time(0));
	int randWordIndex = std::rand() % gWordDict.size();
	std::cout << randWordIndex << std::endl;

	gLettersGuessed.clear();

	gWordToGuess = gWordDict[randWordIndex];
	gMaskedWord.assign(gWordToGuess.size(), '-');

	gGuessesAllowed = setAllowedGuesses();
	gGuessesMade = 0;

	vRunGameLogic = true;
}

int Hangman::setAllowedGuesses() const
{
	std::vector<char> temp;
	for (size_t i = 0; i < gWordToGuess.size(); i++)
	{
		if (!std::count(temp.begin(), temp.end(), gWordToGuess[i]))
		{
			temp.push_back(gWordToGuess[i]);
		}
	}

	return temp.size() + 2;
}

void Hangman::displayProlog() const
{
	std::cout << "Welcom to Hangman! Prepare to spend some time on guessing secret words!" << std::endl;
	std::cout << "Brace your self and good luck in the game!! \nDon't leave hanging there!\n" << std::endl;
	std::cout << std::endl;
}

void Hangman::displayEndProgram() const
{
	std::cout << "Thank you for playing. See you next time!" << std::endl;
}

void Hangman::playerState(bool pWon)
{
	vRunGameLogic = false;
	clearScreen();

	if (pWon)
	{
		std::cout << "CONGRATULATIONS !!!! YOU WON!!!" << std::endl;
		std::cout << "Secret word was - " << gWordToGuess << std::endl;
		std::cout << "You managed to guess this word only in " << gGuessesMade << " guesses!" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "HAHAHA you FAILED!!" << std::endl;
		std::cout << "Secret word was - " << gWordToGuess << std::endl;
		std::cout << "You managed to get " << gMaskedWord << std::endl;
		std::cout << "Better luck next time..." << std::endl;
		std::cout << std::endl;
	}
}

bool Hangman::confirAction(const std::string& pQuestion) const
{
	char pUserAction;

	do
	{
		std::cout << pQuestion << " (y/n)" << std::endl;
		std::cin >> pUserAction;

		pUserAction = std::tolower(pUserAction);

	} while (pUserAction != 'y' && pUserAction != 'n');

	return pUserAction == 'y' ? true : false;
}

void inline Hangman::clearScreen() const
{
	system("CLS");
}