# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssukhija <ssukhija@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 10:44:57 by ssukhija          #+#    #+#              #
#    Updated: 2025/01/29 10:44:57 by ssukhija         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

# colours
RESET = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m

# commands and flags
CC = cc
RM = rm -rf
CFLAGS = -Wall -Werror -Wextra

# files
CLIENT = client
SERVER = server
CL_OBJ = client.o
SRV_OBJ = server.o
UTILS = utils
UTILS_OBJ = utils.o

#bonusfiles
CLIENT_B = client_bonus
SERVER_B = server_bonus
CL_OBJ_B = client_bonus.o
SRV_OBJ_B = server_bonus.o
UTILS_B = utils_bonus
UTILS_OBJ_B = utils_bonus.o

all: $(CLIENT) $(SERVER) $(CLIENT_B) $(SERVER_B) clean

$(CLIENT): $(CL_OBJ) $(UTILS_OBJ)
	$(CC) $(CLAGS) $(CL_OBJ) $(UTILS_OBJ) -o $(CLIENT); \
	if [ $$? -eq 0 ]; then \
		echo "COMPILE CLIENT ... $(GREEN)[ok]$(RESET)"; \
	else \
		echo "COMPILE CLIENT   ... $(RED)[error]$(RESET)"; \
	fi

$(CLIENT_B): $(CL_OBJ_B) $(UTILS_OBJ_B)
	$(CC) $(CLAGS) $(CL_OBJ_B) $(UTILS_OBJ_B) -o $(CLIENT_B); \
	if [ $$? -eq 0 ]; then \
		echo "COMPILE CLIENT BONUS... $(GREEN)[ok]$(RESET)"; \
	else \
		echo "COMPILE CLIENT BONUS  ... $(RED)[error]$(RESET)"; \
	fi

$(SERVER): $(SRV_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SRV_OBJ) $(UTILS_OBJ) -o $(SERVER); \
	if [ $$? -eq 0 ]; then \
		echo "COMPILE SERVER ... $(GREEN)[ok]$(RESET)"; \
	else \
		echo "COMPILE SERVER   ... $(RED)[error]$(RESET)"; \
	fi

$(SERVER_B): $(SRV_OBJ_B) $(UTILS_OBJ_B)
	$(CC) $(CFLAGS) $(SRV_OBJ_B) $(UTILS_OBJ_B) -o $(SERVER_B); \
	if [ $$? -eq 0 ]; then \
		echo "COMPILE SERVER BONUS ... $(GREEN)[ok]$(RESET)"; \
		echo "Type ./client to run"; \
		echo "Type ./server to run"; \
	else \
		echo "COMPILE SERVER_BONUS   ... $(RED)[error]$(RESET)"; \
	fi

clean:
	$(RM) $(SRV_OBJ) $(CL_OBJ) $(UTILS_OBJ) $(SRV_OBJ_B) $(CL_OBJ_B) $(UTILS_OBJ_B) 
	echo "CLEAN OBJS ... $(GREEN)[ok]$(RESET)"

fclean: clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	echo "FCLEAN ... $(GREEN)[ok]$(RESET)"

re: fclean all

.PHONY: clean fclean all re