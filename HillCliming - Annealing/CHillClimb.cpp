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
		CGameBoard* newBoard = new CGameBoard(gameBoardSize);
		newBoard->DuplicateBoard(currentBoard->gameBoard);
		
		int deltaCost = (newBoard->GetHeuristic() - bestBoard->GetHeuristic());
		if (deltaCost < 0)
		{
			bestBoard = newBoard;
		}
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
			currentTemp--;
			std::cout << bestBoard->GetHeuristic() << " - Curent Temp - " << currentTemp << std::endl;
			iterations++;
		}
	}

	
	
}