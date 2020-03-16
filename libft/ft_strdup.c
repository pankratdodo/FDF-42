/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:32:42 by crycherd          #+#    #+#             */
/*   Updated: 2019/04/08 17:31:19 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *src1;

	if ((src1 = (char *)malloc(ft_strlen(src) * sizeof(char) + 1)))
		return (ft_strcpy(src1, src));
	else
		return (src1);
}
