/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:44:42 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/20 17:54:06 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*to;
	const char	*from;

	i = 0;
	to = (char *)dest;
	from = (char *)src;
	if (n)
	{
		while (i < n && from[i] != (char)c)
		{
			to[i] = from[i];
			i++;
		}
		if (i < n)
		{
			to[i] = from[i];
			return (dest + i + 1);
		}
	}
	return (NULL);
}
