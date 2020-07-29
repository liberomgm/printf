/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 03:58:32 by hurek             #+#    #+#             */
/*   Updated: 2020/05/08 06:45:03 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_words(char const *s, char c)
{
	char	*str;
	size_t	words;

	words = 0;
	str = (char*)s;
	while (*str == c && *str != '\0')
		str++;
	while (*str != '\0')
	{
		while (*str != c && *str != '\0')
			str++;
		while (*str == c && *str != '\0')
			str++;
		words++;
	}
	return (words);
}

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		if (s[len] == c)
			break ;
		len++;
	}
	return (len);
}

static char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (str);
}

static void		*ft_memdel(char **ap, size_t i)
{
	while (i-- > 0)
		free(ap[i]);
	free(ap);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	wordlen;
	size_t	words;

	if (s == NULL)
		return (NULL);
	i = 0;
	words = ft_words(s, c);
	if (!(split = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	split[words] = NULL;
	while (i < words)
	{
		while (*s == c && *s != '\0')
			s++;
		wordlen = ft_wordlen(s, c);
		if (!(split[i] = ft_strnew(wordlen)))
			return (ft_memdel(split, i));
		ft_strlcpy(split[i], s, wordlen + 1);
		s += wordlen;
		i++;
	}
	return (split);
}
