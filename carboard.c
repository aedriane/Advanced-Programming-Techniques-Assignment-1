#include "carboard.h"

/*  
 *  COSC1076 - Advanced Programming Techniques
 *  Assignment 1
 *   Full Name:        Aedriane Hernan
 *   Student Number:   s34541804
 *   Course Code:      COSC1076
 *   Program code:     BP162
*/ 

int main(int argc, char *argv[])
{
	/* Initialise the choices */
	enum carboardMenu choice = 0;

	while(choice != CHOICE_QUIT)
	{
		/* Prints the main menu of carboard */
		choice = printMenu();

		switch(choice)
		{
			/* playGame() will be called which starts the game loop. */
			case CHOICE_GAME:
				playGame();
				break;
			/* showStudentInformation() will be called and will show the
			students information that was inputted into the function. */
			case CHOICE_STUDENT:
				showStudentInformation();
				break;

			/* Quits the main menu without any errors. */	
			case CHOICE_QUIT:
				printf("Game has ended.\n");
				exit(0);

			/* If player enters something silly.*/
			default:
				break;
		}
	}

	return EXIT_SUCCESS;
}

enum carboardMenu printMenu(void)
{
	/* Variable declarations. */
	Boolean end = FALSE;
	char userInput[INPUT] = {'\0'};
	enum carboardMenu carboardChoices;

	while(!end)
	{
		/* Simple menu print. */
		printf("Welcome to Car Board\n");
		printf("--------------------\n");
		printf("1. Play Game\n");
		printf("2. Show Student's Information\n");
		printf("3. Quit\n\n");

		printf("Please enter your choice: ");

		/* If the input of the user defies the function 'get_Input', quit 
			the game. */
		if(!get_Input(userInput))
		{
			return CHOICE_QUIT;
		}

		printf("\n");

		/* Converts string to an integer by the use of get_Int function. */
		carboardChoices = get_Int(userInput);

		/* If user enters 1, 2, or 3, the while loop will end and the appropriate
			case will be dealt with. */
		if(carboardChoices == CHOICE_GAME || carboardChoices == CHOICE_STUDENT
			|| carboardChoices == CHOICE_QUIT)
		{
			end = TRUE;
		}

		else
		{
			printf("Invalid\n\n");
		}
	}

	return carboardChoices;
}


void showStudentInformation()
{
	printf("----------------------------------\n");
	printf("Name: %s\n", STUDENT_NAME);
	printf("No: %s\n", STUDENT_ID);
	printf("Email: %s\n", STUDENT_EMAIL);
	printf("----------------------------------\n");
	printf("\n");
}
