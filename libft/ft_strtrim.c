/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:24:21 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/17 21:29:18 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		st;
	int		ed;

	new = NULL;
	st = 0;
	if (s)
	{
		ed = ft_strlen(s) - 1;
		while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
			st++;
		while (ed > st && (s[ed] == ' ' || s[ed] == '\n' || s[ed] == '\t'))
			ed--;
		if ((new = (char *)malloc(sizeof(char) * (ed - st + 2))))
		{
			new[ed - st + 1] = '\0';
			while (ed - st >= 0)
			{
				new[ed - st] = s[ed];
				ed--;
			}
		}
	}
	return (new);
}
