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
	// Create a tempBoard so that when assigning bestBoard no memory leck
	CGameBoard* tempBoard;

	// Store all the new boards to be generated
	std::vector<CGameBoard*> newGendBoards;

	// Create all the new boards based on inputed board
	for (int rowToChange = 0; rowToChange < gameBoardSize; rowToChange++)
	{
		// Create a new board
		CGameBoard* newBoard = new CGameBoard(gameBoardSize);
		newBoard->AlteredBoard(currentBoard->gameBoard);

		//Adding newBoard to newGendBoards
		newGendBoards.push_back(newBoard);
	}

	tempBoard = bestBoard;

	// Check all new boards generated at set if better
	for (int i = 0; i < (int)newGendBoards.size(); i++)
	{
		if (newGendBoards[i]->GetHeuristic() < bestBoard->GetHeuristic())
		{
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

	// Delete the tempBoard if its not the best board
	if (tempBoard != bestBoard)
	{
		delete tempBoard;
	}
	
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