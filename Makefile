COMPILER       = gcc
INPUT          = ./src/main.c
OUTPUT         = ./bin/yap
COMPILER_FLAGS = -Wall -Wextra
# SDL2_FLAGS     = 

all:
	${COMPILER} -o ${OUTPUT} ${INPUT} ${COMPILER_FLAGS}
