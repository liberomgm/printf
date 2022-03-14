/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:58:26 by hurek             #+#    #+#             */
/*   Updated: 2020/05/06 06:04:09 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_customcmp(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_customcmp(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_customcmp(set, s1[len - 1]))
		len--;
	return (ft_substr(s1, 0, len));
}
