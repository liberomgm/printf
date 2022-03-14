/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:59:11 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 21:05:33 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_di_zero(int input, int len, t_args *parsed)
{
	int zero_count;

	zero_count = 0;
	if (parsed->width > len)
		zero_count = parsed->width - len - (input < 0 ? 1 : 0);
	if (input < 0)
		parsed->len += write(1, "-", 1);
	if (zero_count > 0)
		ft_print_nchar('0', zero_count, parsed);
	ft_print_nbr(input, parsed);
}

void	ft_di_dot(int input, int len, t_args *parsed)
{
	int spaces_count;
	int zero_count;

	spaces_count = 0;
	zero_count = 0;
	if (parsed->prec > len)
		zero_count = parsed->prec - len;
	if (parsed->width > (len + zero_count + (input < 0 ? 1 : 0)))
		spaces_count = parsed->width - len - zero_count - (input < 0 ? 1 : 0);
	if (parsed->flags & FLG_MIN)
	{
		if (input < 0)
			ft_print_nchar('-', 1, parsed);
		ft_print_nchar('0', zero_count, parsed);
		ft_print_nbr(input, parsed);
		ft_print_nchar(' ', spaces_count, parsed);
	}
	else
	{
		ft_print_nchar(' ', spaces_count, parsed);
		if (input < 0)
			ft_print_nchar('-', 1, parsed);
		ft_print_nchar('0', zero_count, parsed);
		ft_print_nbr(input, parsed);
	}
}

void	ft_di_min(int input, int len, t_args *parsed)
{
	int space_count;

	space_count = parsed->width - len;
	if (input < 0)
		space_count--;
	if (input < 0)
		ft_print_nchar('-', 1, parsed);
	if (len != 0)
		ft_print_nbr(input, parsed);
	if (space_count > 0)
		ft_print_nchar(' ', space_count, parsed);
}

void	ft_di_width(int input, int len, t_args *parsed)
{
	int space_count;

	space_count = parsed->width - len;
	if (input < 0)
		space_count--;
	if (space_count > 0)
		ft_print_nchar(' ', space_count, parsed);
	if (input < 0)
		ft_print_nchar('-', 1, parsed);
	if (len != 0)
		ft_print_nbr(input, parsed);
}

int		ft_di_type(va_list *ap, t_args *parsed)
{
	int	input;
	int	input_len;

	input = va_arg(*ap, int);
	input_len = ft_number_len(input);
	if ((parsed->prec == 0) && (parsed->flags & FLG_DOT) && (input == 0))
		input_len = 0;
	if (!(parsed->flags & FLG_DOT) && (parsed->flags & FLG_ZERO))
		ft_di_zero(input, input_len, parsed);
	else if ((parsed->flags & FLG_DOT) && !(parsed->prec == 0 && input == 0))
		ft_di_dot(input, input_len, parsed);
	else if (parsed->flags & FLG_MIN)
		ft_di_min(input, input_len, parsed);
	else if (parsed->width)
		ft_di_width(input, input_len, parsed);
	else if (input < 0)
	{
		ft_print_nchar('-', 1, parsed);
		ft_print_nbr(input, parsed);
	}
	else
		(input_len == 0 ? 0 : ft_print_nbr(input, parsed));
	return (1);
}
