/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:48:11 by crycherd          #+#    #+#             */
/*   Updated: 2019/07/13 20:58:42 by crycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFF_SIZE 100

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_toupper(int item);
int					ft_tolower(int item);
int					ft_isprint(int item);
int					ft_isascii(int item);
int					ft_isalnum(int item);
int					ft_isdigit(int item);
int					ft_isalpha(int item);
int					get_next_line(const int fd, char **line);
char				*ft_strtrim(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strsub(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putlongnbr(long long nb);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl(char const *str);
void				ft_putchar_fd(char c, int fd);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_itoa(int value);
void				ft_putnbr(int n);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strdel(char **as);
void				ft_strclr(char *s);
char				*ft_strnew(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
int					ft_memcmp(const void *str1, const void *str2, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strnstr(const char *str, const char *find, size_t len);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strstr(const char *str, const char *to_find);
int					ft_atoi(const char *str);
char				*ft_strchr(const char *p, int item);
char				*ft_strrchr(const char *p, int item);
char				**ft_strsplit(char const *s, char c);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstremovis(t_list **alst, size_t n);
size_t				ft_count_wrd(char const *s, char c);
void				ft_lstprint(t_list **begin);
void				ft_swap(void *a, void *b);
#endif
