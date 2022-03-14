/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:26:09 by hurek             #+#    #+#             */
/*   Updated: 2020/07/17 21:43:10 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int		ft_number_len(int number)
{
	int				len;
	unsigned int	i;

	len = 0;
	i = 0;
	if (number < 0)
		i = -1 * number;
	else
		i = number;
	while (i > 9)
	{
		i /= 10;
		len++;
	}
	len++;
	return (len);
}

int		ft_unsigned_len(size_t number)
{
	int	len;

	len = 0;
	while (number > 9)
	{
		number /= 10;
		len++;
	}
	len++;
	return (len);
}

int		ft_hex_len(unsigned int number)
{
	int len;

	len = 0;
	while (number > 15)
	{
		number /= 16;
		len++;
	}
	len++;
	return (len);
}
