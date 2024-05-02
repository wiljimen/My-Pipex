NAME = libft.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_itoa.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	   ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c ft_memset.c ft_strdup.c ft_strchr.c ft_strjoin.c ft_strlcat.c  \
	   ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c \
	   ft_strtrim.c ft_split.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_tolower.c ft_toupper.c \
	   get_next_line.c get_next_line_utils.c ft_char_str.c ft_hex.c	ft_put_ptr.c \
	   ft_printf.c ft_putnum.c \

OBJS = $(SRCS:.c=.o)

INCLUDE = ../includes/libft.h

BSRCS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

BOBJS = $(BSRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDE)
	ar -rcs $(NAME) $(OBJS)

bonus : $(OBJS) $(BOBJS) $(INCLUDE)
	ar -rcs $(NAME) $(BOBJS) $(OBJS) $(INCLUDE)

$.o : %.c
	$(cc) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re