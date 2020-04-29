#ifndef YAP_SCREEN_H
#define YAP_SCREEN_H

#include <SDL2/SDL.h>
#include <stdint.h>

#include "game_object.h"
#include "color.h"

typedef int8_t ScreenOperationResult;

extern const ScreenOperationResult RENDERER_CREATION_ERROR, WINDOW_CREATION_ERROR, VIDEO_INITIALIZATION_ERROR, SCREEN_SUCCESS;

typedef struct screen {
    SDL_Window*   window;
    SDL_Renderer* renderer;
    uint16_t      width;
    uint16_t      height;
} Screen;

ScreenOperationResult init_screen(const char* title, uint16_t width, uint16_t height, Screen* out_screen);
void close_screen(const Screen* const screen);

void initialize_drawing(const Screen* const screen);
void end_drawing(const Screen* const screen);
void draw_boxes(const Screen* const screen, Box** boxes, uint32_t count, Color color);

#endif