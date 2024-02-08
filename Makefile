# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosh <mosh@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 05:43:03 by mosh              #+#    #+#              #
#    Updated: 2024/02/08 20:01:56 by mosh             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT = ./lib/libftprintf.a
RM = rm -rf

SERVER = server
CLIENT = client
SERVER-BONUS = server_bonus
CLIENT-BONUS = client_bonus

SRC-SERVER = ./mandatory/server_utils.c
SRC-MAIN-SERVER = ./mandatory/server_main.c
SRC-CLIENT = ./mandatory/client_utils.c
SRC-MAIN-CLIENT = ./mandatory/client_main.c

SRC-SERVER-BONUS = ./bonus/server_utils_bonus.c
SRC-MAIN-SERVER-BONUS = ./bonus/server_main_bonus.c
SRC-CLIENT-BONUS = ./bonus/client_utils_bonus.c
SRC-MAIN-CLIENT-BONUS = ./bonus/client_main_bonus.c

OBJ-SERVER = $(SRC-SERVER:.c=.o)
OBJ-MAIN-SERVER = $(SRC-MAIN-SERVER:.c=.o)
OBJ-CLIENT = $(SRC-CLIENT:.c=.o)
OBJ-MAIN-CLIENT = $(SRC-MAIN-CLIENT:.c=.o)

OBJ-SERVER-BONUS = $(SRC-SERVER-BONUS:.c=.o)
OBJ-MAIN-SERVER-BONUS = $(SRC-MAIN-SERVER-BONUS:.c=.o)
OBJ-CLIENT-BONUS = $(SRC-CLIENT-BONUS:.c=.o)
OBJ-MAIN-CLIENT-BONUS = $(SRC-MAIN-CLIENT-BONUS:.c=.o)

NAME = $(SERVER) $(CLIENT)

ifeq ($(bonus),true)
	OBJ-SERVER += $(OBJ-SERVER-BONUS)
	OBJ-CLIENT += $(OBJ-CLIENT-BONUS)
endif

all: $(NAME)

bonus: $(SERVER-BONUS) $(CLIENT-BONUS)
	@make bonus=true

$(LIBFT): 
	$(MAKE) -C ./lib

$(SERVER): $(OBJ-SERVER) $(OBJ-MAIN-SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-SERVER) $(OBJ-MAIN-SERVER) $(LIBFT) -o server
$(CLIENT): $(OBJ-CLIENT) $(OBJ-MAIN-CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-CLIENT) $(OBJ-MAIN-CLIENT) $(LIBFT) -o client
$(SERVER-BONUS): $(OBJ-SERVER-BONUS) $(OBJ-MAIN-SERVER-BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-SERVER-BONUS) $(OBJ-MAIN-SERVER-BONUS) $(LIBFT) -o server_bonus
$(CLIENT-BONUS): $(OBJ-CLIENT-BONUS) $(OBJ-MAIN-CLIENT-BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ-CLIENT-BONUS) $(OBJ-MAIN-CLIENT-BONUS) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./lib
	$(RM) $(OBJ-SERVER) $(OBJ-CLIENT)
	$(RM) $(OBJ-MAIN-SERVER) $(OBJ-MAIN-CLIENT)
	$(RM) $(OBJ-SERVER-BONUS) $(OBJ-CLIENT-BONUS)
	$(RM) $(OBJ-MAIN-SERVER-BONUS) $(OBJ-MAIN-CLIENT-BONUS)

fclean: clean
	$(MAKE) fclean -C ./lib	
	$(RM) $(SERVER) $(CLIENT)
	$(RM) $(SERVER-BONUS) $(CLIENT-BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
