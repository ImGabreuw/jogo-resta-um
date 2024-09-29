#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>

#include "board.h"

/*
Integrantes:

Enzo Ribeiro                 - 10418262 
Gabriel Ken Kazama Geronazzo - 10418247 
Lucas Zanini da Silva        - 10417361

*/

extern FILE *file;

void init_log_file(void);

void close_log_file(void);

void log_board(int state[BOARD_SIZE][BOARD_SIZE]);

void log_message(const char *format, ...);

#endif
