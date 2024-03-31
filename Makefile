# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:30:03 by gbeaudoi          #+#    #+#              #
#    Updated: 2024/03/25 19:23:21 by gbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### COLORS #####################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM		:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED		:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE	:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN	:=	\e[96m


################################### BASICS ###################################

NAME		=	push_swap
BONUS  =	checker

LIBFT = libft/

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3 -I 
INC		=	include/
LIBC		=	ar -rcs
RM		=	rm -rf


################################### SOURCES ###################################

SRC	= 	action_push.c action_reverse_rotate.c action_rotate.c action_swap.c calcul_cost.c calculate_rank.c error_handling.c initialize_info.c initialize_node_1.c initialize_node_2.c \
		list_utils.c main.c maths_utils.c parsing.c perform_move_to_a.c perform_move_to_b.c sorting_algo.c sorting_utils.c parsing_utils.c 
					
SRC_BONUS	= 	action_push_bonus.c action_reverse_rotate_bonus.c action_rotate_bonus.c action_swap_bonus.c checker.c error_handling_bonus.c initialize_node_bonus.c \
		list_utils_bonus.c parsing_bonus.c sorting_utils_bonus.c parsing_utils_bonus.c 

######################## COMBINE DIRECTORIES AND FILES ########################

SRC_DIR		= src/
SRC_DIR_BONUS = src_bonus/

SRC_NAMES	= $(SRC)
SRC_NAMES_BONUS = $(SRC_BONUS)

OBJ_DIR		= obj/
OBJ_DIR_BONUS = obj_bonus/


OBJ	= $(SRC_NAMES:.c=.o)
OBJ_BONUS	= $(SRC_NAMES_BONUS:.c=.o)

OBJ_FOLDERS	= $(addprefix $(OBJ_DIR), $(OBJ))
OBJ_BONUS_FOLDERS = $(addprefix $(OBJ_DIR_BONUS), $(OBJ_BONUS))

#################################### MANDATORY ####################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(GREEN)Compiling: $(RESET)$(ITAL)$<\n"
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

# link .o files to the library
$(NAME):	$(OBJ_FOLDERS)	
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@printf "\n $(BOLD)$(YELLOW)Libft ready! $(RESET)\n"
			@printf "$(RESET)$(BOLD)$(CYAN)[Push_Swap]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJ_FOLDERS) -L$(LIBFT) -lft -o $(NAME) 
			@printf "$(PINK) ./push_swap ready to order$(RESET)\n"


all:		$(NAME)

#################################### BONUS ####################################

$(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(GREEN)Compiling bonus: $(RESET)$(ITAL)$<\n"
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# link .o files to the library
$(BONUS):	$(OBJ_BONUS_FOLDERS)	
			@make -C $(LIBFT)
			@cp $(LIBFT)/libft.a .
			@printf "\n $(BOLD)$(YELLOW)Libft ready! $(RESET)\n"
			@printf "$(RESET)$(BOLD)$(CYAN)[Checker]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(OBJ_BONUS_FOLDERS) -L$(LIBFT) -lft -o $(BONUS)
			@printf "$(PINK) ./checker ready to check $(RESET)\n"

bonus:		$(BONUS)

#################################### RULES ####################################

clean:
		@$(RM) $(OBJ_DIR)
		@$(RM) $(OBJ_DIR_BONUS)
		@make clean -C $(LIBFT)
		@printf "$(BOLD)$(PINK)[fdf]: $(RESET)$(PINK)object files $(RESET)\t\t=> CLEANED! \n\n"

fclean: 	clean
			@$(RM) $(NAME) $(BONUS) 
			@$(RM) $(LIBFT)/libft.a
			@$(RM) libft.a
			@printf "$(BOLD)$(PURPLE)[LIBFT]: $(RESET)$(PURPLE)exec. files $(RESET)\t=> CLEANED! \n\n"
			@printf "$(BOLD)$(BRIGHT_PURPLE)[Push_swap]: $(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED! \n\n"
			@printf "$(BOLD)$(BRIGHT_PURPLE)[Checker]: $(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED! \n\n"

re:		fclean all bonus
			@printf "\n\n $(BOLD)$(YELLOW)Cleaning done! $(RESET)\n"
			
.PHONY:		all clean fclean re bonus