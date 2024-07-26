#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
// These are the standard libraries that are required to make the program function.

// Function 1 that I have created to be called from Main.
int corLocNum(int LENGTHOFCODE, int GuessNumber, int GeneratedNumber[7]) // A function with the integers for the different parts of the program.
{																		// States that the array value is set to [7].
	int b = LENGTHOFCODE - 1, v[7], corlocnum = 0;
	for (int k = 0; k < LENGTHOFCODE; k++)
    {
		v[k] = GuessNumber % 10;
		GuessNumber /= 10;
		for (int i = 0; i < LENGTHOFCODE; i++)
        {
			if (i == b && v[k] == GeneratedNumber[i])
            {
				corlocnum++;
				break;
			}
		}
		b--;
	}
	return corlocnum;
}
// Function 2 that I have created to be called from Main.
int corNum(int LENGTHOFCODE, int GuessNumber, int GeneratedNumber[7]) // Another function with the integers for the different parts of the program.
{
	int b = LENGTHOFCODE - 1, v[7], cornum = 0;
	for (int k = 0; k < LENGTHOFCODE; k++)
    {
		if (k != 0)
			b--;
		v[k] = GuessNumber % 10;
		GuessNumber /= 10;
		for (int i = 0; i < LENGTHOFCODE; i++)
        {
			int p;
			
			if (v[k] == GeneratedNumber[i])
            {
				cornum++;
				
				break;
			}
		}
	}
	return cornum;
}
// Function 3 that I have created to be called from Main.
void randomNumber(int LENGTHOFCODE, int GeneratedNumber[7]) // Another function with the integers for the different parts of the program.
{
	int cornum = 0, corlocnum = 0; // Generates unique random number.
	for (int i = 0; i <= (LENGTHOFCODE - 1); i++) // Generates unique random number.
    {
		GeneratedNumber[i] = 1 + rand() % 9; // Generates unique random number.
		if (i != 0) // Generates unique random number.
        {
			for (int k = 0; k < i; k++) // Generates unique random number.
			{
				while (GeneratedNumber[k] == GeneratedNumber[i]) // Generates unique random number.
					GeneratedNumber[i] = 1 + rand() % 9; // Generates unique random number.
			}
			while (GeneratedNumber[LENGTHOFCODE - 1] == GeneratedNumber[i] && i != LENGTHOFCODE - 1) // Generates unique random number.
				GeneratedNumber[LENGTHOFCODE - 1] = 1 + rand() % 9; // Generates unique random number.
		}
	}
}
int main() // Main function.
{
	int  exit = 1, LENGTHOFCODE, n;
	bool Play = true;
	while (Play)
    {
        printf("Welcome to Mastermind\n"); // Greeting Message.
        printf("Created by: Ryan Rostampour\n"); // Creator Name.

		printf("Enter the amount of digits:\n"); // Tells a message to the player asking to input amount of guesses.
		scanf("%d", &LENGTHOFCODE); // Scans the input of the player.
		printf("Enter the amount of tries you would like:\n"); // Tells a message to the player asking to input the amount of tries.
		scanf("%d", &n); // Scans the input of the player.
		int GeneratedNumber[7], GuessNumber, cornum, corlocnum;
		while (LENGTHOFCODE > 7 || LENGTHOFCODE < 1) // States that the number of digits for the random generated number can be between 1 - 7, if more, it prints the message below.
		{
			printf("Please enter a size between 1 and 7:\n"); // Tells a message to the player to input a size they like.
			scanf("%d", &LENGTHOFCODE); // Scans the input of the player.
		}
		while (n > 100 || n < 1) // Gives the option of having between 1 - 100 guesses for guessing the random generated number.
        {
			printf("Please enter the amount of tries you would like between 1 and 100:\n"); // Tells a message to the player to input the amount of tries.
			scanf("%d", &n); // Scans the input of the player.
		}
		int Try = 1;
		srand(time(NULL));
		randomNumber(LENGTHOFCODE, GeneratedNumber); // Random generated number based of digit size and size.
													// This shows that the funtion is being called into the main (Function 3).
		int x = 1;
		for (Try; Try <= n; Try++)
        {
			int b = LENGTHOFCODE - 1;
			cornum = 0;
			corlocnum = 0;
			printf("Try #: %d\n", Try); // Tells the player which try # they are on.
			printf("Enter your Guess:"); // Tells a message to the player to input their guess.
			scanf("%d", &GuessNumber); // Scans the players input.

			if (GuessNumber == 0)
            {
				break;
			}
			if (Play == false)
				break;
			corlocnum += corLocNum(LENGTHOFCODE, GuessNumber, GeneratedNumber); // This shows that the function is being called into the main (Function 1).
			cornum += corNum(LENGTHOFCODE, GuessNumber, GeneratedNumber); // This shows that the next function is being caleld into the main. (Function 2).
			printf("Correct number: %d\t  Correct number and place: %d\n", cornum, corlocnum); // Tells the player what they got right, right location and number or just right number.
            // Prints how many numbers are correct and how many are correct and in the correct location.
			if (corlocnum == LENGTHOFCODE) // States that if the user guess is correct with the generated code then the game prints the message below.
            {
				printf("You Have Won!\n"); // Tells a message to the player saying they have won.
				break;
			}
		}
		if (Try > n) // States that if the user does not guess the code in the given guesses(n), the game prints the message below.
        {
			printf("You lose\n"); // Tells a message to the player saying they have won the game.
            printf("The guess was:\n"); // Tells the player what the random generated number was.
            for (int i = 0; i < LENGTHOFCODE; i++)
            printf("%d", GeneratedNumber[i]); // Prints the random generated guess.
		}

        printf("\nWould you like to play again?\n"); // Asks the player if they would like to play again.
        printf("[1] = Yes, [0] = No:"); // Asks player to input a number. [1] = Yes, [0] = No.
		scanf("%d", &exit); // Scans the players input.
		if (exit == 0)
			Play = false; // Game does not start again if player inputs 0.
		else
			Play = true; // Game restarts in player inputs 1.
	}
}
