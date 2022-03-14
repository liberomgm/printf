/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:50:02 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 20:51:31 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_new_parse(t_args *parsed)
{
	parsed->flags = FLG_EMPTY;
	parsed->type = '\0';
	parsed->len = 0;
	parsed->prec = 0;
	parsed->width = 0;
}

void	ft_parse_flags(const char **str, t_args *parsed)
{
	while (**str)
	{
		if (**str == '-')
			parsed->flags |= FLG_MIN;
		else if (**str == '0')
			parsed->flags |= FLG_ZERO;
		else if (**str == ' ')
			parsed->flags |= FLG_SPACE;
		else if (**str == '#')
			parsed->flags |= FLG_HASH;
		else if (**str == '+')
			parsed->flags |= FLG_PLUS;
		else
			break ;
		(*str)++;
	}
}

void	ft_parse_width(const char **str, t_args *parsed, va_list *ap)
{
	if (**str == '*')
	{
		parsed->width = va_arg(*ap, int);
		(*str)++;
		if (parsed->width < 0)
		{
			parsed->flags = parsed->flags | FLG_MIN;
			if (parsed->flags & FLG_ZERO)
				parsed->flags &= ~FLG_ZERO;
			parsed->width *= -1;
		}
	}
	else
	{
		parsed->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
}

int		ft_parse_prec(const char **str, t_args *parsed, va_list *ap)
{
	parsed->flags = parsed->flags | FLG_DOT;
	(*str)++;
	if (ft_isalpha(**str))
		return (1);
	else if (**str == '*')
	{
		parsed->prec = va_arg(*ap, int);
		if (parsed->prec < 0)
			parsed->flags = parsed->flags & (~FLG_DOT);
		(*str)++;
	}
	else
	{
		parsed->prec = ft_atoi(*str);
		if (parsed->prec < 0)
		{
			parsed->flags = parsed->flags & (~FLG_DOT);
			return (0);
		}
		while (ft_isdigit(**str))
			(*str)++;
	}
	return (1);
}

int		ft_parse_args(const char **format, va_list *ap, t_args *parsed)
{
	ft_new_parse(parsed);
	ft_parse_flags(format, parsed);
	ft_parse_width(format, parsed, ap);
	if (**format == '.' && !(ft_parse_prec(format, parsed, ap)))
		return (0);
	if (!(ft_customcmp("cspdiuxX%", **format)))
		return (1);
	else
		parsed->type = **format;
	(*format)++;
	if (parsed->flags & FLG_MIN && parsed->flags & FLG_ZERO)
		parsed->flags &= ~FLG_ZERO;
	if (!ft_processor(ap, parsed))
		return (0);
	return (1);
}
