/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_shift_home.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:37:51 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/01 16:47:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_move_shift_home(t_dlist *list)
{
	int		pos;

	pos = list->pos;
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") != 0 && pos > 0)
	{
		pos--;
		list = ft_left(list);
	}
	return (list);
}
