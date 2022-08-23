#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

bool confirAction(const std::string &pQuestion);
void displayProlog();
void initGameVariables();
void displayMaskedWord();
void revealCorrectLetters(const char pLetter);
void playerGuess();
void checkGameState();
void playerWin();
void playerLose();
void clearScreen();

const std::vector<std::string> gWordDict = { "hangman", "orange", "battleship", "congratulation", "imagination", "advertisement"};
std::vector<char> gLettersGuessed;
std::string gWordToGuess;
std::string gMaskedWord;
bool vRunGameLogic = false;
int gGuessesMade = 0;
int gGuessesAllowed = 9;

int main()
{
	displayProlog();
	vRunGameLogic = confirAction("Are you ready to play?");

	initGameVariables();

	while (vRunGameLogic)
	{
		clearScreen();
		displayMaskedWord();
		playerGuess();
		checkGameState();
	}

	return 0;
}

void checkGameState()
{
	if (gMaskedWord == gWordToGuess)
	{
		playerWin();
	}
	else if (gGuessesMade >= gGuessesAllowed)
	{
		playerLose();
	}
}

void playerGuess()
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

void revealCorrectLetters(const char pLetter)
{
	for (int i = 0; i < gMaskedWord.length(); i++)
	{
		if (gWordToGuess[i] == pLetter)
		{
			gMaskedWord[i] = pLetter;
		}
	}
}

void displayMaskedWord()
{
	std::cout << gMaskedWord << std::endl;
	std::cout << "You have left " << gGuessesAllowed - gGuessesMade << " guesses, be vise about them!" << std::endl;
	for (char letter : gLettersGuessed)
	{
		std::cout << letter << " ";
	}
	std::cout << std::endl;
}

void initGameVariables()
{
	std::srand(std::time(0));
	int randWordIndex = std::rand() % gWordDict.size() + 1;

	gWordToGuess = gWordDict[randWordIndex];
	gMaskedWord.assign(gWordToGuess.size(), '-');
	
	gGuessesAllowed = gWordToGuess.size() + 2;
}

void displayProlog()
{
	std::cout << "Welcom to Hangman! Prepare to spend some time on guessing secret words!" << std::endl;
	std::cout << "Brace your self and good luck in the game!! Don't leave hanging there!\n" << std::endl;
}

void playerWin()
{
	vRunGameLogic = false;
	clearScreen();
	std::cout << "CONGRATULATION !!!! You WON!!!" << std::endl;
	std::cout << "Secret word was - " << gWordToGuess << std::endl;
	std::cout << "You managed to guess this word only in " << gGuessesMade << std::endl;
}

void playerLose()
{
	vRunGameLogic = false;
	clearScreen();
	std::cout << "HAHAHA you FAILED!!" << std::endl;
	std::cout << "Secret word was - " << gWordToGuess << std::endl;
	std::cout << "You managed to get " << gMaskedWord << std::endl;
	std::cout << "Better luck next time..." << std::endl;
}

bool confirAction(const std::string &pQuestion)
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

void clearScreen()
{
	system("CLS");
}