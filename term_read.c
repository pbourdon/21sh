/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 17:16:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 17:16:07 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

void	delete_shell_line(void)
{
	press_home_key();
	tputs(tgetstr("cd", NULL), 0, tputs_putchar);
}

void	replace_shell_line(char *str)
{
	delete_shell_line();
	ft_bzero(g_shell.shell_line, g_shell.size);
	g_shell.shell_line = ft_strcat(g_shell.shell_line, str);
	g_shell.length_line = ft_strlen(str);
	g_cursor.position_line = g_shell.length_line;
	ft_putstr(g_shell.shell_line);
	if (g_shell.length_line == g_shell.shell_win_size - 6)
	{
		ft_putstr(" ");
		tputs(tgetstr("le", NULL), 0, tputs_putchar);
	}
	update_cursor();
}

void	delete_shell_backslash_line(void)
{
	int i;

	i = 0;
	press_end_key();
	while (g_shell.backslash_index != 0)
	{
		press_left_key();
		if (ft_strchr(g_shell.shell_line, '\n'))
			update_cursor();
		g_shell.shell_line[g_cursor.position_line + 1] = '\0';
		g_shell.length_line--;
		i++;
	}
	g_shell.shell_line[g_cursor.position_line] = '\0';
	tputs(tgetstr("cd", NULL), 0, tputs_putchar);
}

void	replace_shell_backslash_line(char *str)
{
	int		i;
	char	*del;

	i = g_shell.last_backslash;
	delete_shell_backslash_line();
	ft_putstr(str);
	i = ft_strlen(str);
	while (i > 0)
	{
		g_shell.backslash_index++;
		g_shell.length_line++;
		g_cursor.position_line++;
		i--;
	}
	del = g_shell.shell_line;
	g_shell.shell_line = ft_strcat(g_shell.shell_line, str);
}
