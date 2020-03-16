/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 03:18:21 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/29 20:55:56 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *p, int item)
{
	if (p)
		while (*p && *p != item)
			p++;
	if (*p == '\0' && item == '\0')
		return ((char *)p);
	else if (*p == '\0')
		return (NULL);
	return ((char *)p);
}
