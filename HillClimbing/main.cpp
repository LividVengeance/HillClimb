#pragma once

#include <iostream>
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

#include "CGameBoard.h"
#include "CHillClimb.h"

int main()
{
	srand(time(NULL));

	int boardSize;
	std::cout << "Please input a board size: ";
	std::cin >> boardSize;

	CHillClimb climbingTheHill(boardSize);
}
