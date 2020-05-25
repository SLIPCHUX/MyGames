#pragma once

#include "FBullCowGame.h"
#include <map>

#define TMap std::map	// UE4 style
using int32 = int;		//UE4 stule

FBullCowGame::FBullCowGame()
	: myMaxTry(8), myCurrentTry(1)
{

}

int32 FBullCowGame::GetMaxTries() const
{
	//return this->myMaxTry;
	TMap<int32, int32> WorldLengthToMaxTries{ {3, 5}, {4, 7}, {5, 10}, {6, 16}, {7, 20} };
	return WorldLengthToMaxTries[myHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{
	return myCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return myHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return this->bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FStrig Guess) const
{
	if (!IsIsogram(Guess)) // if the guess isn't an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) // if the guess isn't all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else
	{
		return EGuessStatus::OK; // TODO make actual error
	}
}

bool FBullCowGame::CheckCase(FStrig Word) const
{
	for (size_t i = 0; i < Word.length(); i++)
	{
		if (Word[i] > 'z' || Word[i] < 'a')
		{
			return true;
		}
	}
	return false;
}

void FBullCowGame::Reset()
{
	//constexpr int32 MAX_TRIES = 8;
	//this->myMaxTry = MAX_TRIES;

	const FStrig HIDDEN_WORD = "planet"; //MUST be an isogram
	myHiddenWord = HIDDEN_WORD;

	myCurrentTry = 1;
	
	bGameIsWon = false;

	return;
}

// recieve a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FStrig Guess)
{
	myCurrentTry++;
	
	FBullCowCount BullCowCount;
	size_t wordLength = myHiddenWord.length(); // assuming same length as guess
	// Loop through all letters in the hidden word

	for (size_t MHWChar = 0; MHWChar < wordLength; MHWChar++)
	{
		// compare letters against the hidden word
		for (size_t GChar = 0; GChar < wordLength; GChar++)
		{	
			// if they match then
			if (myHiddenWord[MHWChar] == Guess[GChar])
			{
				//if they're in the same place, increment bulls 
				if (MHWChar == GChar)
				{
					BullCowCount.Bulls++;
				}
				else //else increment cows
				{
					BullCowCount.Cows++;
				}
			}
		}

	}

	if (BullCowCount.Bulls == wordLength)
	{
		bGameIsWon = true;
	}
	else
	{
		bGameIsWon = false;
	}

	return BullCowCount;
}

FBullCowGame::~FBullCowGame()
{

}

bool FBullCowGame::IsIsogram(FStrig Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1)
	{
		return true;
	}

	TMap<char, bool> LetterSeen; // setup ur map
	for (auto Letter : Word)	// for all letteres of the word
	{
		Letter = tolower(Letter);	// handle mixed case
		if (LetterSeen[Letter])	// if the letter is in the map
		{
			return false;		// we don't have an isogram
		}
		else // otherwise
		{
			LetterSeen[Letter] = true;	// add the letter to the map as seen
		}
	}


	return true;	// for example in cases where /o is entered
}

bool FBullCowGame::IsLowerCase(FStrig Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))// if not a lowercase letter
		{
			return false;
		}
			
	}
	return true;
}
