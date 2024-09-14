#ifndef SOLVER_H_
#define SOLVER_H_

#include "board.h"

#define MAX_MOVES 31

typedef struct {
    int state[BOARD_SIZE][BOARD_SIZE];
    int from_row, from_col, to_row, to_col;
} Move;

int solve(int steps);

#endif  // SOLVER_H_
