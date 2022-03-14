/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:47:03 by hurek             #+#    #+#             */
/*   Updated: 2020/05/06 06:02:42 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*source;

	i = 0;
	arr = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			arr[i] = source[i];
			i++;
		}
	}
	else if (dest > src)
		while (i < n)
		{
			i++;
			arr[n - i] = source[n - i];
		}
	return (dest);
}
