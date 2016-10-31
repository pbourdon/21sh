/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_letter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 16:50:43 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/12 16:51:05 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/shell.h"

int				ft_strlend(char **str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void			delete_last_backslash(void)
{
	g_shell.shell_line = del_from_arr(g_shell.shell_line, g_shell.length_line);
}

int				get_history_length(void)
{
	t_history	*history;
	int			i;

	history = g_shell.history;
	if (history->str)
		i = 1;
	else
		i = 0;
	while (history->next)
	{
		history = history->next;
		i++;
	}
	return (i);
}
