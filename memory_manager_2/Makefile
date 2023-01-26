NAME = memory_mng.a

SOURCES = memory_manager.c\
		  memory_manager_2.c\
		  memory_manager_utils.c\

OBJECTS = $(SOURCES:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS)

all: $(NAME)

clean:
	rm -f $(OBJECTS) $(OBJBONUS)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(SRCBONUS) $(OBJBONUS) $(NAME)
	ar rc $(NAME) $(OBJBONUS)

$(NAME): $(SOURCES) $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)