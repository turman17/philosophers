NAME = philo

CC = clang-12

FLAGS =  -Wall -Wextra -Werror -g

SOURCES = main.c ./utils/utils.c src/philo.c utils/checker.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -I. -o $(NAME)

fclean: 
	rm -rf $(NAME) $(OBJECTS)

re: fclean all
