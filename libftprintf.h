/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:48:13 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 21:52:23 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define FLG_EMPTY	0b00000000
# define FLG_MIN	0b00000001
# define FLG_ZERO	0b00000010
# define FLG_DOT	0b00000100
# define FLG_SPACE	0b00001000
# define FLG_HASH	0b00010000
# define FLG_PLUS	0b00100000

typedef struct		s_args
{
	unsigned char	flags;
	unsigned char	type;
	int				width;
	int				prec;
	int				len;
}					t_args;

int					ft_printf(const char *format, ...);
int					ft_processor(va_list *ap, t_args *parsed);
int					ft_char_type(va_list *ap, t_args	*parsed);
int					ft_di_type(va_list *ap, t_args	*parsed);
int					ft_string_type(va_list *ap, t_args	*parsed);
int					ft_pointer_type(va_list *ap, t_args	*parsed);
int					ft_unsigned_type(va_list *ap, t_args	*parsed);
int					ft_x_type(va_list *ap, t_args	*parsed);

int					ft_number_len(int number);
int					ft_hex_len(unsigned int number);
int					ft_unsigned_len(size_t number);
size_t				ft_customcmp(const char *set, char c);
void				ft_print_nbr(int n, t_args *parsed);
void				ft_print_nchar(char c, int number, t_args *parsed);
void				ft_print_base(size_t number, int reg, size_t base,
					t_args *parsed);
int					ft_parse_args(const char **format, va_list *ap,
					t_args *parsed);

#endif
