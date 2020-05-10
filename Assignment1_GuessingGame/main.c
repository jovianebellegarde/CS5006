// Add your program here!
//
//
#include <stdio.h>
#include <stdlib.h>

/*
 * Have a generateRandomNumber function that generates a random integer that
 * the user will guess for the duration of the game.
 */
int generateRandomNumber() {
	int randomNumber = rand() % 10 + 1;
	return randomNumber;
}

/*
 * The playRound function allows for each iteration of the array to signify one
 * round of the guessing game.
 */
int playRound() {
	int userNumber = 0;
	int numberOfGuesses = 1;

	// Generate a random number from 1 - 10
	int randomNumber = generateRandomNumber();

	// While loops plays one round until the user guesses the correct number
	while (1) {
		printf("\nGuess a number from 1 to 10: ");
		scanf("%d", &userNumber);

		if (userNumber < randomNumber) {
			printf("\n Your number %d is too low. Try again.\n", 
				userNumber);

		} else if (userNumber > randomNumber) {
			printf("\nYour number %d is too high. Try again.\n",
				userNumber);

		} else {
			printf("\nYour number %d is the right guess!\n", 
			userNumber);
			
			return numberOfGuesses;
		}
		
		numberOfGuesses++;
	}
}

/*
 * The main function allows for each round to be represented by each iteration
 * of the gameScores array. Each iteration represents 1 game. The playRound
 * function is called here. The results from that function are then returned
 * back to the main, where the number of guesses for each round is printed.
 */
int main() {
	int games = 5;
	int gameScores[] = {0, 0, 0, 0, 0};
	int i;

	// Looping through to play a single round per iteration of gameScores
	for (i = 0; i < games; i++) {
		gameScores[i] = playRound();
	}

	// Looping though to print out number of guesses for each round
	for (i = 0; i < games; i++){
	printf("Guess %d: Took %d guesses.\n", i + 1, gameScores[i]);
	}
	
	return 0;
}
