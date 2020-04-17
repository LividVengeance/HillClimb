#pragma once

#include "CHillClimb.h"
#include "CGameBoard.h"

#include <iostream>
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <vector>

CHillClimb::CHillClimb(int boardSize)
{
	gameBoardSize = boardSize;

	// Creating the first board
	CGameBoard* firstBoard = new CGameBoard(gameBoardSize);
	firstBoard->FirstBoard();
	std::cout << firstBoard->GetHeuristic() << " - First Solution" << std::endl;
	// Set the first board to the best board
	bestBoard = firstBoard;
	BoardIterations(firstBoard);
}

CHillClimb::~CHillClimb()
{
}

void CHillClimb::BoardIterations(CGameBoard* currentBoard)
{
	// Check all new boards generated at set if better
	int finalTemp = 0;
	while (currentTemp > finalTemp)
	{
		// Generating a new board
		CGameBoard* newBoard = new CGameBoard(gameBoardSize);
		newBoard->AlteredBoard(currentBoard->gameBoard);
		
		int deltaCost = (newBoard->GetHeuristic() - bestBoard->GetHeuristic());
		if (deltaCost < 0)
		{
			bestBoard = newBoard;
		}
		// Delata greater than random num between 0-1
		else if ((((double)rand() / (RAND_MAX)) + 1) > exp(deltaCost/currentTemp))
		{
			bestBoard =  newBoard;
		}
		
		// Found the best solution or finished all iterations
		if ((bestBoard->GetHeuristic() == 0))
		{
			std::cout << bestBoard->GetHeuristic() << " - Curent Temp - " << currentTemp << " The Final Solution" << std::endl;
			break;
		}
		else
		{
			// Haven't found the best solution or temp reached 0
			currentTemp--;
			std::cout << bestBoard->GetHeuristic() << " - Curent Temp - " << currentTemp << std::endl;
		}
	}
}