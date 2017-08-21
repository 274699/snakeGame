
#ifndef snake_h
#define snake_h

# include <stdlib.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# include <SDL2_ttf/SDL_ttf.h>
# define WID 480
# define HEIG 320

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
	TTF_Font		*font;
	SDL_Rect		message_rect;
	SDL_Surface		*surface_message;
	SDL_Texture		*message;
}					t_sdl;

typedef struct		s_snake
{
	t_sdl			sdl;
}					t_snake;

void					sdlInit(t_snake *snake);
void					sdlDestroy(t_snake *snake);
void					sdlRender(t_snake * snake);

#endif
