
#include "snake.h"

void	setGrid(t_snake *snake)
{
	int		i;

	memset(snake->grid, 0, sizeof(snake->grid[0][0]) * W * (H - 1));
	memset(snake->grid[0], -1, sizeof(snake->grid[0][0]) * W);
	memset(snake->grid[H - 1], -1, sizeof(snake->grid[0][0]) * W);
	i = 0;
	while (i < H)
	{
		snake->grid[i][0] = -1;
		snake->grid[i][W - 1] = -1;
		i++;
	}
}
