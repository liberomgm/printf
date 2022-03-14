/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:46:54 by hurek             #+#    #+#             */
/*   Updated: 2020/05/06 06:02:34 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*arr;
	const unsigned char	*source;
	size_t				i;

	arr = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (!n || (dest == src))
		return (dest);
	i = 0;
	while (i < n)
	{
		arr[i] = source[i];
		i++;
	}
	return (arr);
}
