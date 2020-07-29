/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 18:51:23 by hurek             #+#    #+#             */
/*   Updated: 2020/07/21 15:35:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_args	parsed;
	int		res;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	res = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (!(ft_parse_args(&format, &ap, &parsed)))
				return (-1);
			res += parsed.len;
		}
		else
			res += write(1, format++, 1);
	}
	va_end(ap);
	return (res);
}
