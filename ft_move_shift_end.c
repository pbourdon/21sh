/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_shift_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:15:34 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 17:28:54 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_move_shift_end(t_dlist *list)
{
	int		pos;

	pos = list->pos;
	while (ft_strcmp(ft_get_element_from_list(list, pos), " ") != 0 && pos <
		list->length)
	{
		pos++;
		list = ft_right(list);
	}
	return (list);
}
