/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:33:31 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/17 21:27:24 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rtrn;
	size_t	i;

	rtrn = NULL;
	if (s)
	{
		i = 0;
		if ((rtrn = (char *)malloc(ft_strlen(s) + 1)))
		{
			while (s[i])
			{
				rtrn[i] = f(s[i]);
				i++;
			}
			rtrn[i] = '\0';
		}
	}
	return (rtrn);
}
