/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:31:37 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 21:44:12 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_x_zero(unsigned int input, int len, t_args *parsed)
{
	int zero_count;
	int reg;

	reg = 0;
	if (parsed->type == 'X')
		reg = 1;
	zero_count = 0;
	if (parsed->width > len)
		zero_count = parsed->width - len;
	if (zero_count > 0)
		ft_print_nchar('0', zero_count, parsed);
	if (len != 0)
		ft_print_base(input, reg, 16, parsed);
}

void	ft_x_dot(unsigned int input, int len, t_args *parsed)
{
	int spaces_count;
	int zero_count;
	int reg;

	spaces_count = 0;
	zero_count = 0;
	reg = 0;
	if (parsed->type == 'X')
		reg = 1;
	if (parsed->prec > len)
		zero_count = parsed->prec - len;
	if (parsed->width > (len + zero_count))
		spaces_count = parsed->width - len - zero_count;
	if (parsed->flags & FLG_MIN)
	{
		ft_print_nchar('0', zero_count, parsed);
		(len != 0 ? ft_print_base(input, reg, 16, parsed) : 0);
		ft_print_nchar(' ', spaces_count, parsed);
	}
	else
	{
		ft_print_nchar(' ', spaces_count, parsed);
		ft_print_nchar('0', zero_count, parsed);
		(len != 0 ? ft_print_base(input, reg, 16, parsed) : 0);
	}
}

void	ft_x_min(unsigned int number, int len, int reg, t_args *parsed)
{
	int		i;
	char	space;

	space = ' ';
	i = 0;
	if (parsed->width <= len)
		ft_print_base(number, reg, 16, parsed);
	else
	{
		if (len != 0)
			ft_print_base(number, reg, 16, parsed);
		i += len;
		while (i < parsed->width)
		{
			parsed->len += write(1, &space, 1);
			i++;
		}
	}
}

void	ft_x_width(unsigned int number, int len, int reg, t_args *parsed)
{
	int		i;
	int		j;
	char	space;

	space = ' ';
	i = 0;
	j = 0;
	while (i < (parsed->width - len))
	{
		parsed->len += write(1, &space, 1);
		i++;
	}
	if (len != 0)
		ft_print_base(number, reg, 16, parsed);
}

int		ft_x_type(va_list *ap, t_args *parsed)
{
	unsigned int	input;
	int				reg;
	int				input_len;

	input = va_arg(*ap, unsigned int);
	reg = 0;
	if (parsed->type == 'X')
		reg = 1;
	input_len = ft_hex_len(input);
	if ((parsed->prec == 0) && (parsed->flags & FLG_DOT) && (input == 0))
		input_len = 0;
	if (!(parsed->flags & FLG_DOT) && (parsed->flags & FLG_ZERO))
		ft_x_zero(input, input_len, parsed);
	else if ((parsed->flags & FLG_DOT) && !(parsed->prec == 0 && input == 0))
		ft_x_dot(input, input_len, parsed);
	else if (parsed->flags & FLG_MIN)
		ft_x_min(input, input_len, reg, parsed);
	else if (parsed->width > input_len)
		ft_x_width(input, input_len, reg, parsed);
	else
		(input_len == 0 ? 0 : ft_print_base(input, reg, 16, parsed));
	return (1);
}
