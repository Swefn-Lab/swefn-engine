#include <stdio.h>

#include <SDL3/SDL.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

// TODO(wv): Maybe change to WinMain on Windows instead of hiding terminal
// via linker flags. What difference will it make?
int main()
{
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) == false) {
		fprintf(stderr, "Failed to init SDL3!\n");
		return -1;
	}

	SDL_Window *window;
	SDL_Renderer *renderer;

	bool success = SDL_CreateWindowAndRenderer("Swefn Engine Demo",
						   WINDOW_WIDTH,
						   WINDOW_HEIGHT,
						   0,
						   &window,
						   &renderer);
	if (success == false) {
		fprintf(stderr, "Failed to create window and renderer!\n");
		return -1;
	}

	bool running = true;

	while (running) {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_EVENT_QUIT:
				running = false;
				break;
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 127, 206, 235, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
		
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
}
