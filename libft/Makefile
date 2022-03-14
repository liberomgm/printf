# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 19:36:20 by hurek             #+#    #+#              #
#    Updated: 2020/07/17 23:02:27 by hurek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS :=			ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_toupper.c \
				ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
				ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c

BSRCS :=		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

NAME = libft.a
OBJ = $(SRCS:c=o)
BOBJ = $(BSRCS:c=o)
HEADERPATH = ./
HEADER = libft.h
CC = gcc
CF = -Wall -Wextra -Werror

all: $(NAME)

ifdef WITH_BONUS
OBJ_FILES = $(OBJ) $(BOBJ)
else
OBJ_FILES = $(OBJ)
endif

bonus:
	@$(MAKE) 'WITH_BONUS = true' all
	@echo "		 Bonus \033[32mCompiled\n"


$(NAME): $(OBJ_FILES)
	@ar rs $(NAME) $(OBJ_FILES)
	@echo "\033[1;4;32mLibft: Compiled\n\033[0m"

%.o: %.c $(HEADER)
	@$(CC) $< -c $(CF) -I$(HEADERPATH) -o $@

clean:
	@rm -rf $(OBJ) $(BOBJ)
	@echo "\033[1;4;33mLibft: .o cleaned\n\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;4;33mLibft: full cleaned\n\033[0m"

re: fclean all
