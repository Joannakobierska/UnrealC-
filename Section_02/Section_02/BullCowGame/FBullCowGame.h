#pragma once
#include <string>


class FBullCowGame {
public:
	void Reset(); // TODO make more rich return value.
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); // TODO make more rich return value.



	// Please try and ignore this and focus on the interface above 
private:
	int MyCurrentTry;
	int MyMaxTries;
	bool IsIsogram(std::string);
};