/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 02:34:32 by pbourdon          #+#    #+#             */
/*   Updated: 2016/09/05 17:18:50 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_dlist		*ft_paste(t_dlist *list, t_dlist *to_paste)
{
	char	*str;
	int		index;
	char	str2[2];
//	char	*test;

//	test = ft_get_str_from_list(list);
	index = 0;
	str = ft_get_str_from_list(to_paste);
	while (str[index] != '\0')
	{
		str2[0] = str[index];
		str2[1] = '\0';
		if (list->pos + 1 > list->length)
			list = ft_add_data(list, str2);
		else
			list = ins_avant(list, str2, list->p_head ,list->pos + 1);
		index++;
	}
	index = 0;
	ft_putstr(" \nlist->length : ");
	ft_putnbr(list->length);
	ft_putstr(" list->pos " );
	ft_putnbr(list->pos);
	ft_putchar('\n');
	ft_clear_line();
	ft_move_begin();
	ft_display_list(list);
	while (index < list->length - list->pos)
	{
		tputs(tgetstr("le", NULL), 0, ft_putchar2);
		index++;
	}
	return (list);
}
