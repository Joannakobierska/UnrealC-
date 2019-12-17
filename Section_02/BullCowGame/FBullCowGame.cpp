#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() {	Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLenght() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;	
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;	
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK; // TODO make actual error
}

// recives a valid guess inrements trurn and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	//setup a return value 
	FBullCowCount BullCowCount;

	// loop through all letters in the guess
	int32 HiddenWordLenght = MyHiddenWord.length(); 
	for (int32 MHWChar = 0; MHWChar < HiddenWordLenght; MHWChar++)
	{


		//compare letters against the hidden word
		for (int32 GChar = 0; GChar < HiddenWordLenght; GChar++) 
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




	return BullCowCount;
}
