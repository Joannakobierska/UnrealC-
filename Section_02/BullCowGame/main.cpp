#include <iostream>
#include <string>

using namespace std;

int main()
{
	// introduce the gamr
	constexpr int WORD_LENGHT = 5;
	cout << "Welcome to Bulls nad Cows, a fun word game. \n";
	cout << "Can you guess the " << WORD_LENGHT;
	cout << " letter isogram I'm thinking of?\n";
	cout << endl;

	// get a guess from the player
	cout << "Enter your guess:";
	string Guess = "";
	getline(cin, Guess);
	// repeat the guess back to them
	cout << "Your guess was:" << Guess << endl; 

	// get a guess from the player
	cout << "Enter your guess:";	
	getline(cin, Guess);
	// repeat the guess back to them
	cout << "Your guess was:" << Guess << endl;

	cout << endl;
	return 0;

}