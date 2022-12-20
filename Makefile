NAME            =   minitalk

SERVER			=	server
SERVER_SRC		=	server.c

SERVER_B		=	server_bonus
SERVER_BSRC		=	server_bonus.c

CLIENT			=	client
CLIENT_SRC		=	client.c

CLIENT_B		=	client_bonus
CLIENT_BSRC		=	client_bonus.c

UTILS_SRC		=	utils.c 

CC				=	gcc
RM 				=	rm -rf
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) :
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)


$(CLIENT) :
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)


fclean :
	$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)

bonus : $(SERVER_B) $(CLIENT_B)

$(SERVER_B) :
	$(CC) $(FLAGS) $(SERVER_BSRC) $(UTILS_SRC) -o $(SERVER_B)


$(CLIENT_B) :
	$(CC) $(FLAGS) $(CLIENT_BSRC) $(UTILS_SRC) -o $(CLIENT_B)


re : fclean all

.PHONY: all fclean re bonus

