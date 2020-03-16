/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:38:24 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/18 18:46:00 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*to;
	const char	*from;

	i = 0;
	from = (char *)src;
	to = (char *)dest;
	if ((dest - src) < (long)n && (dest - src) > 0)
	{
		while (n != 0)
		{
			to[n - 1] = from[n - 1];
			n--;
		}
	}
	else if (dest - src != 0)
		while (i < n)
		{
			to[i] = from[i];
			i++;
		}
	return (dest);
}
