/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:47:48 by hurek             #+#    #+#             */
/*   Updated: 2020/05/01 23:05:41 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	i = 0;
	j = 0;
	cnt = 0;
	while (dest[i])
		i++;
	while (src[cnt])
		cnt++;
	if (i >= size)
		cnt += size;
	else
		cnt += i;
	while (src[j] && (i + 1 < size))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (cnt);
}
