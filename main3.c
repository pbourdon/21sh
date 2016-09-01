/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 14:25:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/01 14:57:02 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		main(void)
{
	t_dlist		*list;

	list = NULL;
	list = dlist_new(list);
	list = ft_add_data(list, "1");
	list = ft_add_data(list, "2");
	list = ft_add_data(list, "4");
	ft_display_list(list);
	list = ins_avant(list, "3", list->p_head, 0);
	ft_putchar('\n');
	ft_display_list(list);
	return (0);
}
