# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 23:46:53 by sonamcrumie       #+#    #+#              #
#    Updated: 2024/03/21 13:41:07 by scrumier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj/
SRC_DIR = src/
SRC_1 = instructions1.c instructions2.c instructions3.c main.c radix.c \
		sort_five.c sort_five_bis.c utils.c t_list.c index.c check_args.c \
		free_list.c

OBJ_1 = $(addprefix $(OBJ_DIR), $(SRC_1:.c=.o))

LIBFT_DIR = libft
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)/includes
LIBFT_LINK = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(LIBFT_INC) -MMD -MP -c $< -o $@

-include $(OBJ_1:.o=.d)

$(NAME): $(OBJ_1) $(LIBFT) FORCE
	$(CC) $(FLAGS) $(OBJ_1) -o $(NAME) $(LIBFT_LINK)

$(LIBFT): FORCE
	make -C $(LIBFT_DIR)

$(LIBFT_OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c | $(LIBFT_OBJ_DIR)
	$(LIBFT_CC) $(LIBFT_FLAGS) -MMD -MP -c $< -o $@ $(LIBFT_INC)

-include $(LIBFT_OBJ:.o=.d)

clean:
	$(RM) $(OBJ_1)
	$(RM) -r $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

FORCE:

re: fclean all

.PHONY: all clean fclean re FORCE
