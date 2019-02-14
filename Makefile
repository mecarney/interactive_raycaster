NAME = wolf3d

SRCS = main.c reader.c raycaster.c color.c input_hooks.c input_loop.c

INC = -I libft/

LIB = -L. -lmlx -L libft/ -lft

FRM = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) :
	@#make -C libft
	@#make -C minilibx_macos
	gcc -Wall -Werror -Wextra -c $(SRCS) $(INC)
	gcc -Wall -Werror -Wextra -o $(NAME) *.o $(LIB) $(FRM)
	rm -f *.o

clean:
	@#make -C libft/ clean
	@#make -C minilibx_macos/ clean
	rm -f *.o

fclean: clean
	@#make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
