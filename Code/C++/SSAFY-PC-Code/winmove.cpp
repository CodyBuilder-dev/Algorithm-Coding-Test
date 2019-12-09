#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;

#define SCREEN_WIDTH 50
#define SCREEN_HEIGHT 50
int main(int argc, char** argv)
{
	SDL_Event event;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	int x, y;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		perror("Could not initialize SDL2\n");
		return 1;
	}
	window = SDL_CreateWindow("Move",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_ALWAYS_ON_TOP);
	if (window == NULL) {
		perror("Could not create window\n");
		return 1;
	}
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0xFF));
	SDL_UpdateWindowSurface(window);
	do {
		SDL_PollEvent(&event);
		SDL_GetWindowPosition(window, &x, &y);
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_LEFT: x -= 2; break;
			case SDLK_RIGHT: x += 2; break;
			case SDLK_UP: y -= 2; break;
			case SDLK_DOWN: y += 2; break;
			}
		}
		SDL_SetWindowPosition(window, x, y);
		SDL_Delay(50);
	} while (event.key.keysym.sym != SDLK_ESCAPE);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}