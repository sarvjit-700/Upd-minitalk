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

all: $(CLIENT) $(SERVER) clean

$(CLIENT): $(CL_OBJ) $(UTILS_OBJ)
	$(CC) $(CLAGS) $(CL_OBJ) $(UTILS_OBJ) -o $(CLIENT); \
	if [ $$? -eq 0 ]; then \
		echo "COMPILE CLIENT ... $(GREEN)[ok]$(RESET)"; \
		echo "Type ./client to run"; \
	else \
		echo "COMPILE CLIENT   ... $(RED)[error]$(RESET)"; \
	fi

$(SERVER): $(SRV_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SRV_OBJ) $(UTILS_OBJ) -o $(SERVER); \
	if [ $$? -eq 0 ]; then \
		echo "COMPILE SERVER ... $(GREEN)[ok]$(RESET)"; \
		echo "Type ./server to run"; \
	else \
		echo "COMPILE SERVER   ... $(RED)[error]$(RESET)"; \
	fi

clean:
	$(RM) $(SRV_OBJ) $(CL_OBJ) $(UTILS_OBJ) 
	echo "CLEAN OBJS ... $(GREEN)[ok]$(RESET)"

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	echo "FCLEAN ... $(GREEN)[ok]$(RESET)"

re: fclean all

.PHONY: clean fclean all re