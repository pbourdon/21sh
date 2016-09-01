/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:17:49 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/01 16:19:36 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_move_end(t_dlist *list)
{
	int		pos;

	pos = list->length - list->pos;
	while (pos > 0)
	{
		list = ft_right(list);
		pos--;
	}
	return (list);
}
