#include "game.h"

/*  
 *  COSC1076 - Advanced Programming Techniques
 *  Assignment 1
 *   Full Name:        Aedriane Hernan
 *   Student Number:   s34541804
 *   Course Code:      COSC1076
 *   Program code:     BP162
*/ 

void menuAfterMain()
{
  char enter = '\0';

    /* Initialisation menu. */
  printf("You can use the following commands to play the game:\n\n");
  printf("load <g>\n");
  printf("   g: number of the game board to load\n");
  printf("init <x>, <y>, <direction>\n");
  printf("   x: horizontal position of the car on the board (between 0 & 9)\n");
  printf("   y: vertical position of the car on the board (between 0 & 9)\n");
  printf("   direction: direction of the car's movement (north, east, south, or west)\n");
  printf("forward (or f)\n");
  printf("turn_left (or l)\n");
  printf("turn_right (or r)\n");
  printf("quit\n\n");

  printf("Press enter to continue...");

  /* If enter is not equal to the carriage return character and the new userInput character,
      run the while loop to getChar() the enter variable. */
  while(enter != '\r' && enter != '\n')
  {
    enter = getchar();
  }
  printf("\n");
}

void playGame()
{
  /* Variable Declarations. */
  Cell board[BOARD_HEIGHT][BOARD_WIDTH];
  char userInput[INPUT];
  char *tok;
  Boolean load = TRUE;
  Boolean playerLoop = TRUE;
  int yValue, xValue, boardNo;

  menuAfterMain();

  /* Initialise main while loop. */
  while(load)
  {
    /* Initialise board, and display empty board with no player. */
    initialiseBoard(board);
    displayBoard(board, NULL);

    printf("At this stage of the program, only two commands are acceptable:\n");
    printf("load<g>\n");
    printf("quit\n\n");

    printf("Input: ");

      /* if Input defies get_Input (helpers.c) function, print invalid */
    if(!get_Input(userInput))
    {
      printf("Invalid!\n\n");
    }
    printf("\n");

    /* Tokenization of string input */
    tok = strtok(userInput, DELIMS);

    if(tok == NULL)
    {
      printf("Invalid!\n\n");
      continue;
    }

    if(strcmp(tok, COMMAND_LOAD) == 0)
    {
      tok = strtok(NULL, DELIMS);

      if(tok == NULL)
      {
        printf("Invalid!\n\n");
        continue;
      }

      /* Convert the token from string to an integer, using the get_Int method
          (helpers.c) so it could be passed into what board to load. */
      boardNo = get_Int(tok);

      /* If the converted integer is not equal to either 1 or 2, print Invalid. */
      if(boardNo != 1 || boardNo != 2)
      {
        printf("Invalid!\n\n");
      }
    }

    else if(strcmp(tok, COMMAND_QUIT) == 0)
    {
       load = FALSE;
    }

    else
    {
      printf("Invalid!\n\n");
    }

    /* Determine the board to load. */
    while(boardNo == 1 || boardNo == 2)
    {
      if(boardNo == 1)
      {
        loadBoard(board, BOARD_1);
        displayBoard(board, NULL);
      }

      else if(boardNo == 2)
      {
        loadBoard(board, BOARD_2);
        displayBoard(board, NULL);
      }

      else
      {
        printf("Invalid\n");
      }

      printf("At this stage of the program, only three commands are acceptable:\n");  
      printf("load <g>\n");      
      printf("init <x>,<y>,<direction>\n");
      printf("quit\n");

      printf("Input: ");

      if(!get_Input(userInput))
      {
        printf("Invalid!\n\n");
      }
      printf("\n");

      tok = strtok(userInput, DELIMS);

      if(tok == NULL)
      {
        printf("Invalid!\n\n");
        continue;
      }    

      /* If the first string is equal to "init", proceed further */
      if(strcmp(tok, COMMAND_INIT) == 0)
      {
        /* Tokensises second string of user input after "init", which would
            be an integer between 0 and 9. */
        tok = strtok(NULL, DELIMS);

        if(tok == NULL)
        {
          printf("Invalid!\n\n");
          continue;
        }

        /* Convert the token from string to an integer, so it could be passed into 
          the player's position of x on the board. */
        xValue = get_Int(tok);

        /* If the xValue is greater than 0 or less than BOARD_WIDTH which is
            10, then continue. */
        if(xValue > 0 || xValue < BOARD_WIDTH)
        {
          /* Tokensises second string of user input after "xValue", which would
            be an integer between 0 and 9. */      
          tok = strtok(NULL, DELIMS);

          if (tok == NULL)
          {
            printf("Invalid!\n\n");
            continue;
          }

          /* Convert the token from string to an integer, so it could be passed into 
          the player's position of y on the board. */
          yValue = get_Int(tok);

          /* If the xValue is greater than 0 or less than BOARD_HEIGHT which is
            10, then continue. */
          if(yValue > 0 || yValue < BOARD_HEIGHT)
          {
            /* Tokensises third string of user input after "yValue", this would be a string
                for user's direction on the board. Will be handled with strcmp() */            
            tok = strtok(NULL, DELIMS);

            if(tok == NULL)
            {
              printf("Invalid!\n\n");
              continue;
            }

            /* if statement to determine if the direction token would be equal to any of the directions. */
            if((strcmp(tok, DIRECTION_NORTH) == 0) || 
              (strcmp(tok, DIRECTION_SOUTH) == 0) || 
              (strcmp(tok, DIRECTION_EAST) ==0) || 
              (strcmp(tok, DIRECTION_WEST) ==0))
            {
              /* Initialise the Player. */
              Player p1;

              /* Initialise the Position. */
              Position pos;

              /* Add both x and y values from user input into Position struct. */
              pos.x = xValue;
              pos.y = yValue;

              /* Check for validation to continue. This if statement checks if the placePlayer()
                  function returns TRUE. It will only return true if the player is placed inside
                  the board, or if the player is not initiialised onto a BLOCKED cell. These are 
                  FALSE returns. */
              if(placePlayer(board, pos) == TRUE)
              {
                /* Initialise player to appropriate direction. Place the player on the board and 
                  display. */
                if(strcmp(tok, DIRECTION_NORTH) == 0)
                {
                  initialisePlayer(&p1, &pos, NORTH);               
                }

                else if(strcmp(tok, DIRECTION_SOUTH) == 0)
                {
                  initialisePlayer(&p1, &pos, SOUTH);               
                } 


                else if(strcmp(tok, DIRECTION_EAST) == 0)
                {
                  initialisePlayer(&p1, &pos, EAST);               
                }   

                else if(strcmp(tok, DIRECTION_WEST) == 0)
                {
                  initialisePlayer(&p1, &pos, WEST);               
                }                

                printf("You have placed your player on x = %d, y = %d\n\n", xValue, yValue);
                placePlayer(board, pos);
                displayBoard(board, &p1);


                /* At this point is where the game actually starts. Which is Requirement 5 onwards. */
                while(playerLoop)
                {
                  printf("At this stage of the program, only four commands are acceptable\n");
                  printf("forward (or f)\n");
                  printf("turn_left (or l)\n");
                  printf("turn_right (or r)\n");
                  printf("quit\n");

                  printf("Input: ");

                  if(!get_Input(userInput))
                  {
                    printf("Invalid!\n\n");
                  }
                  printf("\n");                            

                  /* If statement to determine if player turned left. */
                  if((strcmp(userInput, COMMAND_TURN_LEFT) == 0) || 
                    (strcmp(userInput, COMMAND_TURN_LEFT_SHORTCUT) == 0))
                  {
                    printf("Player has turned left!\n\n");
                    turnDirection(&p1, TURN_LEFT);
                    displayBoard(board, &p1);               
                  }

                  /* If statement to determine if player turned right. */
                  else if((strcmp(userInput, COMMAND_TURN_RIGHT) == 0) || 
                    (strcmp(userInput, COMMAND_TURN_RIGHT_SHORTCUT) == 0))
                  {
                    printf("Player has turned right!\n\n");
                    turnDirection(&p1, TURN_RIGHT);
                    displayBoard(board, &p1); 
                  }

                  /* If statement to determine if player had moved forward. */
                  else if((strcmp(userInput, COMMAND_FORWARD) == 0) || 
                    (strcmp(userInput, COMMAND_FORWARD_SHORTCUT) == 0))
                  {
                    /* Print message if player had moved forward. Displays board with player moved in the corrent position and direction. */
                    if(movePlayerForward(board, &p1) == PLAYER_MOVED)
                    {
                    	printf("Player Moved!\n\n");                 
                    	displayBoard(board, &p1);                   
                    }

                    /* Print message if player tries to initiate a move to an outside bounds ie. x = 10, y = 9. */
                    else if(movePlayerForward(board, &p1) == OUTSIDE_BOUNDS)
                    {
                    	printf("Out of bounds!\n\n");
                    	displayBoard(board, &p1);
                    }

                    /* Print message if player tries to initiate a move to a blocked cell. */
                    else if(movePlayerForward(board, &p1) == CELL_BLOCKED)
                    {
                    	printf("Cell is blocked!\n\n");
                    	displayBoard(board, &p1);
                    }
                  }

                  /* Ends both load and player loop and sets boardNo to
                      something other than board 1 or 2. When player quits,
                      it will display the amounts of successful forward
                      moves the player has made. */
                  else if(strcmp(userInput, COMMAND_QUIT) == 0)
                  {
                    printf("Total player moves: %d\n\n", p1.moves);                  
                    boardNo = -1;
                    load = FALSE;
                    playerLoop = FALSE;
                  }

                  else
                  {
                    printf("Invalid!\n\n");
                    displayBoard(board, &p1); 
                  }
                }
              } 
            }

            else
            {
              printf("Invalid!\n\n");
            }                               
          }
        }
      }

      else if(strcmp(tok, COMMAND_QUIT) == 0)
      {
        /* Sets board number to something other than 1 or 2 and sets load 
            boolean to false to end the loop */        
        boardNo = -1;
        load = FALSE;
      }
          
      /* this if statement is if the user wants to load either BOARD_1 or BOARD_2
        from the initialise player menu. */
      else if(strcmp(tok, COMMAND_LOAD) == 0)
      {
        /* Tokensises second string of user input after "load", which would
            be an integer of either 1 or 2. */     
        tok = strtok(NULL, DELIMS);

        /* If token is equal to nothing, print Invalid */
        if(tok == NULL)
        {
          printf("Invalid!\n\n");
          continue;
        }

        /* Convert the token from string to an integer, so it could be passed 
            into what board to load. */
        boardNo = get_Int(tok);           
      }

      else
      {
        printf("Invalid!\n\n");

      }
    }
  }
}
