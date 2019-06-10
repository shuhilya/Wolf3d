# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwynton- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/04 15:49:20 by bwynton-          #+#    #+#              #
#    Updated: 2019/04/09 17:38:41 by bwynton-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -c -I.
FILES = ft_strlen.c \
		ft_strdup.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strncat.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strdel.c \
		ft_strnew.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strncmp.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_isspace.c \
		ft_count_razryad.c \
		ft_wordcount.c \
		ft_wordcut.c \
		ft_strconvert.c

OUT = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OUT)
	ar rc $(NAME) $(OUT)
	ranlib $(NAME)

$(OUT): %.o:%.c
	gcc $(CFLAGS) $(FILES)

clean:
	rm -f $(OUT)

fclean: clean
	rm -f $(NAME)

re: fclean all
