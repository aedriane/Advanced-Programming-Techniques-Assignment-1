#include "player.h"

/*  
 *  COSC1076 - Advanced Programming Techniques
 *  Assignment 1
 *   Full Name:        Aedriane Hernan
 *   Student Number:   s34541804
 *   Course Code:      COSC1076
 *   Program code:     BP162
*/ 

/* This function references the player struct in player.h, it gets the member
    of direction, position, and moves that player currently retains. */
void initialisePlayer(Player * player, Position * position, Direction direction)
{   
	player -> direction = direction;
	player -> position = *position;
	player -> moves = 0;    
}

/* Function to determine player's direciton on the board. Simply using if and else if statements. */
void turnDirection(Player * player, TurnDirection turnDirection)
{
    if(turnDirection == TURN_RIGHT)
    {
        if(player -> direction == NORTH)
        {
            player -> direction = EAST;
        }

        else if(player -> direction == EAST)
        {
            player -> direction = SOUTH;
        }

        else if(player -> direction == SOUTH)
        {
            player -> direction = WEST;
        }

        else if(player -> direction == WEST)
        {
            player -> direction = NORTH;
        }
    }

    if(turnDirection == TURN_LEFT)
    {
        if(player -> direction == NORTH)
        {
            player -> direction = WEST;
        }

        else if(player -> direction == WEST)
        {
            player -> direction = SOUTH;
        }

        else if(player -> direction == SOUTH)
        {
            player -> direction = EAST;        
        }

        else if(player -> direction == EAST)
        {
            player -> direction = NORTH;
        }
    }
}


/* This function obtains the next position that the player will move forward to.
    Contains simple logic where if the player is facing north and they move forward,
    the player decrease its position by 1. For example: if my player has init 5,3,north,
    and they move forward, their position will be 4,3,north because it's going up the board,
    and the numerical order from bottom to top is descending. */
Position getNextForwardPosition(const Player * player)
{
    Position position;

    position = player -> position;

    if (player->direction == NORTH)
    {
        position.y--;
    }

    else if (player->direction == EAST)
    {
        position.x++;
    }

    else if (player->direction == SOUTH)
    {
        position.y++;
    }
    
    else if (player->direction == WEST)
    {
        position.x--;
    }
    return position;
}


/* This function updates the player's position and keeps track of the current
    moves the player has made if they have successfully moved forward. */
void updatePosition(Player * player, Position position)
{
    player -> position = position;

    player -> moves++;
}

/* Simple function to determine what direction the player is facing on
    the board. It will print the necessary arrow corresponding to the
    arrow direction. */
void displayDirection(Direction direction)
{
    if(direction == NORTH)
    {
    	printf("%s|", DIRECTION_ARROW_OUTPUT_NORTH);
    }

    if(direction == SOUTH)
    {
    	printf("%s|", DIRECTION_ARROW_OUTPUT_SOUTH);
    }

    if(direction == EAST)
    {
    	printf("%s|", DIRECTION_ARROW_OUTPUT_EAST);
    }

    if(direction == WEST)
    {
    	printf("%s|", DIRECTION_ARROW_OUTPUT_WEST);
    }
}
