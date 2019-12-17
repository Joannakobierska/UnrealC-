/* This is the console executable, that mekes use of the BullCow class
This scts as the view in MVC pattern, and is responsible for all user interaction. For game logic see FBullCowGame class. 

*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
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
		
	std::cout << "Welcome to Bulls nad Cows, a fun word game. \n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() ;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	

	//	loop for the number of turns asking for guesses
	// TODO change FOR to WHILE loop onece we have validating tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid guesses


		// Sumit valid guess to the game, and recive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// Print nuber of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
	
		std::cout << std::endl;
	}
}
		// TODO summarise game

FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	// get a guess from the player
	std::cout << "Try " << CurrentTry << ". Enter your guess: " ;
	FText Guess = " ";	
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want play again (y/n)?";
		FText Response = "";
		std::getline(std::cin, Response);
		return (Response[0] == 'y') || (Response[0] == 'Y');
		std::cout << std::endl;

	return false;
}
