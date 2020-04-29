#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include "player.h"

typedef int8_t  GameOperationResult;
typedef uint8_t GameState;

extern const uint32_t SCREEN_WIDTH;
extern const uint32_t SCREEN_HEIGHT;

extern const GameOperationResult GAME_SUCCESS;
extern const GameOperationResult GAME_SDL_INIT_ERROR;
extern const GameOperationResult GAME_SCREEN_INIT_ERROR;

extern const GameState GAME_STATE_CREATED;
extern const GameState GAME_STATE_RUNNING;
extern const GameState GAME_STATE_PAUSED;
extern const GameState GAME_STATE_ENDED;

typedef struct game {
    Screen    screen;
    GameState state;
    uint32_t  last_tick;

    Player player1;
    Player player2;
} Game;

GameOperationResult init_game(Game* out_game);
void run_game(Game* game);
void close_game(Game* game);

#endif