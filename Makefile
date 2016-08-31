# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:03:16 by pbourdon          #+#    #+#              #
#    Updated: 2016/08/31 17:44:24 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = ./libft/
LIB = $(LIBPATH)/21sh.a

NAME = 21sh

CC = @gcc -lncurses

CFLAGS =

LDFLAGS = -L $(LIBPATH) -lft

SRC =	main.c\
		ft_tc.c\
		ft_get_user_input.c\
		ft_detect_arrows.c\
		ft_move_cursor_simple.c\
		ft_clear_n_char.c\
		ft_deal_input.c\
		ft_detect_ctrl.c\
		ft_delete_on_shell.c\
		ft_add_element.c\



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
