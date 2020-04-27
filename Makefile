COMPILER       = gcc
INPUT          = ./src/screen.c ./src/main.c
OUTPUT         = ./bin/yap
COMPILER_FLAGS = -Wall -Wextra
SDL2_FLAGS     = -I/usr/include -D_REENTRANT -L/usr/lib -pthread -lSDL2

all:
	${COMPILER} -o ${OUTPUT} ${INPUT} ${COMPILER_FLAGS} ${SDL2_FLAGS}


