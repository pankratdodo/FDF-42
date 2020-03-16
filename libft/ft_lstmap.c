/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:13:20 by crycherd          #+#    #+#             */
/*   Updated: 2019/05/24 17:57:53 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t size)
{
	if (content && size > 0)
		free(content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start;

	start = NULL;
	if (lst && f)
	{
		if ((new = f(lst)))
		{
			lst = lst->next;
			start = new;
			while (lst)
			{
				if ((new->next = f(lst)))
					new = new->next;
				else
				{
					ft_lstdel(&start, del);
					return (start);
				}
				lst = lst->next;
			}
		}
	}
	return (start);
}
