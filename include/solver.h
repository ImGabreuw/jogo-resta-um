#ifndef SOLVER_H_
#define SOLVER_H_

#include "board.h"

/*
Integrantes:

Enzo Ribeiro                 - 10418262 
Gabriel Ken Kazama Geronazzo - 10418247 
Lucas Zanini da Silva        - 10417361

*/

#define MAX_MOVES 31

typedef struct {
    int state[BOARD_SIZE][BOARD_SIZE];
    int from_row, from_col, to_row, to_col;
} Move;

int solve(int steps);

#endif  // SOLVER_H_
