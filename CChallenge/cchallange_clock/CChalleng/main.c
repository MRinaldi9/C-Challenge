#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

void plotLineAngle(SDL_Renderer* renderer, int xs, int ys, double degrees, double magnitude);

const float sector = (3.14159265359 * 2) / 360;
const int screen_widht = 720;
const int screen_height = 720;



int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    
    time_t t;
    struct tm tm;
    
	int second;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    if (SDL_CreateWindowAndRenderer(screen_widht, screen_height, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    while (1) {
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
		
		t = time(NULL);
		localtime_s(&tm,&t);
		
		second = tm.tm_sec;
		
		
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
        plotLineAngle(renderer, screen_widht/2, screen_height/2, second * 6 - 90, 300);
        
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}


void plotLineAngle(SDL_Renderer* renderer, int xs, int ys, double degrees, double magnitude) {
	
	double w = magnitude * cos (degrees * sector);
    double h = magnitude * sin (degrees * sector);
    SDL_RenderDrawLine(renderer, xs, ys, xs+(int)w, ys+(int)h);
    
}


