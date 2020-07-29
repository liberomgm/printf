/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:46:45 by hurek             #+#    #+#             */
/*   Updated: 2020/05/06 05:58:06 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*arr1;
	const unsigned char	*arr2;

	arr1 = (unsigned char *)s1;
	arr2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		else
			i++;
	}
	return (arr1[i - 1] - arr2[i - 1]);
}
