################################################################################                       #              						FLAGS                                     #
################################################################################

NAME        := fractol
CC        := cc
FLAGS    := -Wall -Wextra -Werror 
RM		    := rm -f

################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      src/fractol.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

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
			@ $(MAKE) -C mlx all &> /dev/null
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit
			@echo "$(GREEN)$(NAME) created[0m ✔️"
all:		${NAME}
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ rm mlx/libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
re:			fclean all

.PHONY:		all clean fclean re


