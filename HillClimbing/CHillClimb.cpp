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
	// Store all the new boards to be generated
	std::vector<CGameBoard*> newGendBoards;

	// Create all the new boards based on inputed board
	for (int rowToChange = 0; rowToChange < gameBoardSize; rowToChange++)
	{
		CGameBoard* newBoard = new CGameBoard(gameBoardSize);

		newBoard->DuplicateBoard(currentBoard->gameBoard);

		//Adding newBoard to newGendBoards
		newGendBoards.push_back(newBoard);
	}

	// Check all new boards generated at set if better
	for (int i = 0; i < (int)newGendBoards.size(); i++)
	{
		if (newGendBoards[i]->GetHeuristic() < bestBoard->GetHeuristic())
		{
			delete bestBoard;
			bestBoard = newGendBoards[i];
		}
	}

	// Delete unused boards
	for (int i = 0; i < (int)newGendBoards.size() - 1; i++)
	{
		if (newGendBoards[i] != bestBoard)
		{
			delete newGendBoards[i];
		}
	}

	// Regenerate new boards based on new best board
	if (iterations < gameBoardSize)
	{
		std::cout << bestBoard->GetHeuristic() << " - " << iterations << std::endl;
		iterations++;
		BoardIterations(bestBoard);
	}
	// Found the best solution or finished all iterations
	else if ((iterations = gameBoardSize) or (bestBoard->GetHeuristic() == 0))
	{
		std::cout << bestBoard->GetHeuristic() << " - " << iterations << " The Final Solution" << std::endl;
	}
}