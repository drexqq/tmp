CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = rush-02
SOURCES = dict.c file.c print_number.c split.c util.c trim.c valid_param.c main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(TARGET)
re: fclean all
