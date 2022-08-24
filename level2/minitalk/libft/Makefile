# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gde-jesu <gde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 14:50:00 by gde-jesu          #+#    #+#              #
#    Updated: 2022/08/15 10:44:42 by jsantann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a
SRCS =	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memcpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strchr.c \
			ft_strncmp.c \
			ft_strjoin.c \
			ft_substr.c \
			ft_strtrim.c \
			ft_split.c \
			ft_strdup.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_printf.c \
			ft_putchar.c \
			ft_strlen.c \
			ft_hexadecimal.c \
			ft_pointer.c \
			ft_putnbr.c \
			ft_putstr.c
CC	=	cc
CFLAGS	= -Wall -Wextra -Werror -c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBC = ar -rcs

$(NAME):
	$(CC) $(CFLAGS) -I. $(SRCS)
	$(LIBC) $(NAME) $(OBJS)

all:		$(NAME)

clean:
	$(RM) $(OBJS)
	
fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all fclean clean re
