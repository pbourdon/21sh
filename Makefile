# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:03:16 by pbourdon          #+#    #+#              #
#    Updated: 2016/08/18 18:06:55 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = ./libft/
LIB = $(LIBPATH)/minishell.a

NAME = minishell

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -L $(LIBPATH) -lft

SRC =


OBJ = $(SRC:.c=.o)

all: $(LIB) $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^

$(LIB):
	@make -C $(LIBPATH)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBPATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBPATH)

re: fclean all

.PHONY: all re clean flcean
