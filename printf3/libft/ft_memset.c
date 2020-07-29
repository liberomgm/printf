/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:47:17 by hurek             #+#    #+#             */
/*   Updated: 2020/05/06 06:02:51 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*arr;

	arr = (unsigned char *)s;
	while (n > 0)
	{
		*(arr++) = (unsigned char)c;
		n--;
	}
	return (s);
}
