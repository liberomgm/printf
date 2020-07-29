# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/11 21:08:04 by hurek             #+#    #+#              #
#    Updated: 2020/07/11 21:08:04 by hurek            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
LIBFTFOLDER = libft/
FLAGS = -Wall -Wextra -Werror
HEADER = libftprintf.h

SRCS = ft_printf.c \
		parser/ft_customcmp.c \
		parser/ft_parse_args.c \
		processor/ft_processor.c \
		processor/ft_char_type.c \
		processor/ft_string_type.c \
		processor/ft_pointer_type.c \
		processor/ft_print_funcs.c \
		processor/ft_support_funcs.c \
		processor/ft_di_type.c \
		processor/ft_unsigned_type.c \
		processor/ft_x_type.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re clean_libft clean_printf fclean_libft \
	fclean_printf main mainclean

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) -C $(LIBFTFOLDER)
		@cp $(LIBFTFOLDER)$(LIBFT) $(NAME)
		@ar rcs $(NAME) $(OBJS)
		@echo "\033[1;4;32mLibftprintf: Compiled\033[0m"

%.o: %.c 
		@gcc $(FLAGS) -I $(HEADER) -c $< -o $@

main:	re
		@gcc main.c libftprintf.a -I libftprintf.h $(FLAGS)

mainclean:
			@rm -f main.o
			@rm -f a.out

clean_printf:
		@rm -f $(OBJS)
		@echo "\033[1;4;33mlibftprintf: .o cleaned\n\033[0m"

fclean_printf: clean_printf
		@rm -rf $(NAME)
		@echo "\033[1;4;33mLibftprintf: full cleaned\n\033[0m"

clean_libft:
		@$(MAKE) -C $(LIBFTFOLDER) clean

fclean_libft:
		@$(MAKE) -C $(LIBFTFOLDER) fclean

clean: clean_printf clean_libft

fclean:	fclean_printf fclean_libft mainclean

re:		fclean all

