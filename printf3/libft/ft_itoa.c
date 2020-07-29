/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 03:25:19 by hurek             #+#    #+#             */
/*   Updated: 2020/05/08 06:35:48 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		len;

	len = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return ((int)len);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		minus;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	minus = ((n < 0) ? 1 : 0);
	n = ((minus == 1) ? n * (-1) : n);
	len = ft_intlen(n) + minus;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	if (minus == 1)
		str[0] = '-';
	return (str);
}
