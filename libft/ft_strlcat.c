/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:55:01 by crycherd          #+#    #+#             */
/*   Updated: 2019/05/15 20:37:50 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t j;
	size_t sized;
	size_t sizes;

	j = 0;
	sized = ft_strlen(dest);
	sizes = ft_strlen(src);
	if (sized < n)
	{
		while (j < n - sized - 1 && src[j])
		{
			dest[sized + j] = src[j];
			j++;
		}
		dest[sized + j] = '\0';
		return (sized + sizes);
	}
	return (n + sizes);
}
