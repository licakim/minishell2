# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunjki2 <hyunjki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/23 15:01:00 by hyunjki2          #+#    #+#              #
#    Updated: 2023/05/23 15:01:00 by hyunjki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRCS = main.c init.c utils.c env_utils1.c env_utils2.c make_heredoc.c \
	   error.c redirect.c expand_env.c pipe.c finalization.c check.c \
	   exec.c builtin.c
# SRCS = test.c init.c utils.c env_utils1.c env_utils2.c make_heredoc.c \
# 	   error.c redirect.c expand_env.c pipe.c finalization.c check.c \
# 	   exec.c builtin.c
OBJS = $(SRCS:.c=.o)
CC = CC
CFLAGS = -Wall -Wextra -Werror -I ~/.brew/opt/readline/include
LIBS = -Llibft -lft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft bonus
	$(CC) $(OBJS) $(LIBS) -o $(NAME) -lreadline -L ~/.brew/opt/readline/lib -g -fsanitize=address

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean : 
	make -C libft clean
	rm -f $(OBJS)

fclean : clean
	make -C libft fclean
	rm -f $(NAME)

re : fclean all 

.PHONY : all clean fclean re

