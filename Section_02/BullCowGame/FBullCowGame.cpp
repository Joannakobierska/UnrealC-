#pragma once

#include "FBullCowGame.h"
#include <map>

#define TMap std::map // to make syntax Unreal friendly
using int32 = int;

FBullCowGame::FBullCowGame() {	Reset(); } // default constructor


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

int32 FBullCowGame::GetMaxTries() const 
{
	TMap <int32, int32> WordLenghtToMaxTries{ {3,4}, {4,7}, {5,10}, {6,16}, {7,20} };
	return WordLenghtToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{	
	const FString HIDDEN_WORD = "plane"; //this MUST be an isogram	
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram (Guess)) // if the guess isn't an isogram,
	{
		return EGuessStatus::Not_Isogram;
	} 
	else if (!IsLowercase(Guess)) // if the guess isn't all lowercase, 
	{
		return EGuessStatus::Not_Lowercase; // the guess isn't all lowercase
	}
	else if (Guess.length() != GetHiddenWordLenght()) //if guess lenght is wrong
	{
		return EGuessStatus::Wrong_Lenght;
	} 
	else 
	{
		return EGuessStatus::OK;
	}	
	
}

// recives a valid guess inrements trurn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	
	int32 WordLenght = MyHiddenWord.length(); // assuming same lenght as guess

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLenght; MHWChar++)
	{
		//compare letters against the guess
		for (int32 GChar = 0; GChar < WordLenght; GChar++) 
		{

		
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar])
			{
				// increment bulls if they are in the same place 
				if (MHWChar == GChar) 
				{
					BullCowCount.Bulls++; // increment bulls
				}
				else
				{
					 BullCowCount.Cows++; //must ber a cow					
				}	
			}
		}
	}


	if (BullCowCount.Bulls == WordLenght) 
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	// treat 0 and 1 letter words as isograms 
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;//setup our map
	for(auto Letter : Word) //for all letters of the word
	{ 
		Letter = tolower(Letter); //handle mixed case
		if (LetterSeen[Letter]) 
		{//if the letter is in the map
			return false; //we do NOT have an isogram
		}
		else
		{
			LetterSeen[Letter] = true; 	//add the letter to the map as seen
		}				
	}
	return true; // for example in cases where /0 is entered
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)  
	{
	if (!islower(Letter)) // if not a lowercase letter
		return false;
	}
	return true;
}
