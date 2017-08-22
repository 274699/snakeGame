
#ifndef snake_h
#define snake_h

# include <stdlib.h>
# include <unistd.h>
# include <SDL2/SDL.h>
# define WID 480
# define HEIG 320
# define W WID / 20
# define H HEIG / 20

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		e;
}					t_sdl;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				head;
}					t_pos;

typedef struct		s_snake
{
	t_sdl			sdl;
	int				stop;
	int				grid[H][W];
	t_pos			*body[H * W];
	t_pos			move;
	t_pos			point;
}					t_snake;

void				sdlInit(t_snake *snake);
void				sdlDestroy(t_snake *snake);
void				sdlRender(t_snake * snake);
void				introCountDown(t_snake * snake);
int					snakeCycle(t_snake *snake);
void				drawGrid(t_snake *snake);
void				setGrid(t_snake *snake);
void				sdlRenderClear(t_snake * snake);
void				reDraw(t_snake *snake);
void				setBody(t_snake *snake);

#endif
