/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_shift_home.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:37:51 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 10:30:42 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_move_shift_home(t_dlist *list)
{
	int		pos;

	pos = list->pos - 1;
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") == 0 && pos > 0)
	{
		list = ft_left(list);
		pos = list->pos;
	}
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") != 0 && pos > 0)
	{
		list = ft_left(list);
		pos = list->pos;
	}

	return (list);
}
