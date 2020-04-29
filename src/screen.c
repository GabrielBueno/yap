#include "screen.h"

#include <stdlib.h>

// Const definitions
const ScreenOperationResult RENDERER_CREATION_ERROR    = -3;
const ScreenOperationResult WINDOW_CREATION_ERROR      = -2;
const ScreenOperationResult VIDEO_INITIALIZATION_ERROR = -1;
const ScreenOperationResult SCREEN_SUCCESS             = 1;

void _box_to_sdl_rect(Box* src, SDL_Rect* dest);

ScreenOperationResult init_screen(const char* title, uint16_t width, uint16_t height, Screen* out_screen) {
    if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
        return VIDEO_INITIALIZATION_ERROR;

    SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL)
        return WINDOW_CREATION_ERROR;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
        return RENDERER_CREATION_ERROR;

    out_screen->width    = width;
    out_screen->height   = height;
    out_screen->window   = window;
    out_screen->renderer = renderer;

    return SCREEN_SUCCESS;
}

void close_screen(const Screen* const screen) {
    SDL_DestroyRenderer(screen->renderer);
    SDL_DestroyWindow(screen->window);
}

void initialize_drawing(const Screen* const screen) {
    SDL_SetRenderDrawColor(screen->renderer, 0, 0, 0, 0);
    SDL_RenderClear(screen->renderer);
}

void end_drawing(const Screen* const screen) {
    SDL_RenderPresent(screen->renderer);
}

void draw_boxes(const Screen* const screen, Box** boxes, uint32_t count, Color color) {
    SDL_Rect* rects = malloc(sizeof(SDL_Rect) * count);

    for (uint32_t i = 0; i < count; i++)
        _box_to_sdl_rect(boxes[i], &rects[i]);

    SDL_SetRenderDrawColor(screen->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRects(screen->renderer, rects, count);

    free(rects);
    rects = NULL;
}

void _box_to_sdl_rect(Box* src, SDL_Rect* dest) {
    dest->x = src->x;
    dest->y = src->y;
    dest->w = src->width;
    dest->h = src->height;
}