SRC = ft_split.c ft_strncmp.c ft_substr.c main.c main2.c ft_strlen.c ft_strjoin.c
CC = CC
FLAGS = -Wall -Wextra -Werror
NAME = pipex
OBJ = $(SRC:.c=.o)

all :$(NAME)
$(NAME) : $(OBJ)
				$(CC) $(SRC) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)
re : fclean all
