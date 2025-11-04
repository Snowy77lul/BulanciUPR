#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        printf("Chyba inicializace SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "SDL experiments",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        printf("Chyba pøi vytváøení okna: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer;
    SDL_Texture* image = IMG_LoadTexture(renderer, "image.png");

    // Hlavní smyèka
    SDL_Event e;
    int running = 1;
    while (running) 
    {
        while (SDL_PollEvent(&e)) 
        {
            
            if (e.type == SDL_QUIT) 
            {
                running = 0;
                SDL_DestroyTexture(image);

            }
        }
        SDL_Delay(16); // malá pauza, aby CPU nejelo na 100 %
    }
    int position = 0;
    while (running == 1) 
    {
    // ...

    position += 1;
    SDL_RenderDrawLine(renderer, position, 100, position, 200);

    // ...
    }


    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
