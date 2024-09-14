#include "solver.h"

#include <stdio.h>
#include <string.h>

Move moves[MAX_MOVES];
int move_count = 0;

int solve(int steps)
{
    // Condição de parada: Se for feito 31 movimentos e restar apenas uma peça no centro, a solução foi encontrada
    if (steps == MAX_MOVES && board[3][3] == 1)
    {
        printf("Solução encontrada:\n");

        for (int i = 0; i < move_count; i++)
        {
            printf("Movimento da peça (%d, %d) para (%d, %d)\n",
                   moves[i].from_row, moves[i].from_col, moves[i].to_row, moves[i].to_col);
            print_board(moves[i].state);
        }

        print_board(board);
        return 1;
    }

    // Tenta mover cada peça
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            // Se há uma peça na posição (row, col)
            if (board[row][col] == 1)
            {
                // Tenta todas as direções (cima, baixo, esquerda, direita)
                for (int dir = 0; dir < 4; dir++)
                {
                    int new_row = row + row_directions[dir];
                    int new_col = col + col_directions[dir];
                    int middle_row = (row + new_row) / 2;
                    int middle_col = (col + new_col) / 2;

                    if (is_move_valid(row, col, new_row, new_col))
                    {
                        // Salva o estado atual do tabuleiro
                        Move move;
                        memcpy(move.state, board, sizeof(board));
                        move.from_row = row;
                        move.from_col = col;
                        move.to_row = new_row;
                        move.to_col = new_col;

                        // Realiza o movimento (peça pula)
                        board[row][col] = 0;               // Origem fica vazia
                        board[middle_row][middle_col] = 0; // Peça pulada removida
                        board[new_row][new_col] = 1;       // Destino recebe a peça

                        // Adiciona o movimento à lista
                        moves[move_count++] = move;

                        if (solve(steps + 1))
                        {
                            return 1;
                        }

                        // Desfaz o movimento
                        move_count--;
                        memcpy(board, move.state, sizeof(board));
                    }
                }
            }
        }
    }
    
    return 0;
}
