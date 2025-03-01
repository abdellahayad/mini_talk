CC     = gcc
CFLAGS = -Wall -Wextra -Werror

NAME   = minitalk

SRC_COMMON  = utils.c
SRC_SERVER  = mandatory/server.c
SRC_CLIENT  = mandatory/client.c
SRC_SERVER_BONUS = bonus/server_bonus.c
SRC_CLIENT_BONUS = bonus/client_bonus.c

OBJ_SERVER  = $(SRC_SERVER:.c=.o) $(SRC_COMMON:.c=.o)
OBJ_CLIENT  = $(SRC_CLIENT:.c=.o) $(SRC_COMMON:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o) $(SRC_COMMON:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o) $(SRC_COMMON:.c=.o)

all: server client

bonus: server_bonus client_bonus

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^

server_bonus: $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

client_bonus: $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)

fclean: clean
	rm -f server client server_bonus client_bonus

re: fclean all

.PHONY: all bonus clean fclean re
