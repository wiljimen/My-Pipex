NAME = pipex.a

RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f
		
SRCS = src/pipex.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I includes/pipex.h -I includes/libft.h

LIBFT_DIR = libft/

MAKEFLAGS += --silent

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@make all -sC $(LIBFT_DIR)
	@cp ./libft/libft.a .
	@echo "$(GREEN)Libft compiled"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft.a -o $(NAME)
	@echo "$(GREEN)Pipex compiled"

clean :
		@$(RM) $(OBJS)
		@make clean -sC  $(LIBFT_DIR)
		@echo "$(RED)Clean done"

fclean : clean
		@$(RM) $(NAME)
		@make fclean -sC  $(LIBFT_DIR)
		@$(RM) $(NAME) libft.a
		@echo "$(RED)fclean done"

re : fclean all

.PHONY: all clean fclean re