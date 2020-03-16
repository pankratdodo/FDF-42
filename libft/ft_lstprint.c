/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:09:51 by crycherd          #+#    #+#             */
/*   Updated: 2019/05/24 18:16:55 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list **begin)
{
	t_list *a;

	a = *begin;
	while (a)
	{
		ft_putstr(a->content);
		ft_putchar('\n');
		a = a->next;
	}
}
