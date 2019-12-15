#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instaniate a new game

// the entry point of our aplication
int main()
{
	std::cout << BCGame.GetCurrentTry();
	bool bPlayAgain = false;
	do
	{	
	PrintIntro();
	PlayGame();
	bPlayAgain = AskToPlayAgain();
	} 
	while (bPlayAgain);
	return 0; // exit aplication

}

// introduce the game
void PrintIntro()
{
		constexpr int WORD_LENGHT = 5;
	std::cout << "Welcome to Bulls nad Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();
	std::cout << MaxTries << std::endl; 

	//	loop for the number of turns asking for guesses
	// TODO change FOR to WHILE loop onece we have validating tries
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess(); // TODO make loop checking valid guesses


		// Submit valid guess to the game
		// Print nuber of bulls and cows
		std::cout << "Your guess was:" << Guess << std::endl;
		std::cout << std::endl;
	}
}
		// TODO summarise game

std::string GetGuess() 
{
	int CurrentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess:" ;
	std::string Guess = " ";	
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want play again (y/n)?";
		std::string Response = "";
		std::getline(std::cin, Response);
		return (Response[0] == 'y') || (Response[0] == 'Y');
		std::cout << std::endl;

	return false;
}
