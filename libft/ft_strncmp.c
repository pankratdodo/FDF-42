/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:16:33 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/18 15:35:01 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int result;

	result = 0;
	if (len > 0)
	{
		while (*s1 == *s2 && *s1 && *s2 && len > 1)
		{
			s1++;
			s2++;
			len--;
		}
		if (*s1 == *s2)
			result = 0;
		else if (*s1 >= 0 && *s2 >= 0)
			result = *s1 - *s2;
		else
			result = *s2 - *s1;
	}
	return (result);
}
