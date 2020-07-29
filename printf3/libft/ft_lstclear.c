/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 08:36:11 by hurek             #+#    #+#             */
/*   Updated: 2020/05/08 08:55:09 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (lst && del)
	{
		while (*lst)
		{
			buf = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = buf;
		}
	}
}
