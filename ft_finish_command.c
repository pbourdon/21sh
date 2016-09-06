/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:53:50 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 11:12:57 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_finish_command(t_dlist *list, t_dlist *histo)
{
	int		index;
	struct winsize sz;

	ioctl(0, TIOCGWINSZ, &sz);
	index = list->length / sz.ws_col;
	ft_putnbr(index);
	while (index > 0)
	{
		ft_putchar('\n');
		index--;
	}
	ft_putchar('\n');
	ft_display_list(list);
	ft_putchar('\n');
	histo = ft_get_info_from_list(list, histo);
//	ft_run_commands(list);
	// need to handle how to keep in historic this list
	// to make tests, i free/recreate an empty list, but I need to modify that
	ft_delete_list(&list);
	list = NULL;
	list = dlist_new(list);
	return (list);
}
