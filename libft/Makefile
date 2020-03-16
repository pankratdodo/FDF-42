# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crycherd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 20:26:26 by crycherd          #+#    #+#              #
#    Updated: 2020/03/15 12:01:55 by plettie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -O3 -Wall -Wextra -Werror
SOURCE = putlongnbr get_next_line swap lstprint count_wrd lstremovis lstaddend lstmap lstiter lstadd lstdel lstdelone lstnew putnbr_fd putendl_fd putstr_fd putchar_fd putendl itoa strsplit strtrim strjoin strsub strnequ strequ strmapi strmap striteri striter strclr strdel strnew memdel memalloc putnbr putstr putchar memcmp memchr memccpy memcpy memmove bzero memset tolower toupper isprint isascii isalnum isdigit isalpha strncmp strnstr strlcat strncat strcat strncpy  strlen strdup strcpy strcmp strstr atoi strchr strrchr

all: $(NAME)

$(NAME): $(addprefix ft_,$(SOURCE:=.o))
	ar rc $(NAME) $^

ft_%.o: $(@:.o=.c)
	gcc -c $(FLAGS) $(@:.o=.c)

clean:
	rm -f $(addprefix ft_,$(SOURCE:=.o))

fclean: clean
	rm -f $(NAME)

re: fclean all

