#include "board.h"

/*  
 *  COSC1076 - Advanced Programming Techniques
 *  Assignment 1
 *   Full Name:        Aedriane Hernan
 *   Student Number:   s34541804
 *   Course Code:      COSC1076
 *   Program code:     BP162
*/ 

Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

/* This function initialises the board and sets all cells to EMPTY */
void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    int row;
    int column;

    for(column= 0; column < BOARD_HEIGHT; ++column)
    {
        for(row = 0; row < BOARD_WIDTH; ++row)
        {
            board[column][row] = EMPTY;
        }
    }
  
}

/* This function is called when a user wants to load a specific board
    if the boardToLoad is equal to either BOARD_1 or BOARD_2, load the 
    desired board */
void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
    int column;
    int row;

    for(column= 0; column < BOARD_HEIGHT; ++column)
    {
        for(row = 0; row < BOARD_WIDTH; ++row)
        {
            if(boardToLoad[column][row] == BOARD_1[column][row])
            {
                board[column][row] = BOARD_1[column][row];
            }

             if(boardToLoad[column][row] == BOARD_2[column][row])
            {
                board[column][row] = BOARD_2[column][row];
            }       
        }
    }
}


/* This function places the player in the desired cell, if it is EMPTY.
    If the cell is either blocked or out of bounds, it will print a message
    detailing to the user that the instantiation of the player position is not
    possible */
Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
	int row;
	int column;

	row = position.x;
	column = position.y;

    if(board[column][row] == BLOCKED)
    {
        printf("Cell Blocked!\n\n");
        return FALSE;
    }

    if((column < 0 || column > BOARD_HEIGHT) || (row < 0 || row > BOARD_WIDTH))
    {
        printf("Player out of bounds!\n\n");
        return FALSE;        
    }

    if(board[column][row] == EMPTY)
    {
        board[column][row] = PLAYER;
        return TRUE;
    }

    else
    {
        return FALSE;
    }
}

PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{
    int row;
    int column;
    
    Position position;

    position = getNextForwardPosition(player);

    row = position.x;
    column = position.y;

    if (board[column][row] == BLOCKED)
    {
        return CELL_BLOCKED;
    }

    if ((column < 0 || column >= BOARD_HEIGHT) || (row < 0 || row >= BOARD_WIDTH))
    {
        return OUTSIDE_BOUNDS;
    }

    else
    {

    	board[player -> position.y][player -> position.x] = EMPTY;

    	board[column][row] = PLAYER;

    	updatePosition(player, position);

    	return PLAYER_MOVED;
    }
}

/* This function displays the board, board to load and the player's position.
    It will print in a way if the cell is EMPTY is will print an EMPTY_OUTPUT, 
    else if the cell is BLOCKED it will print a BLOCKED_OUTPUT. Also, this function
    prints the direction of the player on the board. */
void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    /* TODO */
    int row;
    int column;
    int i;

    printf("| |0|1|2|3|4|5|6|7|8|9|\n");


    for(i = 0, column = 0; i < 10 && column < BOARD_HEIGHT; ++i, ++column)
    {
        printf("|%d|", i);

        for(row = 0; row < BOARD_WIDTH; ++row)
        {
            if(board[column][row] == EMPTY)
            {
                printf("%s|", EMPTY_OUTPUT);
            }

            if(board[column][row] == BLOCKED)
            {
                printf("%s|", BLOCKED_OUTPUT);
            }

            if(board[column][row] == PLAYER)
            {
                if(player -> direction == NORTH)
                {
                    displayDirection(NORTH);
                }

                if(player -> direction == SOUTH)
                {
                    displayDirection(SOUTH);
                }

                if(player -> direction == EAST)
                {
                    displayDirection(EAST);
                }

                if(player -> direction == WEST)
                {
                    displayDirection(WEST);
                }
            }      
        }
        printf("\n");
    }   
}







