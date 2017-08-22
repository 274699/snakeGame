
NAME = snakeGame

CC = gcc

CFLAGS =  -F. -Wall -Werror -Wextra

SDL_FLAGS = -framework SDL2

OBJ = drawGrid.o main.o setGrid.o initSdl.o setBody.o snakeReDraw.o

HEADER = snake.h


all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC)  $^ $(CFLAGS) $(SDL_FLAGS) -o $@


clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all
