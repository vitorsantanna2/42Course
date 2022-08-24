# Library Name #
NAME	=
CLIENT	=	client
SERVER	=	server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# Libft Variables #
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

# Mandatory Variables #
SRC_C	=	src/client.c
SRC_S	=	src/server.c
SRC_C_BONUS = src/client_bonus.c
SRC_S_BONUS = src/server_bonus.c

INC		=	-I. -I$(LIBFT_DIR)

# Compiling Variables #
CC	=	cc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

# Colors #
GREEN		=	\e[32m
YELLOW		=	\e[33m
RESET		=	\e[0m
_SUCCESS	=	✅ $(GREEN)Successfully compiled$(RESET)
_INFO		=	ℹ️  $(YELLOW)Info$(RESET)

all: $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(NAME): all

$(SERVER): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) server mandatory is ready.\n"

$(CLIENT): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) client mandatory is ready.\n"

$(SERVER_BONUS): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_S_BONUS) $(LIBFT) $(INC) -o $(SERVER_BONUS) 
	@printf "$(_SUCCESS) server bonus is ready.\n"

$(CLIENT_BONUS): $(LIBFT)
	@$(CC) $(CFLAG) $(SRC_C_BONUS) $(LIBFT) $(INC) -o $(CLIENT_BONUS)
	@printf "$(_SUCCESS) client bonus is ready. \n"

$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"
	@$(RM) $(CLIENT_BONUS) $(SERVER_BONUS)
	@printf "$(_INFO) client bonus removed. \n"
	@printf "$(_INFO) server bonus removed. \n"

fclean: clean
	@$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		$(CLIENT_BONUS) $(SERVER_BONUS)

m : mandatory
b : bonus

.PHONY: all fclean clean re mandatory m bonus b
