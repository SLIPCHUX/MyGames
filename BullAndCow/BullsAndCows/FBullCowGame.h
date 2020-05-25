/* The game logic (no view code or direct user interaction)
The gam is a simple guess the word based on Mastermind
*/

#pragma once
#include <string>

using FStrig = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FStrig) const; 
	bool CheckCase(FStrig) const;

	void Reset();
	
	FBullCowCount SubmitValidGuess(FStrig); // counts bulls & cows, and increases try # assuming valid guess

	~FBullCowGame(); // Destructor


private:
	// see the constructor of initialising
	int32 myCurrentTry;
	int32 myMaxTry;
	FStrig myHiddenWord;
	bool bGameIsWon;

	bool IsIsogram(FStrig) const;

	bool IsLowerCase(FStrig) const;
};