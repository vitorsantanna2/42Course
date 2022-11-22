################################################################################                       #              						FLAGS                                     #
################################################################################

NAME		:= push_swap
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
DEBUG		:= -g
RM			:= rm -f
LIBFT		:= libft.a

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/start.c \
					src/sort_three.c \
					src/sort_five.c \
					src/sort_utils.c \
					src/last_bigger_digit.c \
					src/swap_rotate_push.c 
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  COLORS                                      #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

###############################################################################
#							FUNCTIONS									 	  #
###############################################################################
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -s -C libft all
			@ cp ./libft/libft.a .
			@ $(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) $(LIBFT)
			@echo "$(GREEN)$(NAME) created[0m ✔️"
all:		${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libft.a
			@ rm libft/libft.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
re:			fclean all

.PHONY:		all clean fclean re


