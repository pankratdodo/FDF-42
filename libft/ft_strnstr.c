/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:16:54 by crycherd          #+#    #+#             */
/*   Updated: 2019/05/01 16:34:37 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while ((str[i + j] == find[j]) && find[j] && (i + j) < len)
			j++;
		if (find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	if ((str[0] == '\0' && find[0] == '\0') \
				|| (find[0] == '\0' && len == 0))
		return ((char *)&str[0]);
	return (0);
}
