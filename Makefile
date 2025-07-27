NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_SRCS = client.c
SERVER_SRCS = server.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(NAME_SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re 
