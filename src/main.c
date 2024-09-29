#include <stdio.h>

#include "board.h"
#include "solver.h"
#include "log.h"

/*
Integrantes:

Enzo Ribeiro                 - 10418262 
Gabriel Ken Kazama Geronazzo - 10418247 
Lucas Zanini da Silva        - 10417361

Código fonte: https://github.com/ImGabreuw/peg-solitaire-english-game
*/

int main(void)
{
    init_log_file();

    log_message("Tabuleiro inicial:");
    log_board(board);

    if (!solve(0))
    {
        log_message("Nenhuma solução encontrada.");
        return 1;
    }

    close_log_file();

    return 0;
}
