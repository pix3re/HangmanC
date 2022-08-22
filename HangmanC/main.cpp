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
void playerGuess();

const std::vector<std::string> gWordDict = { "hangman", "orange", "battleship", "congratulation", "imagination", "advertisement"};
std::vector<char> gLettersGuessed;
std::string gWordToGuess;
std::string gMaskedWord;
bool vGameLoop = false;

int main()
{
	displayProlog();
	vGameLoop = confirAction("Are you ready to play?");

	while (vGameLoop)
	{
		initGameVariables();
		displayMaskedWord();
		playerGuess();
	}

	return 0;
}

void playerGuess()
{
	char guess;
	std::cout << "Guess letter:" << std::endl;
	//do
	//{
	//	std::cin >> guess;
	//	if (std::count(gLettersGuessed.begin(), gLettersGuessed.end(), guess))
	//	{
	//		std::cout << "You already guessed this letter. Try again." << std::endl;
	//	}
	//	else
	//	{
	//		gLettersGuessed.push_back(guess);
	//	}
	//	
	//}
}

void displayMaskedWord()
{
	std::cout << gMaskedWord << std::endl;
}

void initGameVariables()
{
	std::srand(std::time(0));
	int randWordIndex = std::rand() % gWordDict.size() + 1;

	gWordToGuess = gWordDict[randWordIndex];
	gMaskedWord.assign(gWordToGuess.size(), '-');
}

void displayProlog()
{
	std::cout << "Welcom to Hangman! Prepare to spend some time on guessing secret words!" << std::endl;
	std::cout << "Several rules before playing:" << std::endl;
	std::cout << "* You have only 7 guesses" << std::endl;
	std::cout << "* Only one guess per letter is allowed" << std::endl;
	std::cout << std::endl;
	std::cout << "Brace your self and good luck in the game!! Don't leave hanging there!\n" << std::endl;
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