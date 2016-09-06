/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor_simple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/31 14:35:11 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/06 11:08:19 by pbourdon         ###   ########.fr       */
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
	struct winsize sz;

	ioctl(0, TIOCGWINSZ, &sz);
//	ft_putstr(" the list->pos % col = ");
//	ft_putnbr(list->pos % sz.ws_col);
	if (list->pos < list->length && list->pos % sz.ws_col == 0)
	{
		ft_move_begin();
		ft_down(list);
		list->pos = list->pos + 1;
	}
	else if (list->pos < list->length)
	{
		list->pos = list->pos + 1;
		res = tgetstr("nd", NULL);
		tputs(res, 0, ft_putchar2);
	}
//	ft_putstr(" the rest of list->pos % width  = ");
//	ft_putnbr(list->pos % sz.ws_col);
//	ft_putnbr(list->pos);
//	ft_putchar(' ');
//	ft_putnbr(list->length);
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
