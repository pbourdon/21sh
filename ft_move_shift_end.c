/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_shift_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:15:34 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 10:27:47 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_move_shift_end(t_dlist *list)
{
	int		pos;

	pos = list->pos + 1;
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\t") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\n") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\v") != 0 &&
			ft_strcmp(ft_get_element_from_list(list, pos), "\r") != 0 &&
			pos < list->length)
	{
		list = ft_right(list);
		pos = list->pos;
	}
	if (ft_strcmp(ft_get_element_from_list(list, pos + 1), " ") == 0)
	{
		while ((ft_strcmp(ft_get_element_from_list(list, pos), " ") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\t") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\n") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\v") == 0 ||
				ft_strcmp(ft_get_element_from_list(list, pos), "\r") == 0) &&
				pos < list->length)
		{
			list = ft_right(list);
			pos = list->pos;
		}
		list = ft_left(list);
		pos = list->pos;
	}
	return (list);
}
