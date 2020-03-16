/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 20:56:17 by crycherd          #+#    #+#             */
/*   Updated: 2019/07/13 21:05:25 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlongnbr(long long nb)
{
	unsigned long long num;

	if (nb == -9223372036854775807)
	{
		ft_putstr("-9223372036854775807");
		return ;
	}
	if (nb < 0)
	{
		num = -nb;
		ft_putchar('-');
	}
	else
		num = nb;
	if (num / 10 > 0)
		ft_putlongnbr(num / 10);
	ft_putchar(num % 10 + '0');
}
