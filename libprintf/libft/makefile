#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thalme <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 14:46:58 by thalme            #+#    #+#              #
#    Updated: 2020/03/05 15:36:34 by thalme           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
SRCS = 	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
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
		ft_swap.c \
		ft_abs.c \
		ft_wordcount.c \
		ft_strndup.c \
		ft_vswap.c \
		get_next_line.c \
		ft_itoa_base.c \
		ft_strcspn.c \
		ft_strnchr.c \
		ft_strspn.c \
		ft_superjoin.c \
		ft_pow.c \
		ft_u_itoa_base.c \
		ft_numlen_base.c \
		ft_numlen.c \
		ft_strrev.c \
		ft_ftoa.c \
		ft_str_toupper.c \
		ft_lstswap.c \
		ft_lstlen.c \
		ft_atolong.c

OBJECTS = $(SRCS:.c=.o)
FLAGS = -Werror -Wall -Wextra

$(NAME): all

all:
	@gcc -c $(FLAGS) $(SRCS)
	@ar cr $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

cleandup:
	@find . -type f -name '*~' -exec rm -rf {} \;
