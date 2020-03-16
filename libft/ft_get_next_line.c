/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:18:16 by crycherd          #+#    #+#             */
/*   Updated: 2019/06/12 19:48:31 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*what_file(t_list **list, size_t fd)
{
	t_list *search;

	search = *list;
	while (search)
	{
		if (search->content_size == fd)
			return (search);
		search = search->next;
	}
	search = ft_lstnew("\0", 1);
	ft_lstadd(list, search);
	search->content_size = fd;
	return (search);
}

static void		lstremovis(t_list **alst, size_t this)
{
	t_list *remove;
	t_list *lucky;

	if (*alst)
	{
		lucky = *alst;
		remove = *alst;
		while (remove)
		{
			if (remove->content_size == this)
				break ;
			lucky = remove;
			remove = remove->next;
		}
		lucky->next = remove->next;
		free(remove->content);
		free(remove);
		remove = NULL;
	}
}

static void		*new_content(char *safe, char *buf, size_t size)
{
	char *str;

	str = ft_strnew(ft_strlen(safe) + size + 1);
	str = ft_strcat(str, safe);
	str = ft_strncat(str, buf, size);
	return (str);
}

static void		create_line(char **line, t_list *list, int *bit)
{
	char	*str;
	char	*safe;
	size_t	size;

	safe = list->content;
	if ((str = ft_strchr(list->content, '\n')))
	{
		size = str - safe;
		*line = (char *)ft_strnew(size + 1);
		*line = ft_memcpy(*line, safe, size);
		list->content = ft_strdup(str + 1);
		free(safe);
	}
	else if ((size = ft_strlen(list->content)) != 0)
	{
		*line = (char *)ft_strnew(size + 1);
		*line = ft_memcpy(*line, safe, size);
		list->content = ft_strnew(1);
		free(safe);
		*bit = size;
	}
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*safe_file;
	static t_list	*list;
	t_list			*file;
	int				size;

	if (fd < 0 || !(line) || (read(fd, buf, 0) < 0))
		return (-1);
	file = what_file(&list, fd);
	size = ft_strlen(file->content);
	while (!ft_strchr(file->content, '\n') && (size = read(fd, buf, BUFF_SIZE)))
	{
		safe_file = file->content;
		file->content = new_content(safe_file, buf, size);
		free(safe_file);
	}
	create_line(line, file, &size);
	if (size != 0)
		return (1);
	lstremovis(&list, fd);
	if (list == file && list->next == NULL)
		list = NULL;
	return (0);
}
