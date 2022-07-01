NAME = ft_printf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -c
SRCS = ft_itohex.c ft_printf_util.c ft_printf.c ft_list_node.c ft_uitoa.c
OBJS = $(SRCS:.c=.o)
AR = ar -rcs

.c.o: 
	$(CC) $(CFLAGS) -c $< libft/libft.a -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJECTS)

.PHONY: all clean fclean re
