/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor_simple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:35:11 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/03 16:34:32 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_down(t_dlist *list)
{
	char	*res;

	res = tgetstr("do", NULL);
	tputs(res, 0, ft_putchar2);
	return (list);
}

t_dlist		*ft_up(t_dlist *list)
{
	char	*res;

	res = tgetstr("up", NULL);
	tputs(res, 0, ft_putchar2);
	return (list);
}

t_dlist		*ft_right(t_dlist *list)
{
	char	*res;

	if (list->pos < list->length)
	{
		list->pos = list->pos + 1;
		res = tgetstr("nd", NULL);
		tputs(res, 0, ft_putchar2);
	}
	return (list);
}

t_dlist		*ft_left(t_dlist *list)
{
	char	*res;

	if (list->pos > 0)
	{
		list->pos = list->pos - 1;
		res = tgetstr("le", NULL);
		tputs(res, 0, ft_putchar2);
	}
	return (list);
}
