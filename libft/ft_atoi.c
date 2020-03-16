/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:05:41 by crycherd          #+#    #+#             */
/*   Updated: 2019/07/17 00:49:46 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	long long int	k;
	int				n;

	k = 0;
	n = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'\
			|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		n = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
			return ((int)k * n);
		if (k > (k * 10 + *str - '0'))
			return ((-1 - n) / 2);
		k = k * 10 + *str - '0';
		str++;
	}
	return ((int)k * n);
}
