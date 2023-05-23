# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyeole <jihyeole@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 13:33:19 by jihyeole          #+#    #+#              #
#    Updated: 2023/03/10 18:37:52 by jihyeole         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isascii.c	\
	   ft_memmove.c	\
	   ft_strlen.c	\
	   ft_atoi.c \
	   ft_isdigit.c	\
	   ft_memset.c \
	   ft_strncmp.c \
	   ft_bzero.c \
	   ft_isprint.c	\
	   ft_strchr.c \
	   ft_strnstr.c \
	   ft_calloc.c \
	   ft_memchr.c \
	   ft_strdup.c \
	   ft_strrchr.c \
	   ft_isalnum.c	\
	   ft_memcmp.c \
	   ft_strlcat.c \
	   ft_tolower.c \
	   ft_isalpha.c	\
	   ft_memcpy.c \
	   ft_strlcpy.c	\
	   ft_toupper.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   strlen_without_nl.c \
	   ft_inset.c \
	   ft_printf.c \
	   print_decimal.c \
	   print_hex.c
OBJS = $(SRCS:.c=.o)
CC = cc 
CFLAGS = -Wall -Wextra -Werror
AR = ar 
ARFLAGS = rcs
BSRCS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 
BOBJS = $(BSRCS:.c=.o)

all : $(NAME)
clean : 
	rm -f $(OBJS) $(BOBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
bonus : $(NAME)($(OBJS) $(BOBJS))

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $<

.PHONY : all clean fclean re bonus
