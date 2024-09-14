#!/bin/bash

SRC_DIR="./src"
INCLUDE_DIR="./include"

OUTPUT="peg_solitaire"

CFLAGS="-Wall -Werror -I$INCLUDE_DIR -I$INCLUDE_DIR"

SRC_FILES=$(find . -path ./test -prune -o -name "*.c" -print)

echo "Compiling project..."

gcc $CFLAGS -o $OUTPUT $SRC_FILES

if [ $? -eq 0 ]; then
    echo "Compilation successful! Output binary: $OUTPUT"
else
    echo "Compilation failed!"
fi
