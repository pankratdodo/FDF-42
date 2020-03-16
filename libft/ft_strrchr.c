/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:18:31 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/29 21:00:17 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *p, int item)
{
	int i;

	i = 0;
	if (p)
	{
		while (p[i])
			i++;
		while (i > 0 && p[i] != item)
			i--;
	}
	if (i == 0 && p[i] != item)
		return (NULL);
	return ((char *)p + i);
}
