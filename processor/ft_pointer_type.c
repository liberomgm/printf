/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:06:30 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 21:17:29 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_pointer_len(size_t number)
{
	int len;

	len = 2;
	while (number > 15)
	{
		number /= 16;
		len++;
	}
	len++;
	return (len);
}

void	ft_pointer_min(size_t number, int len, t_args *parsed)
{
	int	i;

	i = 0;
	if (parsed->flags & FLG_DOT && parsed->prec == 0 && !number)
	{
		parsed->len += write(1, "0x", 2);
		return ;
	}
	if (parsed->width <= len)
	{
		parsed->len += write(1, "0x", 2);
		ft_print_base(number, 0, 16, parsed);
	}
	else
	{
		parsed->len += write(1, "0x", 2);
		ft_print_base(number, 0, 16, parsed);
		i += len;
		while (i < parsed->width)
		{
			parsed->len += write(1, " ", 1);
			i++;
		}
	}
}

void	ft_pointer_width(size_t num, int len, t_args *parsed)
{
	int		i;
	int		j;
	char	space;

	space = ' ';
	i = 0;
	j = 0;
	while (i < (parsed->width - ((!num && parsed->flags & FLG_DOT) ? 2 : len)))
	{
		parsed->len += write(1, &space, 1);
		i++;
	}
	parsed->len += write(1, "0x", 2);
	if (parsed->flags & FLG_DOT && parsed->prec == 0 && !num)
		return ;
	ft_print_base(num, 0, 16, parsed);
}

int		ft_pointer_type(va_list *ap, t_args *parsed)
{
	size_t	ptr;
	int		input_len;

	ptr = va_arg(*ap, size_t);
	input_len = ft_pointer_len(ptr);
	if (parsed->flags & FLG_MIN)
		ft_pointer_min(ptr, input_len, parsed);
	else if (parsed->width > input_len)
		ft_pointer_width(ptr, input_len, parsed);
	else
	{
		if (parsed->flags & FLG_DOT && parsed->prec == 0 && !ptr)
		{
			parsed->len += write(1, "0x", 2);
			return (1);
		}
		parsed->len += write(1, "0x", 2);
		ft_print_base(ptr, 0, 16, parsed);
	}
	return (1);
}
