/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:15:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:16:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int			term_init(t_term *term)
{
	if (!isatty(0))
		return (-1);
	if ((term->term_name = "xterm-256color") == NULL)
		return (-1);
	if (tgetent(NULL, term->term_name) < 1)
		return (-1);
	tcgetattr(0, &(term->term));
	g_shell.term_reset = *term;
	tcgetattr(0, &term->term_copy);
	term->term.c_lflag &= ~(ICANON);
	term->term.c_lflag &= ~(ECHO);
	tcsetattr(0, TCSANOW, &(term->term));
	return (1);
}

int			tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void		ft_reset_term(void)
{
	struct termios term;

	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tcsetattr(0, TCSANOW, &term);
}

void		go_home(void)
{
	struct termios s;

	tcgetattr(0, &(s));
	s.c_lflag &= ~(ICANON);
	s.c_lflag &= ~(ECHO);
	tcsetattr(0, TCSANOW, &(s));
}
