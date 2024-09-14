#ifndef BOARD_H_
#define BOARD_H_

#define BOARD_SIZE 7

extern int board[BOARD_SIZE][BOARD_SIZE];

void print_board(int state[BOARD_SIZE][BOARD_SIZE]);

int is_move_valid(int start_row, int start_col, int end_row, int end_col);

// Direções de movimento: cima, baixo, esquerda, direita
extern int row_directions[4];
extern int col_directions[4];

#endif  // BOARD_H_
