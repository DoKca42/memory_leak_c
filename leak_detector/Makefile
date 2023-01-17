NAME = leak.a

SOURCES = leak_detector_c.c\

OBJECTS = $(SOURCES:.c=.o)
CC = gcc

all: $(NAME)

clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(SRCBONUS) $(NAME)
	ar rc $(NAME)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)