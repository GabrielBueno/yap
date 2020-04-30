COMPILER        = gcc
INPUT           = ./src/color.c ./src/game_object.c ./src/ball.c ./src/player.c ./src/screen.c ./src/game.c ./src/main.c
OUTPUT          = ./bin/yap
COMPILER_FLAGS  = -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter -lm
SDL2_FLAGS      = -I/usr/include -D_REENTRANT -L/usr/lib -pthread -lSDL2

all:
	${COMPILER} -o ${OUTPUT} ${INPUT} ${COMPILER_FLAGS} ${SDL2_FLAGS}


