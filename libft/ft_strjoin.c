/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:08:55 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/17 21:26:46 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = NULL;
	if (s1 && s2 && (new = (char *)malloc(sizeof(char) \
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			new[i + j] = s2[j];
			j++;
		}
		new[i + j] = '\0';
	}
	return (new);
}
