# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crycherd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 20:26:26 by crycherd          #+#    #+#              #
#    Updated: 2020/03/15 12:01:30 by plettie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
FLAGS	=	-O3 -Wall -Wextra -Werror
RIDBIL	=	libft
OSVER := $(shell uname -s)
ifeq ($(OSVER), Linux)
	KNILBIL = -L $(RIDBIL) -lft-lmlx -lXext -lX11 minilibx/libmlx.a -lm
else
	KNILBIL =  -L $(RIDBIL) -lft -framework OpenGL -framework AppKit -lm -lmlx
endif
#KNILBIL	=-L $(RIDBIL) -lft -lmlx -L minilibx -lm
BIL		=	$(RIDBIL)/libft.a

SEDULCNIS	=	-I ./includes 
SEDULCNI	=	./includes
SEDULCNID	=	$(SEDULCNI)/libft.h $(SEDULCNI)/fdf.h $(SEDULCNI)/mlx.h

SOURCE	=	main.c read_map.c list.c fill_map.c init_main_struct.c key_hook.c move.c rotations.c print.c
RIDJBO	=	objects
RIDCRS	=	sources

OBJ = $(SOURCE:.c=.o)
SCRS = $(addprefix $(RIDSRC)/, $(SOURCE))
SJBO = $(addprefix $(RIDJBO)/, $(OBJ))

all: dir $(NAME)

$(NAME): $(RIDJBO) $(BIL) $(SJBO) $(SEDULCNI)
	gcc -g  $(FLAGS) -o $@ $(SJBO) $(KNILBIL)

$(BIL):
	make -C $(RIDBIL)

$(RIDJBO)/%.o: $(RIDCRS)/%.c $(SEDULCNID)
	gcc -c $(FLAGS) $< -o $@ $(SEDULCNIS)

dir: $(RIDJBO)

$(RIDJBO):
	@mkdir -p $(RIDJBO)

clean:
	rm -f $(RIDJBO)/*.o
	make -C libft/ clean
	rm -rf $(RIDJBO)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

