#include <stdio.h>

#include "board.h"
#include "solver.h"

int main()
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
