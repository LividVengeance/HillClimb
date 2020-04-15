#pragma once

#include <iostream>
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "CGameBoard.h"

class CHillClimb
{
public:
	CHillClimb(int boardSize);
	~CHillClimb();

	int gameBoardSize;
	CGameBoard* bestBoard;

private:
	int iterations = 0;
	void BoardIterations(CGameBoard* gameBoard);

};

