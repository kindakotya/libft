# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmayweat <gmayweat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 09:56:58 by gmayweat          #+#    #+#              #
#    Updated: 2021/04/30 03:16:32 by gmayweat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 						ft_memset.c\
							ft_bzero.c\
							ft_memcpy.c\
							ft_memccpy.c\
							ft_memmove.c\
							ft_strlen.c\
							ft_strlcpy.c\
							ft_strlcat.c\
							ft_strchr.c\
							ft_strrchr.c\
							ft_strnstr.c\
							ft_strncmp.c\
							ft_isalpha.c\
							ft_isdigit.c\
							ft_isalnum.c\
							ft_isascii.c\
							ft_isprint.c\
							ft_isspace.c\
							ft_toupper.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_tolower.c\
							ft_atoi.c\
							ft_calloc.c\
							ft_strdup.c\
							ft_substr.c\
							ft_strjoin.c\
							ft_strtrim.c\
							ft_itoa.c\
							ft_strmapi.c\
							ft_split.c\
							ft_putchar_fd.c\
							ft_putstr_fd.c\
							ft_putendl_fd.c\
							ft_putnbr_fd.c\
							ft_realloc.c\
							ft_min.c\
							ft_max.c\
							ft_min_arr.c\
							ft_max_arr.c\

OBJS = $(SRCS:.c=.o)

OBJSPATH = $(addprefix objs/, $(OBJS))

OBJDIR = objs

vpath %.o objs
vpath %.c srcs
vpath %.h ../includes

.Phony: all $(NAME) clean fclean re

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	ar rc $(NAME) $(OBJSPATH)
	ranlib $(NAME)

%.o: %.c libft.h
	clang -O3 -Wall -Wextra -Werror -I. -o $(patsubst srcs/%, objs/%, $(patsubst %.c, %.o, $<)) -c $<

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
