/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:14:46 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:14:48 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void				sig_handler(int a)
{
	struct winsize	w;

	a = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	g_shell.shell_win_size = w.ws_col;
	update_cursor();
}

void				sig_handler_ctrl_c(int a)
{
	struct termios	term;

	a = 1;
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &term);
}
