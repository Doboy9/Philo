# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dboire <dboire@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 16:48:52 by dboire            #+#    #+#              #
#    Updated: 2024/05/08 10:49:02 by dboire           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= philo
CFLAGS	:= -Wextra -Wall -Werror -g
SRCS	:=	philo.c\
			parse.c\
			utils.c\
			init.c\
			routine.c\
			monitoring.c\
			

OBJTS	:= $(SRCS:.c=.o)
LIBFT	:= libft
LIB	:= libft/libft.a

all : 	$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling"

$(NAME): $(OBJTS) philo.h
		@make -C $(LIBFT) -j4
	@$(CC) $(CFLAGS) $(OBJTS) $(PRINT) $(LIB) -o $(NAME)

clean:
		@rm -rf $(OBJTS)
		@rm -f $(LIBFT)/*.o

fclean: clean
		@rm -rf $(NAME)
		@rm -f $(LIBFT)/libft.a

re : clean all

.PHONY: all, clean, fclean, re