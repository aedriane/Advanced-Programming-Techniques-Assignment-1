#ifndef CARBOARD_H
#define CARBOARD_H

/*  
 *  COSC1076 - Advanced Programming Techniques
 *  Assignment 1
 *   Full Name:        Aedriane Hernan
 *   Student Number:   s34541804
 *   Course Code:      COSC1076
 *   Program code:     BP162
*/ 

#include "helpers.h"
#include "game.h"

#define STUDENT_NAME "Aedriane Hernan"
#define STUDENT_ID "s3541804"
#define STUDENT_EMAIL "s3541804@student.rmit.edu.au"

/* I had created an enum array to encapsulate each individual CHOICE to a 
	number. */
enum carboardMenu
{
	CHOICE_GAME = 1,
	CHOICE_STUDENT = 2,
	CHOICE_QUIT = 3
};

/* Declaration of function in .h */
enum carboardMenu printMenu(void);

/**
 * Main menu option 2 - show your student information as per the specification.
 *
 * You should change the defines above related to student information and use
 * them when printing.
 */
void showStudentInformation();

#endif
