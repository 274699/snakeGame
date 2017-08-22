#include "snake.h"

void		setBody(t_snake *snake)
{
	if (snake->body[0] == NULL)
	{
		snake->body[0] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[0]->x = 12;
		snake->body[0]->y = 10;
		snake->body[0]->head = 2;
		
		snake->body[1] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[1]->x = 13;
		snake->body[1]->y = 10;
		snake->body[1]->head = 1;
		
		snake->body[2] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[2]->x = 14;
		snake->body[2]->y = 10;
		snake->body[2]->head = 1;
		
		snake->body[3] = (t_pos*)malloc(sizeof(t_pos));
		snake->body[3]->x = 14;
		snake->body[3]->y = 10;
		snake->body[3]->head = 1;
		
		snake->body[4] = NULL;
	}
}
