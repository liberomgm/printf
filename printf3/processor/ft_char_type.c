/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:54:52 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 20:58:50 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	ft_char_min(unsigned char c, t_args *parsed)
{
	int				i;
	char			space;

	space = ' ';
	i = 0;
	i += write(1, &c, 1);
	while ((parsed->width > 1) && (i < parsed->width))
		(i += write(1, &space, 1));
	parsed->len += i;
	return (1);
}

static int	ft_char_width(unsigned char c, t_args *parsed)
{
	int				j;
	char			space;

	if (parsed->flags & FLG_ZERO && parsed->type == '%')
		space = '0';
	else
		space = ' ';
	j = 0;
	while ((parsed->width > 1) && (j < (parsed->width - 1)))
		(j += write(1, &space, 1));
	j += write(1, &c, 1);
	parsed->len += j;
	return (1);
}

int			ft_char_type(va_list *ap, t_args *parsed)
{
	unsigned char	c;
	int				bytes;

	bytes = 0;
	if (parsed->type == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(*ap, int);
	if (parsed->flags & (FLG_MIN))
		ft_char_min(c, parsed);
	else if (parsed->width >= 0)
		ft_char_width(c, parsed);
	return (1);
}
