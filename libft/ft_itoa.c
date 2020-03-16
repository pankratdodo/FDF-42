/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 00:50:36 by crycherd          #+#    #+#             */
/*   Updated: 2019/07/17 00:50:38 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int val)
{
	size_t res;

	res = 0;
	if (val == 0)
		return (1);
	if (val < 0)
		res++;
	while (val)
	{
		val /= 10;
		res++;
	}
	return (res);
}

static void		ft_toa(char *s, int val)
{
	size_t v;
	size_t i;

	v = val;
	if (val < 0)
		v = -val;
	i = 0;
	while (v)
	{
		s[i] = v % 10 + '0';
		v /= 10;
		i++;
	}
	if (val < 0)
	{
		s[i] = '-';
		i++;
	}
	s[i] = '\0';
}

char			*ft_itoa(int value)
{
	char	*result;
	char	a;
	size_t	v;
	size_t	i;

	v = ft_count(value);
	if ((result = (char *)malloc(sizeof(char) * (v + 1))))
	{
		if (value == 0)
			return (ft_strcpy(result, "0"));
		if (value == -2147483648)
			return (ft_strcpy(result, "-2147483648"));
		ft_toa(result, value);
		i = 0;
		while (i < v / 2)
		{
			a = result[i];
			result[i] = result[v - i - 1];
			result[v - i - 1] = a;
			i++;
		}
	}
	return (result);
}
