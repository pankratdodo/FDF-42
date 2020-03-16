/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:47:02 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/18 15:43:21 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	i;

	i = 1;
	result = 1;
	if (s1 && s2 && n > 0)
	{
		result = 0;
		while (*s1 == *s2 && *s1 && *s2 && i < n)
		{
			s1++;
			s2++;
			i++;
		}
		if (*s1 == *s2)
			result = 1;
	}
	return (result);
}
