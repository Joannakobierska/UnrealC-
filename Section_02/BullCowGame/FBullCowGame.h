#pragma once
#include <string>


class FBullCowGame {
public:
	
	FBullCowGame(); // constructor
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make more rich return value.
	bool CheckGuessValidity(std::string); // TODO make more rich return value.
	// provide a method for counting bulls and cows and increasing turn #

	// Please try and ignore this and focus on the interface above 
private:

	// see constructor for initialization
	int MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram(std::string);
};