/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 21:15:29 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/17 21:28:50 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	if (s && (ft_strlen(s) - start) >= len)
	{
		if ((new = (char *)malloc(len + 1)))
		{
			while (i < len)
			{
				new[i] = s[start + i];
				i++;
			}
			new[i] = '\0';
		}
	}
	return (new);
}
