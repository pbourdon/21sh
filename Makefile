# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/04 13:03:16 by pbourdon          #+#    #+#              #
#    Updated: 2016/08/22 18:10:21 by pbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH = ./libft/
LIB = $(LIBPATH)/21sh.a

NAME = 21sh

CC = @gcc -ltermcap

CFLAGS =

LDFLAGS = -L $(LIBPATH) -lft

SRC =	main.c\
		ft_pipe.c\
		ft_redir.c\
		ft_touche.c\
		ft_check_arg.c\
		ft_check_arg3.c\
		ft_check_file.c\
		ft_choose.c\
		ft_error.c\
		ft_error_home.c\
		ft_exchange_element.c\
		ft_get_auto_path.c\
		ft_get_element.c\
		ft_get_options.c\
		ft_get_path.c\
		ft_get_size.c\
		ft_get_total_path.c\
		ft_give_path.c\
		ft_home.c\
		ft_last_dir.c\
		ft_prev.c\
		ft_run_cd.c\
		ft_run_echo.c\
		ft_run_exe.c\
		ft_run_setenv.c\
		ft_run_unsetenv.c\
		ft_show_prompt.c\
		fuck_the_norm.c\



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
