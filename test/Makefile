NAME 	:= test
MM		:= ../memory_manager_2

LIBS	:= $(MM)/memory_mng.a -g -fsanitize=address

SRCS := test.c\
		test_2.c

OBJS	:= ${SRCS:.c=.o}
FLAGS 	:= -Wall -Wextra -Werror
CC 		:= gcc $(FLAGS)

all: mm $(NAME)

mm:
	@$(MAKE) -C $(MM)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MM) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MM) fclean

re: fclean all

$(NAME): $(SRCS) $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)