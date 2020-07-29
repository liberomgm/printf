/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hurek <hurek@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 09:07:41 by hurek             #+#    #+#             */
/*   Updated: 2020/05/08 10:37:09 by hurek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*buf;
	t_list	*last;

	if (!lst || !f)
		return (NULL);
	if (!(begin = ft_lstnew(f(lst->content))))
		return (NULL);
	buf = begin;
	lst = lst->next;
	while (lst)
	{
		if (!(last = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&begin, del);
			free(begin);
		}
		buf->next = last;
		buf = buf->next;
		last = NULL;
		lst = lst->next;
	}
	return (begin);
}
