/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:23:49 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 21:25:18 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_string_min(char *s, int len, t_args *parsed)
{
	int		i;
	char	space;

	space = ' ';
	i = 0;
	if (parsed->width <= len)
		while (i < len)
		{
			parsed->len += write(1, &s[i], 1);
			i++;
		}
	else
	{
		while (i < len)
		{
			parsed->len += write(1, &s[i], 1);
			i++;
		}
		while (i < parsed->width)
		{
			parsed->len += write(1, &space, 1);
			i++;
		}
	}
}

void	ft_string_width(char *s, int len, t_args *parsed)
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
	while (i < parsed->width)
	{
		parsed->len += write(1, &s[j], 1);
		j++;
		i++;
	}
}

int		ft_string_type(va_list *ap, t_args *parsed)
{
	char	*input;
	int		diff;
	int		input_len;

	input = va_arg(*ap, char *);
	if (!input)
		input = "(null)";
	input_len = ft_strlen(input);
	if ((parsed->prec < input_len) && (parsed->flags & FLG_DOT))
		input_len = parsed->prec;
	diff = parsed->width - input_len;
	if (parsed->flags & FLG_MIN)
		parsed->len += write(1, input, input_len);
	while (diff-- > 0)
		parsed->len += write(1, " ", 1);
	if (!(parsed->flags & FLG_MIN))
		parsed->len += write(1, input, input_len);
	return (1);
}
