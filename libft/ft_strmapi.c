/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 19:17:24 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/17 21:25:45 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				rtrn[i] = f(i, s[i]);
				i++;
			}
			rtrn[i] = '\0';
		}
	}
	return (rtrn);
}
