#include "Window.h"

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 1000

#define X_POSITION 510
#define Y_POSITION 40

#define WINDOW_FLAGS SDL_WINDOW_SHOWN

#include <iostream>

SDL_Window* Window::_window(nullptr);
SDL_Renderer* Window::_renderer(nullptr);
SDL_Texture* Window::_texture(nullptr);

void Window::Init()
{
  SDL_DisplayMode current;

  SDL_GetCurrentDisplayMode(0, &current);

  int window_width = WINDOW_WIDTH;
  int window_height = WINDOW_HEIGHT;
  int x_position = X_POSITION;
  int y_position = Y_POSITION;

  if (current.w == 1366 && current.h == 768) {
    window_width = 600;
    window_height = 700;
    x_position = 383;
    y_position = 34;
  }

  _window = SDL_CreateWindow("SpaceBound",
    x_position, y_position, window_width, window_height, WINDOW_FLAGS);

  _renderer = SDL_CreateRenderer(_window, -1, 0);

  _texture = SDL_CreateTexture(_renderer, SDL_PIXELFORMAT_ARGB8888,
    SDL_TEXTUREACCESS_STREAMING, window_width, window_height);
}

void Window::Quit()
{
  SDL_DestroyTexture(_texture);
  SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}

void Window::Clear()
{
  SDL_RenderClear(_renderer);
}

void Window::Render(SDL_Surface* surface)
{
  SDL_UpdateTexture(_texture, NULL, surface->pixels, surface->pitch);
  SDL_RenderCopy(_renderer, _texture, NULL, NULL);
  SDL_RenderPresent(_renderer);
}

std::size_t Window::GetWidth()
{
  int width, height;

  SDL_GetWindowSize(_window, &width, &height);

  return width;
}

std::size_t Window::GetHeight()
{
  int width, height;

  SDL_GetWindowSize(_window, &width, &height);

  return height;
}