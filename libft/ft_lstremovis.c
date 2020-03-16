/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremovis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:03:14 by crycherd          #+#    #+#             */
/*   Updated: 2019/05/06 18:00:18 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremovis(t_list **alst, size_t this)
{
	t_list *remove;
	t_list *lucky;

	if (*alst)
	{
		lucky = *alst;
		remove = *alst;
		if (this == 0)
			*alst = lucky->next;
		while (this != 0)
		{
			if (!(remove->next))
				return ;
			lucky = remove;
			remove = remove->next;
			this--;
		}
		lucky->next = remove->next;
		free(remove->content);
		free(remove);
	}
}
