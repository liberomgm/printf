/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:19:23 by loscar             #+#    #+#             */
/*   Updated: 2020/07/29 16:54:16 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	take_name(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "cspdiuxX%";
	while (str[i] && c)
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_processor(va_list *ap, t_args *parsed)
{
	int			index_func;
	static int	(*actions[9])(va_list *, t_args *) = {&ft_char_type,
		&ft_string_type, &ft_pointer_type, &ft_di_type, &ft_di_type,
		&ft_unsigned_type, &ft_x_type, &ft_x_type, &ft_char_type};

	index_func = take_name(parsed->type);
	if (index_func < 0)
		return (0);
	if (!(actions[index_func](ap, parsed)))
		return (0);
	return (1);
}
