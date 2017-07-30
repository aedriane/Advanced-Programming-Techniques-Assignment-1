#include "helpers.h"

/*  
 *  COSC1076 - Advanced Programming Techniques
 *  Assignment 1
 *   Full Name:        Aedriane Hernan
 *   Student Number:   s34541804
 *   Course Code:      COSC1076
 *   Program code:     BP162
*/ 

void readRestOfLine()
{
    int ch;
    while(ch = getc(stdin), ch != EOF && ch != '\n')
    { 

    } /* Gobble each character. */

    /* Reset the error status of the stream. */
    clearerr(stdin);
}

/* This function gets the user input and converts it to an integer. 
    Uses: Loading the board number, initialising the player position... */
int get_Int(char *input)
{
   char *end;
   int input_num = -1;

   input_num = (int) strtol(input, &end, 0);

   if (*end || input_num < 0)
   {
      return -1;
   }
   else
   {
      return input_num;
   }
}

/* Gets user input. If input is NULL then it will return FALSE.
    It also checks for buffer overflow and calls readRestOfLine() if so.
    Else if all is well, will return TRUE */
Boolean get_Input(char input[INPUT])
{
   if (input == NULL || fgets(input, INPUT, stdin) == NULL)
   {
      printf("\n");
      return FALSE;
   }
   
   if (input[strlen(input) - 1] != '\n')
   {
      /* buffer overflow */
      printf("Input limit reached: %d.\n", INPUT - 1);
      readRestOfLine();
      return FALSE;
   }

   else
   {
      /* remove newline */
      input[strlen(input) - 1] = '\0';
   }

   return TRUE;
}
