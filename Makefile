# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 16:48:52 by dboire            #+#    #+#              #
#    Updated: 2024/05/14 15:07:58 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
CFLAGS	:= -Wextra -Wall -Werror -g -pthread
SRCS	:=	philo.c\
			parse.c\
			utils.c\
			init.c\
			routine.c\
			monitoring.c\
			ft_calloc.c\
			ft_bzero.c\
			ft_atoi.c\
			ft_putstr_fd.c\
			ft_isdigit.c\
			

OBJTS	:= $(SRCS:.c=.o)

all : 	$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling\n"

$(NAME): $(OBJTS) philo.h
	@$(CC) $(CFLAGS) $(OBJTS) -o $(NAME)

clean:
		@rm -rf $(OBJTS)

fclean: clean
		@rm -rf $(NAME)

re : clean all

.PHONY: all, clean, fclean, re