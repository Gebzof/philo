NAME = philo

SRCS = srcs/philo.c\
		srcs/philo_utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g3

CC = cc

.PHONY = re fclean clean all

all : $(NAME)

%.o: %.C
	$(CC) $(CFLAGS) $(SRCS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)
	rm -f $(NAME)

fclean : clean

re : fclean all