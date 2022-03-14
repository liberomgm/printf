/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 07:59:44 by hurek             #+#    #+#             */
/*   Updated: 2020/05/08 08:13:24 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (*lst == NULL)
		(*lst) = new;
	else
	{
		buf = *lst;
		while (buf->next)
			buf = buf->next;
		buf->next = new;
	}
}
