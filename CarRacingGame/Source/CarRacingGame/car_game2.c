#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int CAR_WIDTH = 40;
const int CAR_HEIGHT = 80;

int main(int argc, char* args[]) {
   
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

   
    SDL_Window* window = SDL_CreateWindow("C Real Car Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

   
    SDL_Rect car = { (SCREEN_WIDTH / 2) - (CAR_WIDTH / 2), SCREEN_HEIGHT - 100, CAR_WIDTH, CAR_HEIGHT };
    bool quit = false;
    SDL_Event e;
    int carSpeed = 5;

   
    while (!quit) {
        // Handle Events (Input)
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;
        }

        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_LEFT] && car.x > 0) car.x -= carSpeed;
        if (currentKeyStates[SDL_SCANCODE_RIGHT] && car.x < SCREEN_WIDTH - CAR_WIDTH) car.x += carSpeed;

        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
        SDL_Rect road = { 100, 0, 440, SCREEN_HEIGHT };
        SDL_RenderFillRect(renderer, &road);

      
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &car);

        
        SDL_RenderPresent(renderer);

        SDL_Delay(16); 
    }

  
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}