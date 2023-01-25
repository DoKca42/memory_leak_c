NAME 	:= test
MM		:= ../memory_manager_2

LIBS	:= $(MM)/memory_mng.a -g -fsanitize=address

SRCS := test.c\
		test_2.c

OBJS	:= ${SRCS:.c=.o}
FLAGS 	:= -Wall -Wextra -Werror
CC 		:= gcc $(FLAGS)

all: $(NAME)

mm:
	@$(MAKE) -C $(MM)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

$(NAME): $(SRCS) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)