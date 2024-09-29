#include "log.h"

#include <stdarg.h>

/*
Integrantes:

Enzo Ribeiro                 - 10418262 
Gabriel Ken Kazama Geronazzo - 10418247 
Lucas Zanini da Silva        - 10417361

*/

FILE *file = NULL;

void init_log_file()
{
    file = fopen("log.txt", "w");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de log!\n");
    }
}

void close_log_file()
{
    if (file != NULL)
    {
        fclose(file);
    }
}

void log_board(int state[BOARD_SIZE][BOARD_SIZE])
{
    if (file == NULL)
    {
        printf("Arquivo de log não está aberto!\n");
        return;
    }

    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (state[row][col] == -1)
                fprintf(file, "  ");
            else
                fprintf(file, "%d ", state[row][col]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}

void log_message(const char *format, ...)
{
    if (file == NULL)
    {
        printf("Arquivo de log não está aberto!\n");
        return;
    }

    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    fprintf(file, "\n");
    va_end(args);
}
