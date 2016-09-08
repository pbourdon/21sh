/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:08:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/08 15:03:58 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_get_user_input(void)
{
	char		*buffer;
	t_dlist		*list;
	t_dlist		*histo;
	t_dlist		*to_paste;

	histo = NULL;
	list = NULL;
	to_paste = NULL;
	to_paste = dlist_new(to_paste);
	histo = dlist_new(histo);
	buffer = malloc(sizeof(char) * 7);
	list = dlist_new(list);
	while (42)
	{
		buffer = ft_bzero(buffer, 7);
		read(0, buffer, 6);
		if (ft_detect_up(buffer) == 1 || ft_detect_down(buffer) == 1)
		{
			if (ft_get_size_from_list(list) > 0 && list->length > 0)
				ft_delete_list(&list);
			list = NULL;
			list = dlist_new(list);
		}
		if (ft_deal_input(buffer, list, histo, to_paste) == 1)
		{
			ft_putchar('\n');
			ft_display_list(list);
			ft_putchar('\n');
			ft_delete_list(&list);
			list = NULL;
			list = dlist_new(list);
		
			// execute the command
		}
	}
}
