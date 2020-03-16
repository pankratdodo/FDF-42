/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 15:59:31 by plettie           #+#    #+#             */
/*   Updated: 2020/03/15 15:59:33 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lst	*lst_new(char *content)
{
	t_lst	*new;
	int		size;

	size = ft_strlen(content);
	if ((new = (t_lst *)malloc(sizeof(t_lst))))
	{
		if (content)
		{
			if ((new->data = malloc(size + 1)))
			{
				new->data = ft_memcpy(new->data, content, size + 1);
			}
			else
			{
				free(new);
				return (NULL);
			}
		}
		else
		{
			new->data = NULL;
		}
		new->next = NULL;
	}
	return (new);
}

void	lst_to_end(t_lst **head, t_lst *new)
{
	t_lst *start;

	if (head)
	{
		start = *head;
		if (start)
		{
			while (start->next)
				start = start->next;
			start->next = new;
		}
		else
		{
			*head = new;
		}
	}
}

void	lst_del(t_lst *head)
{
	if (head)
	{
		lst_del(head->next);
		free(head->data);
		free(head);
	}
}

char	**cnvrt_to_arr(t_lst *list)
{
	char	**result;
	int		i;
	int		n;

	i = 0;
	result = NULL;
	n = count_list(list) + 1;
	if ((result = (char **)malloc(sizeof(char *) * n)))
	{
		while (list)
		{
			result[i] = ft_strdup(list->data);
			list = list->next;
			i++;
		}
		result[i] = NULL;
	}
	return (result);
}

int		count_list(t_lst *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
