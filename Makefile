NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -fsanitize=thread

SOURCES = main.c ./utils/utils.c src/philo.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -I. -o $(NAME)

fclean: 
	rm -rf $(NAME) $(OBJECTS)

re: fclean all
