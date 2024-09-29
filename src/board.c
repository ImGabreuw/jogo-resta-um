#include "board.h"

#include <stdio.h>

/*
Integrantes:

Enzo Ribeiro                 - 10418262 
Gabriel Ken Kazama Geronazzo - 10418247 
Lucas Zanini da Silva        - 10417361

*/

int row_directions[] = {-2, 2, 0, 0};
int col_directions[] = {0, 0, -2, 2};

// Configuração inicial do tabuleiro (1 = peça, 0 = vazio, -1 = posição inválida)
int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1, -1, 1, 1, 1, -1, -1},
    {-1, -1, 1, 1, 1, -1, -1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {-1, -1, 1, 1, 1, -1, -1},
    {-1, -1, 1, 1, 1, -1, -1}};

int is_move_valid(int start_row, int start_col, int end_row, int end_col)
{
    int middle_row = (start_row + end_row) / 2;
    int middle_col = (start_col + end_col) / 2;

    // Verifica se a posição destino está dentro dos limites
    if (end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE)
        return 0;

    // Verifica se a origem tem uma peça, o meio tem uma peça e o destino está vazio
    if (board[start_row][start_col] == 1 && board[middle_row][middle_col] == 1 && board[end_row][end_col] == 0)
        return 1;

    return 0;
}
