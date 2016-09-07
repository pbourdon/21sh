/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 15:53:50 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/07 17:55:24 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_finish_command(t_dlist *list, t_dlist *histo)
{
	int		index;
	struct winsize sz;

	ft_putchar('\n');

	ft_display_list(list);
	ft_putchar('\n');
	if (ft_check_correct_entry(list) == 1)
		return (list);
	histo = ft_get_info_from_list(list, histo);
	ft_delete_list(&list);
	list = NULL;
	list = dlist_new(list);
	return (list);
}
