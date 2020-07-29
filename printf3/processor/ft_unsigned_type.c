/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_type.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:28:00 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 21:30:10 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_un_zero(size_t input, int len, t_args *parsed)
{
	int	zero_count;

	zero_count = 0;
	if (parsed->width > len)
		zero_count = parsed->width - len;
	if (zero_count > 0)
		ft_print_nchar('0', zero_count, parsed);
	ft_print_base(input, 0, 10, parsed);
}

void	ft_un_dot(size_t input, int len, t_args *parsed)
{
	int	spaces_count;
	int	zero_count;

	spaces_count = 0;
	zero_count = 0;
	if (parsed->prec > len)
		zero_count = parsed->prec - len;
	if (parsed->width > (len + zero_count))
		spaces_count = parsed->width - len - zero_count;
	if (parsed->flags & FLG_MIN)
	{
		ft_print_nchar('0', zero_count, parsed);
		ft_print_base(input, 0, 10, parsed);
		ft_print_nchar(' ', spaces_count, parsed);
	}
	else
	{
		ft_print_nchar(' ', spaces_count, parsed);
		ft_print_nchar('0', zero_count, parsed);
		ft_print_base(input, 0, 10, parsed);
	}
}

void	ft_un_min(size_t input, int len, t_args *parsed)
{
	int space_count;

	space_count = parsed->width - len;
	if (len != 0)
		ft_print_base(input, 0, 10, parsed);
	if (space_count > 0)
		ft_print_nchar(' ', space_count, parsed);
}

void	ft_un_width(size_t input, int len, t_args *parsed)
{
	int space_count;

	space_count = parsed->width - len;
	if (space_count > 0)
		ft_print_nchar(' ', space_count, parsed);
	if (len != 0)
		ft_print_base(input, 0, 10, parsed);
}

int		ft_unsigned_type(va_list *ap, t_args *parsed)
{
	size_t	input;
	int		input_len;

	input = va_arg(*ap, unsigned int);
	input_len = ft_unsigned_len(input);
	if ((parsed->prec == 0) && (parsed->flags & FLG_DOT) && (input == 0))
		input_len = 0;
	if (!(parsed->flags & FLG_DOT) && (parsed->flags & FLG_ZERO))
		ft_un_zero(input, input_len, parsed);
	else if ((parsed->flags & FLG_DOT) && !(parsed->prec == 0 && input == 0))
		ft_un_dot(input, input_len, parsed);
	else if (parsed->flags & FLG_MIN)
		ft_un_min(input, input_len, parsed);
	else if (parsed->width)
		ft_un_width(input, input_len, parsed);
	else
		(input_len == 0 ? 0 : ft_print_base(input, 0, 10, parsed));
	return (1);
}
