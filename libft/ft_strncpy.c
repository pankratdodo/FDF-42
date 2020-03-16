/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:50:48 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/08 18:46:57 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (*src && n > 0)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
		n--;
	}
	while (n > 0)
	{
		*dest = 0;
		dest++;
		i++;
		n--;
	}
	return (dest - i);
}
