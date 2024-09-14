#include <stdio.h>

#include "board.h"
#include "solver.h"

/*
Integrantes:

Enzo Ribeiro                 - 10418262 
Gabriel Ken Kazama Geronazzo - 10418247 
Lucas Zanini da Silva        - 10417361

*/

int main(void)
{
    printf("Tabuleiro inicial:\n");
    print_board(board);

    if (!solve(0))
    {
        printf("Nenhuma solução encontrada.\n");
        return 1;
    }

    return 0;
}
