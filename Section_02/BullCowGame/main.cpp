/* This is the console executable, that mekes use of the BullCow class
This scts as the view in MVC pattern, and is responsible for all user interaction. For game logic see FBullCowGame class. 

*/
#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

//to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

//function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // instaniate a new game, which we re-use across plays

// the entry point of our aplication
int main()
{
	
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

void PrintIntro()
{
		
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;

	std::cout << "\n Can you guess the " << BCGame.GetHiddenWordLenght() ;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}
//plays a single game to complition
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();


	//	loop asking for guesses	until the game is NOT won
	// is NOT won and there are still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)	
	{
		FText Guess = GetValidGuess(); 
	
		// Sumit valid guess to the game, and recive counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
	
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}

	PrintGameSummary();	
	return;
}
		


// loop continually until user gives a valid guess
FText GetValidGuess()
{
	FText Guess = " ";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
	// get a guess from the player
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
	std::cout << ". Enter your guess: " ;
	
	std::getline(std::cin, Guess);

	Status = BCGame.CheckGuessValidity(Guess);
	switch (Status)
	{
	case EGuessStatus::Wrong_Lenght:
		std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letter word.\n\n";
		break;
	case EGuessStatus::Not_Isogram:
		std::cout << "Please enter a word without repeating letters.\n\n";
		break;
	case EGuessStatus::Not_Lowercase:
		std::cout << "Please enter all lowercase letters. \n\n";
		break;
	default:
		// assume the guess is valid
		break; 

	}	
	} while (Status != EGuessStatus::OK); // keep looping until we got no errors
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
void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!\n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}
