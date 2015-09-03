#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define true 1 // define true so I could use it in while loop
#define false (!true) // define false so I could break the while loop

int main() {

	time_t now;
	time(&now);
	printf("Brandon Ginoza \nLab2\n%s\n",ctime(&now)); // prints out time name and lab
	char answer; // user input character y or n that answers if the user wants to play again
	int num; // int variable that holds random number
		while(true){ // while loop that runs each game
		
		srand(time(NULL));		
		num = (rand() % 100 + 1); // creates random number
		int counter = 0; // counts the number of guesses the user makes
		printf("Hello user! I'm thinking of a number between 1 and 100. See if you can guess it!\n");

		int response; // initialize int to hold user guess

			while(true){ // while loop to support guessing
	
			printf("Your guess: ");
			scanf("%d", &response); // scans in user guess
		
			counter++; // adds to the counter for every guess
				if (response < num){ // conditional if user guess is too low
					printf("Your guess was too low!\n");
				}
				else if (response > num){ // conditional if user guess is too high
					printf("Your guess was too high!\n");
				}
				else if (response == num){ // conditional when user gets it right
					printf("You got it in %d tries! My number was %d\n", counter, num);
					break; // breaks inner while loop
				}
			}

		printf("Would you like to play again (y/n)?"); // prompts user input
		scanf(" %c",&answer); // scans if user wants to play again
		
			if (answer == 'n'){ // if user doesn't want to play again
			break;	// breaks outer while loop terminating the program
			}
	}
return 0;
}

