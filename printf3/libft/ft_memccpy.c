/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:46:18 by hurek             #+#    #+#             */
/*   Updated: 2020/05/08 00:06:40 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*arr;
	const unsigned char	*source;

	i = 0;
	arr = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (n > i)
	{
		arr[i] = source[i];
		if (arr[i] == (unsigned char)c)
			return (&arr[i + 1]);
		i++;
	}
	return (NULL);
}
