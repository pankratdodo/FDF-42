/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:27:10 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/18 19:12:49 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	int					result;
	size_t				res;
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	res = 0;
	while (res < len && s1[res] == s2[res])
		res++;
	if (res == len || s1[res] == s2[res])
		result = 0;
	else
		result = s1[res] - s2[res];
	return (result);
}
