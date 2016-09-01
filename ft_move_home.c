/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_home.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 16:21:58 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/01 16:29:12 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_move_home(t_dlist *list)
{
	int		pos;

	pos = list->pos;
	while (pos > 0)
	{
		list = ft_left(list);
		pos--;
	}
	return (list);
}
