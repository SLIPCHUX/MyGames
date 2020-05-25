/* 
This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC patter, and is responsible for all
user interation. For game logic see the FBullCowGame class.
*/
#pragma  once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; // UE4 style
using int32 = int;		   // UE4 style

FBullCowGame BCGame;  // Intantiate a new game, wich we re-use across plays

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGameSummary();
bool AskToPlayAgain();

// Entry point of application
int main()
{

	PrintIntro();
	do 
	{
		PlayGame();

	} while (AskToPlayAgain());

	return 0; // Exit the application
}

void PrintIntro()
{
	const int32 WORLD_LENGHT = BCGame.GetHiddenWordLength();
	std::cout << "Welcome to Bulls and Cows, a fun word game. \n";
	std::cout << "Can you guess the " << WORLD_LENGHT;
	std::cout << " letter isogram I'm thinking of?\n\n";
}

// plays a single game to completion
void PlayGame()
{
	BCGame.Reset();
	const size_t maxTries = BCGame.GetMaxTries();

	// loop asking for guesses while
	// the game is NOT wom, and there are still remaining tries
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= maxTries)
	{
		FText guess = GetValidGuess();

		// submit valid guess to the game
		FBullCowCount bullCowCount = BCGame.SubmitValidGuess(guess);


		std::cout << "Bulls = " << bullCowCount.Bulls;
		std::cout << ". Cows = " << bullCowCount.Cows << "\n\n";

		
	}

	PrintGameSummary();
	// TODO summarise game
	return;
}

// Loop continually untill the user gives a valid guess
FText GetValidGuess() // TODO change to GetValid
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do 
	{
		int32 currentTry = BCGame.GetCurrentTry();
		std::cout << "Try #" << currentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";

		getline(std::cin, Guess);
		//std::cout << "Your guess was: " << Guess << "\n\n";

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a work without repeating letters.\n";
			break;
		case EGuessStatus::Wrong_Lenght:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;	
		default:

			break;
		}
	} while (Status != EGuessStatus::OK); // keep looping until we get errors

	return Guess;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "YOU WIN! Nice work! :)\n";
	}
	else
	{
		std::cout << "You lose... Better luck next time! :(\n";
	}
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)\n";
	FText response = "";
	getline(std::cin, response);

	return((response[0] == 'y') || (response[0] == 'Y'));
}

